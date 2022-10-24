global start
extern long_mode_start

section .text
bits 32
start:
	mov al, 0x58
	mov esp, stack_top

	call check_multiboot
	call check_cpuid
	call check_long_mode

	call setup_page_tables
	call enable_pagings

	lgdt [gdt64.pointer]
	jmp gdt64.code_segment:long_mode_start

	hlt

check_multiboot:
	cmp eax, 0x36d76289 ; sihirli değer 
	jne .no_multiboot
	ret
.no_multiboot:
	mov al, 'M'
	jmp error

check_cpuid:
	pushfd
	pop eax
	mov ecx, eax
	xor eax, 1 << 21
	push eax
	popfd
	pushfd
	pop eax
	push ecx
	popfd
	cmp eax, ecx 
	je .no_cpuid
	ret

.no_cpuid:
	mov al, 'C'
	jmp error

check_long_mode:
	mov eax, 0x80000000
	cpuid
	cmp eax, 0x80000001
	jb .no_long_mode

	mov eax, 0x80000001
	cpuid
	test edx, 1 << 29
	jz .no_long_mode
	jmp .no_long_mode
	ret

.no_long_mode: 
	mov al, 'L'
	jmp error   

setup_page_tables:
	mov eax, page_tables_l3
	or eax, 0b11 ; şuanki, yazılabilir
	mov [page_tables_l4], eax

	mov eax, page_tables_l2
	or eax, 0b11 ; şuanki, yazılabilir
	mov [page_tables_l3], eax

	mov ecx, 0 ;sayıcı?
.loop:
	mov eax, 0x200000 ; 2MB
	mul ecx
	or eax, 0b10000011
	mov [page_tables_l2 + ecx  * 8], eax

	inc ecx ;ecx++
	cmp ecx, 512 ; çeviri: "tüm tablonun eşlenip eşlenmediğini kontrol eder"
	jne .loop ;eğer devam etmezse yapacak galiba

	ret

enable_pagings:
	mov eax, page_tables_l4
	mov cr3, eax

	;PAE açık
	mov eax, cr4
	or eax, 1 << 5
	mov cr4, eax

	;long mode açık
	mov ecx, 0xC0000080 ; yeniden sihirli sayı
	rdmsr
	or eax, 1 << 8
	wrmsr
	
	;sayfalama açık ?
	mov eax, cr0
	or eax, 1 << 31
	mov cr0, eax

	ret

error:
	mov dword [0xb8000], 0x4c524c45
	mov dword [0xb8004], 0x4c3a4c52
	mov dword [0xb8008], 0x4c204c20 
	cmp al, 'M'
	je .M
	cmp al, 'C'
	je .C
	cmp al, 'L'
	je .L
	jne .ErrorOnError
	.M mov dword [0xb800c], 0x4c4d ; M yazar
	ret
	.C mov dword [0xb800c], 0x4c43 ; C yazar
	ret
	.L mov dword [0xb800c], 0x4c4c ; L yazar
	ret
	.ErrorOnError mov dword [0xb800c], 0x4c58 ; X yazar
	hlt

section .bss
align 4096
page_tables_l4:
	resb 4096
page_tables_l3:
	resb 4096
page_tables_l2:
	resb 4096
stack_bottom:
	resb 4096 * 4
stack_top:
	
section .rodata
gdt64:
	dq 0 ; sıfır girildi
.code_segment: equ $ - gdt64
	dq (1 << 43) | (1 << 44) | (1 << 47) | (1 << 53) ;kod bölümü
.pointer:
	dw $ - gdt64 - 1
	dq gdt64
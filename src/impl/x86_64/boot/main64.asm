global long_mode_start
extern kernel_main
; he burdasın 
section .text
bits 64 ;SONUNDA ; ye xd
long_mode_start:
	;MOV ALL ;bitdi (!)
	;tüm girilmiş data bölmünden boşlukları al (garip çevirdim)
	mov ax, 0
	mov ss, ax
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	;mov dword [0xb8000], 0x0f57 ;W
	;mov dword [0xb8002], 0x0f65 ;e
	;mov dword [0xb8004], 0x0f6c ;l
	;mov dword [0xb8006], 0x0f63 ;c
	;mov dword [0xb8008], 0x0f6f ;o
	;mov dword [0xb800a], 0x0f6d ;m
	;mov dword [0xb800c], 0x0f65 ;e
	;mov dword [0xb800e], 0x0f20 ; 
	;mov dword [0xb8010], 0x0f54 ;t
	;mov dword [0xb8012], 0x0f6f ;o
	;mov dword [0xb8014], 0x0f20 ; 
	;mov dword [0xb8016], 0xae42 ;B
	;mov dword [0xb8018], 0xa249 ;I
	;mov dword [0xb801a], 0xa24e ;N
	;mov dword [0xb801c], 0xa255 ;U
	;mov dword [0xb801e], 0xa258 ;X
	;mov dword [0xb8020], 0x0f21 ;!  

	call kernel_main
	hlt ;deneme vakti ; oldumu? ; hiç bir şey değişmedide adam şey diyo "şimdi c koduna geçiyoz şimdi çalışacak c ler" \ 1 dk lan hata vermiş derlemek bende ;main.asm deki sorunu yaptım basit "," hatasıymış; öylemi yazmışım ? \ HEE , eklememişim ok TYSM \beqle; 
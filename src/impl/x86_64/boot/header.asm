section .multiboot_header
header_start:
	dd 0xe85250d6												   ;multiboot2 şeysiymiş
	dd 0															;i386 koruma moduymuş
	dd header_end - header_start									;headerın uzunluğu
	dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start)) ;gagıl çeviri: "sağlama toplamı"

	;son etiket:
	dw 0
	dw 0
	dd 8
header_end:
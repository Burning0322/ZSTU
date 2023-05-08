TITLE Endianness Conversion           (EndiannessConversion.asm)

; Program Description: convert the elements in an array from big endian order to little endian order

INCLUDE Irvine32.inc
.data
array  WORD 0201h,0403h,0605h,0807h
;array  BYTE 02h
;array  DWORD 04030201h,08070605h,0C0B0A09h,100F0E0Dh
count DWORD ?

.code
main PROC
	mov esi,OFFSET array
	mov ecx,LENGTHOF array
L1:	
	mov count, ecx
	mov ebx, esi
	mov edi, esi
	add edi,TYPE array - 1
	mov ecx,(TYPE array + TYPE array MOD 2)/2
L2:
	mov  al, [esi]
	xchg al, [edi]
	mov  [esi], al
	inc esi
	dec edi
	Loop L2

	mov esi, ebx
	add esi, TYPE array
	mov ecx,count
	Loop L1

	mov esi,OFFSET array ; offset of variable
	mov ebx,TYPE array ; byte format
	mov ecx,LENGTHOF array ; counter
	call DumpMem
	exit
main ENDP
END main
TITLE Array Reversal           (ArrayReversal.asm)

; Program Description: reverse an array using mov with indirect operands

INCLUDE Irvine32.inc
.data
array  DWORD 1,2,3,4
;array  DWORD 1
;array  WORD 1,2,3,4
tmp DWORD ?

.code
main PROC
	mov esi,OFFSET array
	mov edi,OFFSET array + SIZEOF array - TYPE array
	mov ecx,(LENGTHOF array + LENGTHOF array MOD 2)/2
L1:	
	; exchange values, eax should be changed according to the type of the elements in array
	mov eax, [esi]
	xchg eax, [edi]
	mov [esi], eax
	; update offsets
	add esi, TYPE array
	sub edi, TYPE array
	Loop L1

	mov esi,OFFSET array ; offset of variable
	mov ebx,TYPE array ; byte format
	mov ecx,LENGTHOF array ; counter
	call DumpMem
	exit
main ENDP
END main
TITLE Array Reversal           (ArrayReversal.asm)

; Program Description: reverse an array using mov with indexed operands

INCLUDE Irvine32.inc
.data
array  WORD 1,2,3,4
;array  WORD 1
;array  DWORD 1,2,3,4
tmp DWORD ?

.code
main PROC
	mov esi,0
	mov edi,LENGTHOF array - 1
	mov ecx,(LENGTHOF array + LENGTHOF array MOD 2)/2
L1:	
	; exchange values, ax should be changed according to the type of the elements in array
	mov ax, array[esi * TYPE array]
	xchg ax, array[edi * TYPE array]
	mov array[esi * TYPE array], ax
	; update indexes
	inc esi
	dec edi
	Loop L1

	mov esi,OFFSET array ; offset of variable
	mov ebx,TYPE array ; byte format
	mov ecx,LENGTHOF array ; counter
	call DumpMem
	exit
main ENDP
END main
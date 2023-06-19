; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
array1 BYTE 1,2,3
array2 WORD	10,20,30
array3 DWORD 100,200,300

.code
DumpMemory PROC uses esi edi,
	pAddress:DWORD,
	dwLength:DWORD,
	dwType:DWORD

	mov esi,pAddress	;point esi to the start of the address
	mov edi,dwLength	;store the length to edi

	cmp dwType,TYPE BYTE	;COMPARE DATA TYPE
	je DumpByte
	cmp dwType,TYPE WORD	;COMPARE DATA TYPE
	je DumpWord
	cmp dwType,TYPE DWORD	;COMPARE DATA TYPE
	je DumpDWORD

DumpByte:
	mov ecx,edi	;store length to ecx
	shr	ecx,2	;divide length by 4
	jz DumpByteExit	;jumpzero,if the length is zero then exit

DumpByteLoop:
	mov al,BYTE PTR [esi]	;load the byte from memory
	call WriteHex	;display the byte's value
	inc esi	;increase esi to point to the next byte
	loop DumpByteLoop	;loop
	jmp DumpByteExit	;exit

DumpByteExit:
	ret

DumpWord:
	mov ecx,edi	;store the length in ecx
	shr ecx,1	;divide the length by 2
	jz DumpWordExit	;jumpzero,if length is zero then exit

DumpWordLoop:
	mov ax,WORD PTR [esi]	;load the word from memory
	call WriteHex	;display the word's value
	add esi,2	;increase esi to point to the next word
	loop DumpWordLoop	;loop
	jmp DumpWordExit	;exit

DumpWordExit:
	ret

DumpDword:
	mov ecx,edi	;store the length in ecx
	jz DumpDwordExit	;jumpzero if length is zero then jump 

DumpDwordLoop:
	mov eax,DWORD PTR [esi]	;load the dword form memory
	call WriteHex	;display the dword's value
	add esi,4	;increase the esi to point ot the next value
	loop DumpDwordLoop	;loop
	jmp DumpDwordExit	;exit

DumpDwordExit:
	ret

DumpMemory ENDP

main proc
	;call DumpMemory with BYTE array
	INVOKE DumpMemory,OFFSET array1,LENGTHOF array1,TYPE array1

	;call DumpMemory with WORD array
	INVOKE DumpMemory,OFFSET array2,LENGTHOF array2,TYPE array2

	;call DumpMemory with DWORD array
	INVOKE DumpMemory,OFFSET array3,LENGTHOF array3,TYPE array3

	exit
main endp
end main
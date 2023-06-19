TITLE Experiment 3-1        (experiment3-1.asm)

INCLUDE Irvine32.inc

IsPrime PROTO, integer:SDWORD

.data
prompt BYTE "Please input an integer: ",0
isPrimeString BYTE "The integer is a prime.",0Dh,0Ah,0
notPrimeString BYTE "The integer is not a prime.",0Dh,0Ah,0

.code
main PROC
L1:
	mov edx,OFFSET prompt
	call WriteString
	call ReadInt
	cmp eax,-1
	je QUIT
	INVOKE IsPrime,eax
	jz IS_PRIME
	mov edx,OFFSET notPrimeString
	call WriteString
	jmp L1
IS_PRIME:
	mov edx,OFFSET isPrimeString
	call WriteString
	jmp L1
QUIT:
	exit
main ENDP

;--------------------------------------------------------
IsPrime PROC USES ebx ebx edx,
	integer:SDWORD
;
; Receives a signed integer, set ZF if the interger is a prime,
; otherwise reset ZF.
; Receives: the input signed integer
; Returns: set ZF if the input interger is a prime,
; otherwise reset ZF
;--------------------------------------------------------
	cmp integer,1
	jle NOT_PRIMTE
	mov ebx,integer
	shr ebx,1
L1:
	cmp ebx,1
	je IS_PRIME
	mov eax,integer
	mov edx,0
	div ebx
	cmp edx,0
	jz NOT_PRIMTE
	dec ebx
	jmp L1

IS_PRIME:
	TEST EAX,0		;set ZF
	jmp QUIT
NOT_PRIMTE:
	or bl,1			;clear ZF
QUIT:
	ret
IsPrime ENDP

END main
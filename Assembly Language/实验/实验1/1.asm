; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword

.data
array DWORD 1,1,3,5,7,9,11,13,15,17		; Fibonacci number of DWORD's array

.data
val1 SBYTE 8
val2 SBYTE -128
val3 SBYTE 127

.code
main proc
mov al,val2	;move val2 value -128 to al,CF=0,OF=0
neg al	;let the value of al be negative al=128,CF=0,OF=1
dec al	;al=128-1,al=127,CF=0,OF=0

mov ah,val3	;move val3 with the value of 127 to ah,CF=0,OF=0
add ah,2	;add 2 to ah, ah=127+2, ah=129, OF=1,CF=1

neg al	;let the value of al to be negative,al=-127, CF=0,OF=0
add al,7	;move the value of 7 into al,al=-120,CF=0,OF=0
neg ah	;let the number of ah be negative, ah=-129,CF=0,OF=1
add al,ah	;add the value of al and ah,al=al+ah=-120-129=-249,CF=1,OF=1
mov bh,val1	;move the value of 8 to bh,bh=8,CF=0,OF=0
add al,bh	;add the value of al and bh,al=al+bh,al=-249+8=-241,CF=1,OF=1

	invoke ExitProcess,0
main endp
end main
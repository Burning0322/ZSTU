; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
DumpMem PROTO

.data
array DWORD 1,1,3,5,7,9,11,13,15,17		; Fibonacci number of DWORD's array

.code
main proc
    mov esi,OFFSET array	; offset of target array
    mov ebx,TYPE array		; byte format
    mov ecx,LENGTHOF array	; counter
    call DumpMem			; call DumpMem subroutine to display hexadecimal contents

    mov eax, 1				; initialize Fib(1) = 1
    mov ebx, 1				; initialize Fib(2) = 1

    mov edi, 10				; counter for loop 10 times
L1:
    add eax, ebx			; calculate the next Fibonacci number
    mov [esi + ecx*4], eax	; store the number in the array
    mov eax, ebx			; update Fib(n-1)
    mov ebx, [esi + ecx*4]	; update Fib(n-2)
    loop L1					; loop until counter reaches 0


	invoke ExitProcess,0
main endp
end main

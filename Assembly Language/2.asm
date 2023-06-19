; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

;.386
;.model flat,stdcall
;.stack 4096
;ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
  CaptionGreet BYTE "Test me", 0

  array1 DWORD 2,4,5,8
  array2 DWORD 1,0,4,6
  array3 DWORD 0,0,0,0

  toOut DB 64 dup(?)

.code

main PROC

    mov edi, OFFSET array1    ; Address of array1
    mov esi, OFFSET array2    ; Address of array2
    mov ebx, Offset array3    ; Address of array3

    mov eax, 0              ; Register with result

    mov ecx, LENGTHOF array1  ; Length of arrays

    L1:
        mov eax, [edi]      ; Copy current array1 element to eax
        add eax, [esi]      ; Add current array2 element to eax

        add edi, TYPE array1  ; Move pointer to the next array1 element
        add esi, TYPE array2  ; Move pointer to the next array2 element

        mov [ebx], eax      ; Move current eax value to current array3 element
        add ebx, TYPE array3  ; Move pointer to the next array3 element

        loop L1

    mov esi, OFFSET array3
    mov ecx, 4
    mov ebx, 4
    call DumpMem


    INVOKE ExitProcess,0

main ENDP

END main
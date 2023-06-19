; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

;.386
;.model flat,stdcall
;.stack 4096
;ExitProcess proto,dwExitCode:dword

INCLUDE Irvine32.inc

.data
time WORD  0001001000000111b	;02:16:07

.code
main PROC
	call Clrsrc
	mov ax,time
	call ShowFileTime
	mov ax,4ch
	int 21h
main ENDP
    INVOKE ExitProcess,0

;------------ShowFileTime PROC----------------------
;
;Receives a binary file time value in MS-DOS format
;and displays the time in hh:mm:ss format.
;Receives: AX = time in binary MS-DOS format
;Returns:nothing
;---------------------------------------------------

ShowFileTime PROC
PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX

    ; Extract hours
    MOV CX, 0001111100000000b
    AND AX, CX
    SHR AX, 11
    CALL WriteDec
    MOV DL, ':'
    CALL WriteChar

    ; Extract minutes
    MOV CX, 0000000011111000b
    AND AX, CX
    SHR AX, 5
    CALL WriteDec
    MOV DL, ':'
    CALL WriteChar

    ; Extract seconds
    MOV CX, 0000000000000111b
    AND AX, CX
    CALL WriteDec

    POP DX
    POP CX
    POP BX
    POP AX
    RET
ShowFileTime ENDP

ENDMAIN

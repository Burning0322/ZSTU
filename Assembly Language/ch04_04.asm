TITLE  Chapter 4 Exercise 4                (ch04_04.asm)

Comment !
Description: Write a program that uses addition and subtraction
to set and clear the Overflow flag. After each addition or
subtraction instruction, insert the call DumpRegs statement
to display the registers and flags. Using comments, explain how
(and why) the Overflow flag was affected by each instruction.
Optional: include an ADD instruction that sets both the Carry
and Overflow flags.

Last update: 05/02/2002
!

INCLUDE Irvine32.inc
.data
.code
main PROC

	mov  al,+127	; AL=7Fh
	add  al,1	; AL=80h, OF=1
	call DumpRegs

	sub  al,1	; AL=7Fh, OF=1
	call DumpRegs

	sub  al,1	; AL=7Eh, OF=0
	call DumpRegs

	mov  al,-128
	add  al,-1
	call DumpRegs	; AL=7Fh, OF=1

; Optional:
	mov  al,80h
	add  al,80h	; AL=0, CF=1, OF=1
	call DumpRegs

	exit
main ENDP
END main
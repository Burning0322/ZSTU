TITLE  Chapter 4 Exercise 1                          (ch04_01.asm)

Comment !
Description: Write a program that uses addition and subtraction to set and
clear the Carry flag. After each instruction, insert the call DumpRegs
statement to display the registers and flags. Using comments, explain how
(and why) the Carry flag was affected by each instruction.

Last update: 05/02/2002
!

INCLUDE Irvine32.inc
.data
.code
main PROC

	;adding 1 to 255 rolls AL over to zero:
	mov al,255
	add al,1	; AL=0, CF=1 (unsigned overflow)
	call DumpRegs

	;subtracting larger number from smaller:
	sub al,1	; AL=255, CF=1
	call DumpRegs

	;subtracting 1 from 255
	sub al,1	; AL=254, CF=0
	call DumpRegs

	exit
main ENDP
END main
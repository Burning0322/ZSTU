TITLE  Chapter 4 Exercise 3                (ch04_03.asm)

Comment !
Description:
Write a program that uses addition and subtraction to set and clear
the Zero and Sign flags. After each addition or subtraction
instruction, insert the call DumpRegs statement to display
the registers and flags. Using comments, explain how (and why)
the Zero and Sign flags were affected by each instruction.

Last update: 05/02/2002
!

INCLUDE Irvine32.inc
.data
.code
main PROC

	mov  al,1	; AL=1
	sub  al,1	; AL=0,  SF=0, ZF=1
	call DumpRegs

	sub  al,1	; AL=-1, SF=1, ZF=0
	call DumpRegs

	add  al,1	; AL=0,  SF=0, ZF=1
	call DumpRegs

	add  al,1	; AL=1,  SF=0, ZF=0
	call DumpRegs

	exit
main ENDP
END main
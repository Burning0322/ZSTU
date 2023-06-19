TITLE Chapter 4 Exercise 4               (ch04_04.asm)

Comment !
Description: Write a program that defines symbolic names
for several string literals (characters between quotes).
Use each symbolic name in a variable definition.

Last update: 05/02/2002
!

INCLUDE Irvine32.inc

sym1 TEXTEQU <"System failure">
sym2 TEXTEQU <"Press any key to continue...">
sym3 TEXTEQU <"Insufficient user training">
sym4 TEXTEQU <"Please re-start the system">

.data
msg1 BYTE sym1
msg2 BYTE sym2
msg3 BYTE sym3
msg4 BYTE sym4

.code
main PROC



	exit
main ENDP
END main
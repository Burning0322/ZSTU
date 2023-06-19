TITLE Chapter 3 Exercise 3               (ch03_03.asm)

Comment !
Description: Write a program that defines symbolic constants
for all of the days of the week. Create an array variable
that uses the symbols as initializers.

Last update: 05/02/2002
!

INCLUDE Irvine32.inc

Sunday    = 0
Monday    = 1
Tuesday   = 2
Wednesday = 3
Thursday  = 4
Friday    = 5
Saturday  = 6

.data
myDays BYTE Sunday, Monday, Tuesday, Wednesday,
	      Thursday, Friday, Saturday

.code
main PROC

	exit
main ENDP
END main
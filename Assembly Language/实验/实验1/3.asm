; AddTwo.asm - adds two 32-bit integers.
; Chapter 3 example

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
DumpMem PROTO

.data
sourceTable BYTE 1, 2, 3
		BYTE 4, 5, 6
		BYTE 7, 8, 9
		BYTE 10, 11, 12
tableSize = ($ - sourceTable)	;calculate the size of the sourcetable
targetTable BYTE tableSize DUP(?)	

.code
main proc
mov ah,sourceTable	;move the first value of array in sourceTable to ah
mov al,sourceTable+3	;move the fourth value of array in sourceTable to al
mov bh,sourceTable+6	;move the seventh value of array in sourceTable to bh
mov bl,sourceTable+9	;move the tenth value of array in sourceTable to bl
mov ch,sourceTable+1	;move the second value of array in sourceTable to ch
mov cl,sourceTable+4	;move the fifth value of array in sourceTableto cl
mov dh,sourceTable+7	;move the eight value of array in sourceTable to dh
mov dl,sourceTable+10	;move the eleventh value of array in sourceTable to dl
mov ah,sourceTable+2	;move the third value of array in sourceTable to ah
mov al,sourceTable+5	;move the sixth value of array in sourceTable to al
mov bh,sourceTable+8	;move the nine value of array in sourceTable to bh
mov bl,sourceTable+11	;move the twelve value of array in sourceTable to bl

call DumpMem

	invoke ExitProcess,0
main endp
end main

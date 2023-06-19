TITLE Experiment 3-2         (experiment3-2.asm)

INCLUDE Irvine32.inc

str_remove1 PROTO, remove_p:DWORD,count:DWORD
str_remove2 PROTO, string_p:DWORD,pos:DWORD,count:DWORD

.data
beforeRemove BYTE "Before remove: ",0
afterRemove BYTE "After remove:  ",0
target1 BYTE "abcxxxxdefghijklmop",0
target2 BYTE "abcxxxxdefghijklmop",0

.code
main PROC
	mov edx,OFFSET beforeRemove
	call WriteString
	mov edx,OFFSET target1
	call WriteString
	call Crlf
	INVOKE str_remove1, ADDR [target1+3], 4
	mov edx,OFFSET afterRemove
	call WriteString
	mov edx,OFFSET target1
	call WriteString
	call Crlf
	call Crlf

	mov edx,OFFSET beforeRemove
	call WriteString
	mov edx,OFFSET target2
	call WriteString
	call Crlf
	INVOKE str_remove2, ADDR target2, 4, 4
	mov edx,OFFSET afterRemove
	call WriteString
	mov edx,OFFSET target2
	call WriteString
	call Crlf
	call Crlf
	exit
main ENDP

;--------------------------------------------------------
str_remove1 PROC USES esi edi eax,
	remove_p:DWORD,count:DWORD
;
; Removes n characters from a string
; Receives: a pointer to the position in the string where 
; the characters are to be removed and an integer specifying 
; the number of characters to remove
; Returns: nothing
;--------------------------------------------------------
	mov edi,remove_p
	mov esi,edi
	add esi,count
L1:
	mov al,[esi]
	mov [edi],al
	cmp al,0
	je QUIT
	inc esi
	inc edi
	jmp L1
QUIT:
	ret
str_remove1 ENDP

;--------------------------------------------------------
str_remove2 PROC USES esi,
	string_p:DWORD,pos:DWORD,count:DWORD
;
; Removes n characters from a string
; Receives: a pointer to the first byte of the string, 
; an integer specifying the position in the string from 
; where the characters are to be removed and an integer 
; specifying the number of characters to remove
; Returns: nothing
;--------------------------------------------------------
	mov esi,string_p
	add esi,pos
	dec esi
	INVOKE str_remove1,esi,count
	ret
str_remove2 ENDP

END main
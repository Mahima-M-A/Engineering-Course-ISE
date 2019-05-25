assume cs:code,ds:data
data segment
	fname db "testf.txt" ;file which is to be opened,read and closed
	buff db 100 dup(0) ;buffer where the read data is stored into
	errmsg db 0ah,0dh,"File not found$"
	closmsg db 0ah,0dh,"File closed successfully$"
data ends

code segment
	start:
		mov ax,data
		mov ds,ax
		mov ah,3dh ;to open the file
		lea dx,fname ;the file to be opened
		mov al,0
		int 21h ;if successful, CF is cleared and ax is set to file handle
		jnc next ;jmp to next if CF is cleared or not
		lea dx,errmsg 
		mov ah,9 ;if not disp errmsg
		int 21h
		jmp finish
	next:
		mov bx,ax ;to set bx to file handle
		mov ah,3fh ;to read the file
		mov cx,100d ;number of char to be read
		lea dx,buff ;buffer for the read characters
		int 21h
		mov cx,100d
		lea si,buff
	repeat: ;to loop until the read char are printed
		mov dl,[si]
		mov ah,2
		int 21h
		inc si
		loop repeat

		mov ah,3eh ;to close the file
		int 21h
		lea dx,closmsg
		mov ah,9
		int 21h
	finish:
		mov ah,4ch ;to exit the program
		int 21h
code ends
end start

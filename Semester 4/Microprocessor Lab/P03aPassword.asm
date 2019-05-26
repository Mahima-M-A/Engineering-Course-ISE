assume cs:code,ds:data
disp macro msg ;macro to display the messages
	lea dx,msg
	mov ah,9
	int 21h
endm

data segment
	pwd1 db "lab123"
	len1 db len1-pwd1
	pwd2 db 10 dup(?) ;to store the entered password
	len2 db ?
	msg1 db 0ah,0dh,"Password matched$"
	msg2 db 0ah,0dh,"Passwords did not match$"
	msg3 db 0ah,0dh,"Enter password: $"
	msg4 db 0ah,0dh,"Exceeded 3 attempts, keyboard locked$"
data ends

code segment
	start:
		mov ax,data
		mov ds,ax
		mov es,ax
		mov bl,0 ;to hold the number of attempts made
	rpt:
		call readpwd
		call match
		inc bl
		cmp bl,3 ;to check if 3 attempts have been made or not
		jb rpt ;if not the continue reading i/p
		disp msg4 ;else display the corresponding msg
		mov ah,4ch ;and exit the program
		int 21h

	readpwd proc ;procedure to read the i/p
		disp msg3
		mov bh,0 ;to hold the length of the entered password
		lea si,pwd2 ;to point to the start position of pwd2
		again:
			mov ah,8 ;to i/p without an echo
			int 21h
			cmp al,0dh ;to cmp if enter key is pressed
			je next ;if so then jmp to next
			mov [si],al ;else store it in the pwd2 location
			inc si
			inc bh
			mov dl,'*'
			mov ah,2 ;to print '*' instead of the password characters are being entered
			int 21h
			jmp again ;continue taking the i/p
		next:
			mov len2,bh ;store the length of the entered password
		ret
	readpwd endp

	match proc ;to check if the entered password is right or not
		mov cl,len1
		cmp cl,len2 ;to check if the lengths of the entered password and the stored password is equal or not
		je matchstr ;if so then jmp to matchstr
		jmp mismatch ;else jmp to mismatch
		matchstr: ;to cmp both the passwords(entered and stored)
			lea si,pwd1
			lea di,pwd2
			cld ;clear the direction(to enable automatic increments of si and di)
			mov ch,0 ;ch = 0
			rep cmpsb ;to cmp char by char
			jnz mismatch ;jmp to mismatch if there is a mismatch
			disp msg1 ;else disp the corresponding success msg
			mov ah,4ch ;to exit the program
			int 21h
		mismatch:
			disp msg2 ;disp the failure msg
		ret
	match endp
code ends
end start

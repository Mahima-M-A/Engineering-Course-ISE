assume cs:code
code segment
	start:
		mov cx,100d
		mov bl,00
	next: ;to loop 100 times
		mov al,bl
		aam
		add ax,3030h ;to convert binary 16 bit data to ascii
		mov dl,ah
		mov ah,2 ;to print the msb of the 2 digit number
		push ax
		int 21h
		pop ax
		mov dl,al
		mov ah,2 ;to print the lsb of the 2 digit number
		int 21h
		mov dl,0dh ;0dh=carriage return
		mov ah,2 ;to print the next number at the same position as that of the previous one
		int 21h
		call delay ;to call the procedure
		inc bl ;inc the binary number
		loop next

		mov ah,4ch ;to exit the program
		int 21h
	delay proc ;procedure to generate a delay
		mov si,02fffh
		l2: mov di,0ffffh
		l1: dec di
		jnz l1
		dec si
		jnz l2
		ret
	delay endp
code ends
end start

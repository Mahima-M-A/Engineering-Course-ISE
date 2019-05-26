assume cs:code
code segment
	start:
		mov ah,2ch ;to get the system time (it returns CH=hours, CL=minutes)
		int 21h
		mov al,ch ;to copy the hours into al
		call hex_bcd
		call disp
		mov dl,':'
		mov ah,2 ;to print the delimitor ':'
		int 21h
		mov al,cl ;to copy the min into al
		call hex_bcd
		call disp

		mov ah,4ch ;to exit the program
		int 21h

	disp proc
		push cx ;to preserve the time
		mov ah,00h
		mov cx,4
		shl ax,cl
		shr al,cl
		add ax,3030h ;to convert binary to ascii
		push ax ;to preserve the ascii value
		mov dl,ah
		mov ah,2 ;to print the msb of the 2 digit number
		int 21h
		pop ax
		mov ah,2 ;to print the lsb of the 2 digit number
		mov dl,al
		int 21h
		pop cx ;to get back the preserved time
		ret
	disp endp

	hex_bcd proc
		push cx
		mov cl,al ;to copy the al value
		mov ch,0
		mov al,0
		next: ;to loop cl times
			add al,1 ;inc al
			daa ;decimal adjust al after addition
			loop next
		stop:
			pop cx
		ret
	hex_bcd endp
code ends
end start

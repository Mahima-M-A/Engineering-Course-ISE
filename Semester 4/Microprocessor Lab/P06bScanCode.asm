assume cs:code,ds:data
data segment
	pa equ 20a0h ;address of port A
	pb equ 20a1h ;address of port B
	pc equ 20a2h ;address of port C
	cr equ 20a3h ;address of control register
	rowval db ? ;to store row value
	colval db ? ;to store column value
	scode db ? ;to store the scan code
data ends

code segment
	start:
		mov ax,data
		mov ds,ax
		mov dx,cr
		mov al,90h ;control word to set port A: input, port C: output
		out dx,al ;to send the contol word to cr
	try_again: ;to loop until a key is pressed 
		mov bl,01h ;first row of the keypad
		mov bh,03h ;there are 3 rows of keys(8 keys in each rows)
		mov cl,00h ;to point to each key(scan code value)
		mov ah,01h ;first row of the keypad
	next_row: ;to scan each row of the keypad(loop bh times)
		mov dx,pc
		mov al,bl
		out dx,al
		mov dx,pa
		in al,dx ;to take in the i/p
		cmp al,00h ;to check if any key in that row is pressed
		jne calculate ;jmp to calculate if yes(i.e, if al!=0)
		add cl,08h ;else inc cl by 8(to point to the first key in the next row) 
		inc ah ;next row
		shl bl,01 ;next row
		dec bh
		jnz next_row
		jmp try_again
	calculate:
		mov rowval,ah ;copy the row value
		mov ah,00h ;to store the col value 
	rot_again: ;rotate until the key that is pressed is found
		ror al,01
		jc next
		inc ah
		inc cl
		jmp rot_again
	next:
		mov scode,cl ;copy the scan code value
		mov colval,ah ;copy the col value
		mov al,cl ;copy the scan code
		call disp ;call the procedure

		mov ah,4ch ;to exit the program 
		int 21h
	disp proc ;procedure to display the scan code
		mov bl,al
		mov cl,4
		shr al,cl
		cmp al,09
		jle add_30
		add al,07
    add_30:
      add al,30h
      mov dl,al
      mov ah,02
      int 21h
      mov al,bl
      and al,0fh
      cmp al,09
      jle add_30_1
      add al,07
    add_30_1:
      add al,30h
      mov dl,al
      mov ah,02
      int 21h
		ret
	disp endp
code ends
end start

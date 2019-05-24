disp_msg macro msg ;macro to display messages
	lea dx,msg
	mov ah,09
	int 21h
endm

disp macro ;macro to display operands and operators
	lea bx,table1 ;offset of look-up table
	xlat
	mov dl,al
	mov ah,02
	int 21h
endm

init macro word ;macro to send the control word to cr
	mov al,word ;copy the control word
	mov dx,20a3h ;address of cr
	out dx,al
endm

assume cs:code,ds:data
data segment
	cw db 90h ;control word to set port A: input, port C: output
	ops db 3 dup(?) ;to store the 2 operands and 1 operator
	table1 db '0123456789.+-' ;look-up table
	msg1 db "Not supported$"
data ends

code segment
	start:
		mov ax,data
		mov ds,ax

		init cw ;call macro init and pass the control word as its parameter

		call readkp ;to read first operand
		call delay
		mov ops,al ;copy it into location ops
		disp ;display it

		call readkp ;to read the operator
		call delay
		mov ops+1,al ;copy it into location ops+1
		disp ;display it

		call readkp ;to read second operand
		call delay
		mov ops+2,al ;copy it into location ops+2
		disp ;display it

		mov dl,'=' 
		mov ah,02 ;to display '='
		int 21h

		cmp ops+1,0bh ;compare the entered operator with '+'(scan code of '+' is 0bh)
		jne next ;jmp to next if it isn't '+'
		mov al,ops ;else copy first operand into al
		add al,ops+2 ;add it with second operand
		daa ;decimal adjust al after addition

		mov cl,4
		mov ah,00
		shl ax,cl
		shr al,cl
		add ax,3030h ;to convert binary to ascii
		mov dl,ah
		mov ah,2 ;to display the msb of the 2 digit number
		push ax
		int 21h
		pop ax
		mov dl,al
		mov ah,2 ;to display the lsb of the 2 digit number
		int 21h
		jmp finish ;jmp to exit the program
	next:
		mov al,ops+1 ;copy the entered operator into al 
		cmp al,0ch ;compare it with '-'(scan code of '-' is 0ch)
		jne disp_err ;if they are not equal jmp to display the error msg(because this program handles only addition and subtraction)
		mov al,ops ;else copy first operand into al
		sub al,ops+2 ;subtract the second operand from it
		jnc no_need ;if there is no carry generated(i.e., the diff is +ve) jmp to no_need
		neg al ;else find its 2's complement

		mov dl,'-'
		mov ah,2 ;display -ve sign
		push ax
		int 21h
		pop ax
	no_need:
		add al,30h ;convert binary to ascii
		mov dl,al
		mov ah,2 ;display the diff
		int 21h
		jmp finish ;jmp to exit the program
	disp_err:
		disp_msg msg1 ;call macro to display the error msg(passing it as its parameter)
	finish:
		mov ah,4ch ;to exit the program
		int 21h

	readkp proc ;procedure to take in the input
		try_again:
			mov bl,01
			mov bh,03
			mov cl,00
		next_row:
			mov al,bl
			mov dx,20a2h ;address of port C
			out dx,al
			mov dx,20a0h ;address of port A
			in al,dx
			cmp al,00h
			jne scode
			add cl,08h
			rol bl,1
			dec bh
			jnz next_row
			jmp try_again
		scode:
			ror al,1
			jc return
			inc cl
			jmp scode
		return:
			mov al,cl
		ret
	readkp endp

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

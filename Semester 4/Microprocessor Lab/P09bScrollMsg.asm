assume cs:code,ds:data

data segment
	pa equ 20a0h ;address of port A
	pb equ 20a1h ;address of port B
	pc equ 20a2h ;address of port C
	cr equ 20a3h ;address of control register
	msg db 0ffh,71h,9fh,0f5h,61h,0ffh,91h,61h,0f5h,61h,0ffh,91h,61h,0e3h,31h ;sequences for F,I,r,E, ,H,E,r,E, ,H,E,L,P
data segment

code segment
  start:
    mov ax,data
    mov ds,ax
    mov dx,cr
    mov al,80h ;control word to set all the ports as output ports
    out dx,al ;to send the control word to cr
  rpt: ;for infinite looping of the statement 'FIrE HErE HELP'
    mov cx,15d
    lea si,msg
  next: ;loop for the 15 characters of msg
    mov al,[si]
    call disp ;calls disp procedure
    call delay ;calls delay procedure(to give the scrolling view) 
    inc si
    loop next
    ;to stop displaying if any key is pressed
    mov ah,06h
    mov dl,0ffh
    int 21h
    jz rpt
    
    mov ah,4ch ;to exit the program
    int 21h
    
  disp proc ;procedure to display each character
    push cx ;to preserve the present cx value
    mov cx,08h
    next_bit: ;loop for the 8 segments of each character
      mov dx,pb
      out dx,al ;to output each segment
      push ax ;to preserve the present ax value
      ;to generate a negative edge clock pulse to activate the shift register
      mov dx,pc
      mov al,0ffh
      out dx,al
      mov al,00h
      out dx,al
      
      pop ax ;to get back the previous al value
      ror al,1 
      loop next_bit
    pop cx ;to get back the previous cx value
    ret
  disp endp
  
  delay proc ;procedure to generate a delay
    mov bx,02fffh
    l2: mov di,0ffffh
    l1: dec di
    jnz l1
    dec bx
    jnz l2
    ret
  delay endp
  
code ends
end start

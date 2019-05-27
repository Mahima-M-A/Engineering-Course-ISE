assume cs:code,ds:data

data segment
	pa equ 20a0h ;address of port A
	pb equ 20a1h ;address of port B
	pc equ 20a2h ;address of port C
	cr equ 20a3h ;address of control register
data ends

code segment
  start:
    mov ax,data
    mov ds,ax
    mov dx,cr
    mov al,82h ;control word to set port A: output, port B: input
    out dx,al ;to send control word to cr
    mov dx,pa
    mov al,00h ;to switch on the led corresponding to ground floor
    out dx,al
    mov al,0f0h
    out dx,al
    mov dx,pb
  scan_again: ;to scan the input until any of the buttons are pressed(for the first time)
    in al,dx
    and al,0fh ;mask the upper nibble of the input
    cmp al,0fh ;compare the lower nibble of i/p with 0fh
    je scan_again ;scan_again if they are equal(because none of the buttons are pressed)
    mov cl,01 ;else initialize count=1(i.e.,lift is in the ground floor)
  rot: ;rotate the lower nibble of i/p to know the destination floor
    ror al,1
    jc next ;if there is a carry
    jmp start_mov ;if there is no carry
  next:
    add cl,03 ;inc count by 3(because it takes 3 steps for the lift to reach the next floor)
    jmp rot
  start_mov:
    mov dx,pa
    mov al,0f0h ;initialize al
  next_led: ;loop until the lift reaches the destination(moves up)
    out dx,al 
    call delay
    inc al ;to store the number of steps it takes for the lift to reach the destination
    dec cl
    jnz next_led
    
    call delay
    call delay
    
    dec al 
    and al,0fh ;to get the number of steps required to get back to the ground floor by masking the upper nibble 
  come_down: ;loop until the lift reaches the ground floor(moves down)
    out dx,al
    call delay
    dec al
    cmp al,00h ;to check if it has reached the ground floor
    jge come_down ;continue looping if it hasn't
    
    mov ah,4ch ;to exit the program
    int 21h
    
  delay proc ;to generate a delay
    mov si,02fffh
    l2: mov di,0ffffh
    l1: dec di
    jnz l2
    dec si
    jnz l1
    ret
  delay endp
  
code ends
end start

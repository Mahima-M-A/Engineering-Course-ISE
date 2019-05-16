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
    mov cx,100d ;to count 100 numbers
    mov dx,pa ;to copy address of port A
    mov al,00h ;al = 0
    
  next: ;up counting
    out dx,al ;to move 8 bit data to port A
    call delay ;calls delay procedure
    add al,01 ;increment al's value by 1
    daa ;decimal adjust after addition
    loop next ;loop 100 times
    
    mov cx,99d ;to count 100 numbers
    
  next1: ;down counting
    sub al,01 ;to decrement al's value by 1
    das ;decimal adjust after subtraction
    out dx,al
    call delay
    loop next1
    
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
  delay endp ;end of procedure
code ends
end start

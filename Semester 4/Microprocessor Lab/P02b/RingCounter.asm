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
    mov al,82h ;control word to set port A: output, port B:input
    out dx,al ;to send control word to cr
    mov al,01 ;initialize al to 1
  rpt:
    mov dx,pa ;copy port A's address into dx
    out dx,al ;to send the 8 bit data to port A
    call delay ;calls a procedure
    ror al,1 ;to rotate the 8 bit data
    push ax 
    ;to stop the ring counter(if any key is pressed)
    mov ah,6h ;keyboard input
    mov dl,0ffh ;does not wait for the input(ZF=0, if any key is pressed)
    int 21h
    pop ax
    jz rpt ;if no key is pressed then continue looping
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

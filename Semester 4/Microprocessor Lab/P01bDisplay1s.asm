assume cs:code,ds:data
data segment
  pa equ 20a0h ;address of port A
  pb equ 20a1h ;address of port B
  pc equ 20a2h ;address of port C
  cr equ 20a3h ;address of control register
  msg db "No. of 1's present are: "
  one db ?,"$" ;holds the number of 1's
data ends
code segment
  start:
    mov ax,data
    mov ds,ax
    mov dx,cr
    mov al,82h ;control word to set port A: output, port B: input
    out dx,al ;to send control word to cr
    mov dx,pb ;to copy port B's address
    in al,dx ;to read input
    mov cx,8 ;to loop 8 times(8 bits)
    mov ah,0 ;ah = 0
  rotate:
    ror al,1 ;to rotate the bits once to the right to store the rightmost bit as carry
    jnc next ;jump if carry is 0
    inc ah ;else increment ah
  next:
    loop rotate ;loops 8 times
    mov bl,ah ;to copy ah value into bl
    add ah,30h ;to convert binary into ascii
    mov one,ah ;to copy ascii value into one
    lea dx,msg ;to point to msg
    mov ah,09h ;to display msg
    int 21h
    mov dx,pa ;to copy address of port A
    out dx,al ;to move 8 bit data to port A
    mov ah,4ch ;to exit the program 
    int 21h
code ends
end start

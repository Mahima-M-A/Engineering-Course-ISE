assume cs:code,ds:data
data segment
    arr db 10h,20h,30h,40h,50h  ;sorted array 
    n db n-arr  ;contains array size
    key db 20h  ;key to be found
    msg1 db "Search unsuccessful$"
    msg2 db "Key found at position: "
    pos db ?,"$" ;contains position of the key if found
data ends
code segment
start:
    mov ax,data
    mov ds,ax
    mov al,0  ;contains first position of array
    mov dl,n  ;contains array size
    dec dl   ;contains last position of array
again:
    cmp al,dl  ;compares first and last position
    ja failed  ;if there are no elements in the array
    mov cl,al  ;store a copy of al value
    add al,dl  ;add first and last positions of the array
    shr al,1   ;reduces al to half its value
    mov ah,00h 
    mov si,ax  ;stores ax value(mid position) into si
    mov bl,[si] ;stores the contents of si in bl
    cmp bl,key ;compares mid value with key to be found
    jae loc1 ;if bl is greater than or equal to the key value
    inc al  ;else increment mid position because key value is greater than mid value 
    jmp again 
loc1:
    je success ;if mid value is equal to key value
    dec al ;else decrement mid position as key value is less than mid value
    mov dl,al ;store mid position -1 in dl
    mov al,cl ;copy the stored cl value in al
    jmp again
failed:
    lea dx,msg1 ;load the msg1 offset address in dx
    jmp display
success:
    inc al ;increment the position where key is found
    add al,30h ;convert binary to ascii value
    mov pos,al
    lea dx,msg2 ;load the msg2 offset address in dx
display:
    mov ah,09h ;to print the string msg
    int 21h
    mov ah,4ch ;to exit the program
    int 21h
code ends
end start

assume cs:code,ds:data
data segment
    n db 5 ;whose factorial is to be found
    res db ?
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        mov al,n ;contains n
        call fact ;calls procedure fact
        mov ah,4ch
        int 21h ;to exit program
    fact proc
        cmp al,00 ;if n is 0
        je cal ;jump to cal
        mov ah,00h ;clear the junk in ah
        push ax ;push ax onto the stack
        dec al ;decrement al
        call fact ;calls procedure fact
        pop ax ;pops the top of the stack
        mul res ;mutiplies res with ax and stores it in ax
        mov res,al ;contains al
        ret ;returns to the line following procedure call
    cal:
        mov res,01 ;move 1 to res
        ret ;returns to the line following procedure call
    fact endp ;end of procedure
 code ends
 end start

assume cs:code,ds:data
data segment
    str1 db 'madam' ;string to be checked for
    n dw n-str1 ;contains size of str1
    str2 db 5 dup(?) ;to copy the reverse of str2
    msg1 db "It is a Palindrome$"
    msg2 db "It is not a Palindrome$"
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        mov es,ax 
        mov cx,n ;contains str1 size
        lea si,n
        dec si ;points to the position of last char in str1
        lea di,str2 ;points to the first char position of str2 
    next:
        mov al,[si] ;to copy
        mov [di],al ;the reverse of str1 into str2
        inc di
        dec si
        loop next ;loop until str1 is completely copied into str2
        
        lea si,str1 ;points to the first char position of str1
        lea di,str2 ;points to the first char position of str2
        mov cx,n ;contains str1 size
        cld ;to clear direction flag 
        rep cmpsb ;compare str1 and str2 char by char(byte by byte)
        jnz failure ;jump if unequal
        lea dx,msg1 ;load msg1
        jmp display ;jump to display
    failure:
        lea dx,msg2 ;load msg2
    display:
        mov ah,09h ;to print string
        int 21h
        mov ah,07h ;waits for the char from stdin
        int 21h
code ends
end start

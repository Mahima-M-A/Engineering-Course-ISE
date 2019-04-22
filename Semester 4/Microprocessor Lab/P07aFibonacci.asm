assume cs:code,ds:data
data segment
    fibo db 10 dup(?) ;to store first 10 fibonacci numbers
    n db 0ah ;initialize to 10h
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        lea si,fibo ;to point to the first array element position
        mov al,00h ;to store 0h(first fibonacci number)
        mov [si],al ;at first position of array
        inc si ;to point to next position
        mov bl,01h ;to store 01h(second fibonacci number)
        mov [si],bl ;at second position of array
        inc si ;to point to next position
        mov cl,n ;to loop 'n' times
        sub cl,2 ;because first 2 elements are already stored
        mov ch,00 ;to clear ch
    next:
        add al,bl ;add the previous 2 values to get the next value
        mov [si],al ;store the new value at next position
        inc si ;to point to next position
        xchg al,bl ;to get the next value properly
        loop next ;loop until we get the next 8 fibonacci series numbers
        
        mov ah,4ch ;to exit the program
        int 21h
code ends
end start

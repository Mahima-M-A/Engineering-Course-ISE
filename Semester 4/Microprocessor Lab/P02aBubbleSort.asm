assume cs:code,ds:data
data segment
    arr db 10h,2h,35h,4h,3h ;unsorted array
    n db n-arr ;contains array size
data ends
code segment
    start:
        mov ax,data
        mov ds,ax
        mov bx,n  ;contains array size
        dec bx  ;contains the last array element's position
    nextpass:
        mov cx,bx ;to loop bx times
        lea si,arr ;loads the first array elemnt's position into si
    nextloop:
        mov al,[si] ;contains the array element pointed to by si
        cmp al,[si+1] ;compares the array element pointed to by si with the next element
        jbe do_nothing ;jump if the array element pointed to by si is less than or equal to the nezt element
        xchg al,[si+1] ;else swap
        mov [si],al ;copy al's value to the array position pointed to by si
    do_nothing:
        inc si ;increment si to point to next element
        loop nextloop ;continue looping
        dec bx ;else decrement bx
        jnz nextpass ;continue nextpass

        mov ah,4ch ;to exit program 
        int 21h
code ends
end start

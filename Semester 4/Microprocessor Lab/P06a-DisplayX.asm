assume cs:code
code segment
    start:
        mov ah,00h ;to set to video mode
        mov al,02h ;to set to screen's boundary
        int 10h ;BIOS interrupts
        mov ah,02h ;to set the cursor's position
        mov dh,12d ;to set the row position
        mov dl,40d ;to set the column position
        int 10h 
        mov al,'X' ;to set the char to be printed
        mov bl,8ch 
        mov cl,1 ;to set the number of times the set char should print
        mov ah,09 ;to display char with attributes
        int 10h
        mov ah,07h ;waits for the char from stdin
        int 21h
        mov ah,4ch ;to exit the program
        int 21h
code ends
end start

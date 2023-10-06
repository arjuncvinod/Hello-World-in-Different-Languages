.model small
.data
    hello_msg db 'Hello, World!', '$' ; null-terminated string
.code
    main proc
        mov ah, 9       ; AH = 9 (MS-DOS print string function)
        mov dx, offset hello_msg ; DX = offset of hello_msg
        int 21h         ; Call MS-DOS interrupt 21h to print the message
        mov ah, 4Ch     ; AH = 4Ch (MS-DOS exit function)
        int 21h         ; Call MS-DOS interrupt 21h to exit the program
    main endp
end

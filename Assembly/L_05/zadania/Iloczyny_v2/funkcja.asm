.code
iloczyn_mniejszych PROC
    test rcx, rcx        
    je blad
    test rdx, rdx       
    jle blad
    mov rsi, rcx
    mov ecx, edx
    mov edx, r8d
    mov eax, 1
petla:
    test ecx, ecx
    je koniec
    mov ebx, DWORD PTR [rsi]
    cmp ebx, edx
    jge pomijaj
    imul eax, ebx
pomijaj:
    add rsi, 4
    dec ecx
    jmp petla
blad:
    mov eax, 0
koniec:
    ret
iloczyn_mniejszych ENDP
END

.code
    srednia_arytmetyczna PROC;
Parametry :;
RCX - wskaźnik na tablicę float(float *tab);
EDX - liczba elementów(int n);
Zwraca : XMM0 - średnia arytmetyczna jako double
                    push rbp
                        mov rbp,
    rsp
        sub rsp,
    16;
walidacja danych
    cmp edx,
    0 jle invalid_input;
Zapisz n na stosie
    mov[rbp - 8],
    edx
            finit
                fldz xor
        rax,
    rax
        loop_start : cmp eax,
                     edx
                         jge loop_end
                             fld dword ptr[rcx + rax * 4] faddp st(1),
                     st(0)
                         inc rax
                     jmp loop_start
                     loop_end :;
Oblicz średnią : suma / n
                            fild dword ptr[rbp - 8] fdivp st(1),
    st(0)
        fstp qword ptr[rbp - 16] movsd xmm0,
    qword ptr[rbp - 16] mov rsp, rbp pop rbp ret invalid_input : pxor xmm0, xmm0 mov rsp, rbp pop rbp ret srednia_arytmetyczna ENDP END
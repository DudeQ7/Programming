.code
wyrazenie_a PROC
    finit                   
    ; Oblicz pierwszą część: 2.34 / 1.75
    sub rsp, 40              ; Zarezerwuj 40 bajtów na stosie dla wyrównania
    movq rax, xmm0           
    mov qword ptr [rsp], rax 
    fld qword ptr [rsp]      
    movq rbx, xmm1           
    mov qword ptr [rsp + 8], rbx
    fld qword ptr [rsp + 8]  
    fdiv                    
    fxch                     
    fstp st(0)             
    fstp qword ptr [rsp + 16] 
    ; Oblicz denominator: 97 - 6.33 * 3.14
    movq r8, xmm5            
    mov qword ptr [rsp], r8  
    fld qword ptr [rsp]      
    movq r9, xmm6            
    mov qword ptr [rsp + 8], r9 
    fld qword ptr [rsp + 8]  
    fmul                    
    movq r10, xmm4           
    mov qword ptr [rsp + 8], r10 
    fld qword ptr [rsp + 8]  
    fsubp st(1), st          
    ; Oblicz licznik: 373 * 1.735
    movq rcx, xmm2           
    mov qword ptr [rsp], rcx 
    fld qword ptr [rsp]      
    movq rdx, xmm3          
    mov qword ptr [rsp + 8], rdx 
    fld qword ptr [rsp + 8]  
    fmulp st(2), st          

    ; Podziel: (97 - 6.33 * 3.14) / (373 * 1.735)
    fdivp st(1), st          

    ; Odejmij: (2.34 / 1.75) - [(97 - 6.33 * 3.14) / (373 * 1.735)]
    fld qword ptr [rsp + 16] 
    fsub                     
    fstp st(1)               

    ; Przenieś wynik do XMM0
    fstp qword ptr [rsp]     ; Zapisz wynik na stosie
    mov rax, [rsp]           ; Przenieś wynik do rax
    movq xmm0, rax           ; Przenieś wynik z rax do xmm0
    add rsp, 40              ; Zwolnij miejsce na stosie
    ret
wyrazenie_a ENDP
end
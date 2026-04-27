.code
pole_okregu PROC
    finit                    ; Inicjalizacja FPU
    sub rsp, 16              ;
    movq rax, xmm0           
    mov qword ptr [rsp], rax 
    fld qword ptr [rsp]      
    fldpi                    
    fmul                     
    fld1                     
    fadd st, st(0)           
    fmul                     
    fstp qword ptr [rsp]     
    mov rax, [rsp]           
    movq xmm0, rax           
    add rsp, 16              
    ret
pole_okregu ENDP
end
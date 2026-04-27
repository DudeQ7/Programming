.code
silnia PROC
    mov     eax, 1          ; wynik silni, 32-bit (silnia zmieści się w 32-bit)
    cmp     ecx, 1          ; porównaj n z 1
    jle     koniec          ; jeśli n <=1 to silnia=1
petla:
    imul    eax, ecx        ; eax = eax * ecx
    dec     ecx             ; ecx = ecx - 1
    cmp     ecx, 1
    ja      petla           ; jeśli ecx > 1 to kontynuuj
koniec:
    ret
silnia ENDP
END

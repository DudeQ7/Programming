.code
;Funckcja iloczynu
iloczyn PROC
	mov eax,ecx 
	imul eax,edx;
	imul eax,r8d;
	imul eax,r9d;
	ret 
iloczyn ENDP
END

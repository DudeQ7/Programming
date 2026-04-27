.code 
max proc
	mov eax,[rcx]
	mov r8,1
start_petli:
	cmp r8,rdx
	jge koniec_petli
	mov r9d,[rcx+r8*4];kolejny element tablicy
	cmp eax,r9d ;porownanie z dotychczasowym maximum
	jge ten_sam_max
	mov eax,r9d
ten_sam_max:
	inc r8 
	jmp start_petli
koniec_petli:
	ret
max endp
end
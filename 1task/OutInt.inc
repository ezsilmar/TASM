OutInt proc
        push ax
        push bx
        push cx
        push dx
        push bp
        mov bp, sp ; bp - ��� ��������� �� ����

        mov ax, [bp+12]
; ��������� ����� �� ����.
        test ax, ax
        jns outAbs
 ; ���� ��� �������������, ������� ����� � ������� ��� ������.
        push ax
        mov ah, 02h
        mov dl, '-'
        int 21h
        pop ax
        neg ax

outAbs:
        mov bx, 10
        mov cx, ax
        jcxz outZ
        
dropInsignificantZ:
        xor dx,dx
        div bx
        mov cx, dx
        jcxz dropInsignificantZ ; ���� ������� �� ������� 0
        ; first not 0 num
        push ax
        add dl, '0'
        mov ah, 02h
        int 21h
        pop ax
        
outModulo:

        mov cx, ax
        jcxz exit
        
        xor dx,dx
        div bx

        push ax
        add dl, '0'
        mov ah, 02h
        int 21h
        pop ax

        test ax, ax
        jnz outModulo

exit:
;�������.
        pop bp
        pop dx
        pop cx
        pop bx
        pop ax
       
        ret
 
 outZ: 
        mov dl, '0'
        mov ah, 02h
        int 21h
        
        jmp exit
 
OutInt endp
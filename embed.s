%ifndef NAME
    %error NAME not defined
%elifndef FILE
    %error FILE not defined
%endif


section .rodata

global NAME %+ _begin
global NAME %+ _end
global NAME %+ _size


begin: incbin FILE
end:

NAME %+ _begin: dq begin
NAME %+ _end: dq end
NAME %+ _size: dq end - begin

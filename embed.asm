%ifndef NAME
    %error NAME not defined
%elifndef FILE
    %error FILE not defined
%endif

bits 64
section .rodata

global embed_ %+ NAME %+ _begin
global embed_ %+ NAME %+ _end
global embed_ %+ NAME %+ _size

begin: incbin FILE
end:

embed_ %+ NAME %+ _begin: dq begin
embed_ %+ NAME %+ _end: dq end
embed_ %+ NAME %+ _size: dq end - begin

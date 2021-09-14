; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:04 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:18 CST. 
%define lw 0

%macro colon 2
%%lw: dq lw
db %1, 0
xt_ %+ %2: ; concatinate xt_ and %2

%define lw %%lw
%endmacro

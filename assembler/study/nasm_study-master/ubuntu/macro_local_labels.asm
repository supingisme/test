; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 


%macro mymacro 0
%%labelname:
%%labelname:
%endmacro

; expand to `..@0.labelname:`
mymacro
; expand to `..@1.labelname:`
mymacro
; expand to `..@2.labelname:`
mymacro

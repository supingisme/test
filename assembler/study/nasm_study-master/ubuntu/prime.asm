; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 06月 14日 星期五 09:05:05 CST. 
; Copyright (C) Rong Tao @Sylincom Beijing, 2019年 03月 19日 星期二 18:33:19 CST. 




%assign limit 15
is_prime: db 0, 0, 1
%assign n 3
%rep limit
  %assign current 1
  %assign i 1
    %rep n / 2
      %assign i i + 1
      %if n % i = 0
        %assign current 0
        %exitrep
      %endif
    %endrep
db current
  %assign n n+1
%endrep

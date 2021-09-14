# QUIC （Quick UDP Internet Connections，快速 UDP 网络连接）

[QUIC HostStack](https://fd.io/docs/vpp/master/gettingstarted/developers/quic_plugin.html)

>QUIC（Quick UDP Internet Connections，快速 UDP 网络连接）是一种实验性的网络传输协议。从网络层级来看，QUIC 是类似于 TCP，UDP 和 SPDY 的数据传输协议，目前正在由 Internet 工程任务组（IETF）进行标准化。
>关于 QUIC 的研究始于 2010 年代初期，由 Google 率先进行的尝试。当时 Google 希望创建一个更快，更强调性能的数据传输协议来代替 HTTPS/HTTP。
>QUIC 借鉴了 TCP、UDP 和 TLS（用于加密）的原理和功能，在这个基础上优化了传输的速度。QUIC 的数据传输从第一个数据包传送（0-RTT）开始立即开始，从而减少了应用程序延迟时间。并且可以在数据量已满时调整管理流程（拥塞控制），从而更快更安全。QUIC 协议在登录成功、推拉流成功的耗时，大幅低于 TCP 协议，优化百分比在 30% 以上，极端场景甚至超过 90%。


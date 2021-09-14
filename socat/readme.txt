https://github.com/craSH/socat

socat是用于在两个独立数据通道之间进行双向数据传输的中继。 这些数据通道中的每一个可以是文件，管道，设备（串行线等或伪终端），套接字（UNIX，IP4，IP6-原始，UDP，TCP），SSL套接字，代理CONNECT连接，文件 描述符（stdin等），GNU行编辑器（readline），一个程序或其中两个的组合。 这些模式包括“监听”套接字，命名管道和伪终端的生成。

UNIX监听服务端
---------------------------------
# socat unix-listen:./rtoax_unsocket_pcap stdio


UNIX链接客户端
--------------------------------
# echo "sadsfasdfhow info" | socat unix-connect:./rtoax_unsocket_pcap stdio

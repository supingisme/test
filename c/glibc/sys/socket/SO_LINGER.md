Set SO_LINGER socket option
16–19 Once the connection is established, we set the SO_LINGER socket option, setting the l_onoff flag to 1 and the l_linger time to 0. As stated in Section 7.5(See 8.5.5), this causes an RST to be sent on a TCP socket when the connection is closed. We then close the socket.

Next, we modify our TCP server from Figures 6.21(See 8.4.8) and 6.22(See 8.4.8) to pause after select returns that the listening socket is readable, but before calling accept. In the following code from the beginning of Figure 6.22(See 8.4.8), the two lines preceded by a plus sign are new:


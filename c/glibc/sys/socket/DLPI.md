Datalink Provider Interface (DLPI)

数据链路提供者接口

SVR4 provides datalink access through DLPI. DLPI is a protocol-independent interface designed by AT&T that interfaces to the service provided by the datalink layer [Unix International 1991]. Access to DLPI is by sending and receiving STREAMS messages.
There are two styles of DLPI. In one style, there is a single device to open, and the desired interface is specified using a DLPI DL_ATTACH_REQ request. In the other style, the application simply opens the device (e.g., le0). But for efficient operation, two additional STREAMS modules are normally pushed onto the stream: pfmod, which performs packet filtering within the kernel, and bufmod, which buffers the data destined for the application. We show this in Figure 29.2.



NDL
Like Devil, NDL allows the description of device register layouts. However, NDL offers additional
features that simplify device driver development and is even capable of generating complete
(network) device drivers from code templates.

Listing 6.2: Excerpt of NE2000 NDL interface (adopted from [Conway, 2010])
1 device ne2k : NetworkDevice {
2 ioports {
3 0x00: /* At offset 0x00 */
4 command = {
5 stop : trigger except 0,
6 start : trigger except 0,
7 transmit : trigger except 0,
8 dmaState : {
9 READING = #001
10 WRITING = #010
11 SENDING = #011
12 DISABLED = #1**
13 },
14 registerPage : int{0..2}
15 },
16
17 /* State machine */
18 state STOPPED {
19 goto DMA_DISABLED ;
20 stop = true ;
21 }
22 ||
23 STARTED { start = true ; }
24
25 state DMA_DISABLED { dmaState = DISABLED ; }
26 ||
27 DMA_READING { goto STARTED ; dmaState = READING ; }
28 ||
29 DMA_WRITING { goto STARTED ; dmaState = WRITING ; }
30 }

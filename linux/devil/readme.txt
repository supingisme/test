Devil
Devil is domain-specific language for describing the hardware I/O interface of a register-based
device [Mérillon et al., 2009]. Listing 6.2 shows a devil specification for a serial mouse which
will be explained in the course of this section.


#Listing 6.1: Devil specification for the logitech busmouse (taken from [Mérillon et al., 2009])
1 device logitech_busmouse (base : bit[8] port @ {0..3})
2 {
3 // Signature register (SR)
4 register sig_reg = base @ 1 : bit[8];
5 variable signature = sig_reg, volatile, write trigger : int(8);
6
7 // Configuration register (CR)
8 register cr = write base @ 3, mask ’1001000.’ : bit[8];
9 variable config = cr[0] : { CONFIGURATION => ’1’, DEFAULT_MODE => ’0’ };
10
11 // Interrupt register
12 register interrupt_reg = write base @ 2, mask ’000.0000’ : bit[8];
13 variable interrupt = interrupt_reg[4] : { ENABLE => ’0’, DISABLE => ’1’ };
14
15 // Index register
16 register index_reg = write base @ 2, mask ’1..00000’ : bit[8];
17 private variable index = index_reg[6..5] : int(2);
18
19 register x_low = read base @ 0, pre {index = 0}, mask ’****....’ : bit[8];
20 register x_high = read base @ 0, pre {index = 1}, mask ’****....’ : bit[8];
21 register y_low = read base @ 0, pre {index = 2}, mask ’****....’ : bit[8];
22 register y_high = read base @ 0, pre {index = 3}, mask ’...*....’ : bit[8];
23
24 structure mouse_state = {
25 variable dx = x_high[3..0] # x_low[3..0], volatile : signed int(8);
26 variable dy = y_high[3..0] # y_low[3..0], volatile : signed int(8);
27 variable buttons = y_high[7..5], volatile : int(3);
28 };
29
30 }

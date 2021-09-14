// Demonstrate some virtual key codes.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="KeyEvents" width=300 height=100>
</applet>
*/
/*
在键盘和鼠标事件处理的例子中展示的程序过程，可以被用于任何类型的事件处理，
包括那些由控件产生的事件。在最后一章，你将看到许多处理其他类型事件的例子，但是
它们采用的基本结构同前面所描述的例子程序是一样的。
*/

public class Demo_03_KeyEvent extends Applet
        implements KeyListener {

        String msg = "";
        int X = 10, Y = 20; // output coordinates
        public void init() {
                addKeyListener(this);
                requestFocus(); // request input focus
          }
        public void keyPressed(KeyEvent ke) {
                showStatus("Key Down");
                int key = ke.getKeyCode();
                switch(key) {
                        case KeyEvent.VK_F1:
                                msg += "<F1>";
                                break;
                        case KeyEvent.VK_F2:
                                msg += "<F2>";
                                break;
                        case KeyEvent.VK_F3:
                                msg += "<F3>";
                                break;
                        case KeyEvent.VK_PAGE_DOWN:
                                msg += "<PgDn>";
                                break;
                        case KeyEvent.VK_PAGE_UP:
                                msg += "<PgUp>";
                                break;
                        case KeyEvent.VK_LEFT:
                                msg += "<Left Arrow>";
                                break;
                        case KeyEvent.VK_RIGHT:
                                msg += "<Right Arrow>";
                                break;
                    }
                repaint();
          }
        public void keyReleased(KeyEvent ke) {
                showStatus("Key Released");
          }
        public void keyTyped(KeyEvent ke) {
                msg += ke.getKeyChar();
                repaint();
          }
        // Display keystrokes.
        public void paint(Graphics g) {
                g.drawString(msg, X, Y);
          }
}


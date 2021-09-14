// Demonstrate the key event handlers.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="Demo_02_SimpleKey" width=300 height=100>
</applet>
*/
public class Demo_02_SimpleKey extends Applet
        implements KeyListener {

        String msg = "";
        int X = 20, Y = 20; // output coordinates

        public void init() {
                addKeyListener(this);
                requestFocus(); // request input focus
          }

        public void keyPressed(KeyEvent ke) {
                showStatus("Key pressed");
          }

        public void keyReleased(KeyEvent ke) {
                showStatus("Key released");
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

// Demonstrate the mouse event handlers.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="Demo_01_MouseEvent" width=300 height=100>
</applet>
*/

/*
MouseEvents 类扩展了Applet 类， 同时实现了
MouseListener接口和MouseMotionListener接口。这两个接口包括了接受并处理各种鼠标事
件的方法。请注意，在这里小应用程序不但是事件源，同时也是这些事件的监听器。这是
因为支持addMouseListener( )方法和addMouseMotionListener( )方法的Component类是Applet
的超类。所以小应用程序不但是事件源而且还是监听器。
*/

public class Demo_01_MouseEvent extends Applet
implements MouseListener, MouseMotionListener {

        String msg = "";
        int mouseX = 0, mouseY = 0; // coordinates of mouse
        public void init() {
                addMouseListener(this);
                addMouseMotionListener(this);
          }
        // Handle mouse clicked.
        public void mouseClicked(MouseEvent me) {
                // save coordinates
                mouseX = 0;
                mouseY = 10;
                msg = "Mouse clicked.";
                repaint();
          }
        // Handle mouse entered.
        public void mouseEntered(MouseEvent me) {
                // save coordinates
                mouseX = 0;
                mouseY = 10;
                msg = "Mouse entered.";
                repaint();
          }
        // Handle mouse exited.
        public void mouseExited(MouseEvent me) {
                // save coordinates
                mouseX = 0;
                mouseY = 10;
                msg = "Mouse exited.";
                repaint();
          }
        // Handle button pressed.
        public void mousePressed(MouseEvent me) {
                // save coordinates
                mouseX = me.getX();
                mouseY = me.getY();
                msg = "pressed";
                repaint();
          }
        // Handle button released.
        public void mouseReleased(MouseEvent me) {
                // save coordinates
                mouseX = me.getX();
                mouseY = me.getY();
                msg = "released";
                repaint();
          }
        // Handle mouse dragged.
        public void mouseDragged(MouseEvent me) {
                // save coordinates
                mouseX = me.getX();
                mouseY = me.getY();
                msg = "*";
                showStatus("Dragging mouse at " + mouseX + ", " + mouseY);
                repaint();
          }
        // Handle mouse moved.
        public void mouseMoved(MouseEvent me) {
                // show status
                showStatus("Moving mouse at " + me.getX() + ", " + me.getY());
          }
        // Display msg in applet window at current X,Y location.
        public void paint(Graphics g) {
                g.drawString(msg, mouseX, mouseY);
        }
}


// This applet does NOT use an inner class.
import java.applet.*;
import java.awt.event.*;
/*
<applet code="MousePressedDemo" width=200 height=100>
</applet>
*/
public class Demo_05_MousePressed extends Applet {
        public void init() {
                addMouseListener(new MyMouseAdapter(this));
          }
}
class MyMouseAdapter extends MouseAdapter {

        Demo_05_MousePressed mousePressedDemo;
        public MyMouseAdapter(Demo_05_MousePressed mousePressedDemo) {
                this.mousePressedDemo = mousePressedDemo;
          }
        public void mousePressed(MouseEvent me) {
                mousePressedDemo.showStatus("Mouse Pressed.");
          }
}

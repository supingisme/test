// Inner class demo.
import java.applet.*;
import java.awt.event.*;
/*
<applet code="InnerClassDemo" width=200 height=100>
</applet>
*/
public class Demo_05_InnerClass extends Applet {

        public void init() {
                addMouseListener(new MyMouseAdapter());
          }

        class MyMouseAdapter extends MouseAdapter {
                public void mousePressed(MouseEvent me) {
                        showStatus("Mouse Pressed");
                    }
          }
}

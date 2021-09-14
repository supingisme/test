// Demonstrate an adapter.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="AdapterDemo" width=300 height=100>
</applet>
*/

/*
不必去实现MouseMotionListener接口和MouseListener接口定义的
全部方法，这就让我们省去了相当多的处理,也预防了由空方法带来的代码混乱
*/
public class Demo_04_MouseAdapter extends Applet {

        public void init() {
                addMouseListener(new MyMouseAdapter(this));
                addMouseMotionListener(new MyMouseMotionAdapter(this));
         }
}


class MyMouseAdapter extends MouseAdapter {

        Demo_04_MouseAdapter adapterDemo;
        public MyMouseAdapter(Demo_04_MouseAdapter adapterDemo) {
                this.adapterDemo = adapterDemo;
          }
        // Handle mouse clicked.
        public void mouseClicked(MouseEvent me) {
                adapterDemo.showStatus("Mouse clicked");
          }
}
class MyMouseMotionAdapter extends MouseMotionAdapter {

        Demo_04_MouseAdapter adapterDemo;
        public MyMouseMotionAdapter(Demo_04_MouseAdapter adapterDemo) {
                this.adapterDemo = adapterDemo;
          }
        // Handle mouse dragged.
        public void mouseDragged(MouseEvent me) {
                adapterDemo.showStatus("Mouse dragged");
          }
}


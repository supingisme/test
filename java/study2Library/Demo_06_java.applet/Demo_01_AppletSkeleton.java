// An Applet skeleton.
import java.awt.*;
import java.applet.*;
/*
<applet code="AppletSkel" width=300 height=100>
</applet>
*/
public class Demo_01_AppletSkeleton extends Applet {
        
        String msg;

        public void init() {
                
                setBackground(Color.green);
                setForeground(Color.red);
                msg = "Inside init() --";
          }
        
        public void start() {
                msg += " Inside start() --";
          }
        
        public void stop() {
                
          }
        
        public void destroy() {
                
          }
        public void update(Graphics g) {
                g.drawString(msg,10,30);
                //paint(g);
          }
        
        public void paint(Graphics g) {
                
                msg += " Inside paint().";
                update(g);
                
          }
        
}

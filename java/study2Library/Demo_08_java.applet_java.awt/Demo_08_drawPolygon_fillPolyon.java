// Draw Polygon
import java.awt.*;
import java.applet.*;
/*
<applet code="HourGlass" width=230 height=210>
</applet>
*/
public class Demo_08_drawPolygon_fillPolyon extends Applet {

        public void paint(Graphics g) {
                int xpoints[] = {30, 200, 30, 200, 30};
                int ypoints[] = {30, 30, 200, 200, 30};
                int num = 5;
                g.drawPolygon(xpoints, ypoints, num);
          }
}

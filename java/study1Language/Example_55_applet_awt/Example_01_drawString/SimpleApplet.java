/*
2017/5/24
*/
import java.awt.*;
import java.applet.*;

/*
HTML file
<applet code="SimpleApplet" width=200 height=60>
</applet>

run:
appletviewer RunApp.html
*/

public class SimpleApplet extends Applet{
	public void paint(Graphics g){
		g.drawString("Rong Tao",20,20);
	}
}

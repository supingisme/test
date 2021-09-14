/* Using an applet context, getCodeBase(),
and showDocument() to display an HTML file.
下面的小应用程序说明了AppletContext和showDocument( )方法。在执行时，它获得了
当前小应用程序的上下文，并用上下文将控制权交给一个名为Test.html的文件。这个文件
必须与小应用程序在同一目录下。Test.html.能包含任何有效的超文本。
*/
import java.awt.*;
import java.applet.*;

import java.net.*;
/*
<applet code="Demo_06_AppletContext_showDocument" width=300 height=50>
</applet>
*/
public class Demo_06_AppletContext_showDocument extends Applet{
        public void start() {
                AppletContext ac = getAppletContext();
                URL url = getCodeBase(); // get url of this applet
                try {
                        ac.showDocument(new URL(url+"Test.html"));
                } catch(MalformedURLException e) {
                        showStatus("URL not found");
                    }
          }
}



import java.awt.Frame;
import java.awt.Label;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class hello {

        public static native int sum(int i,int j);     

	public static void main(String[] args) {

        System.loadLibrary("math");

		Frame f = new Frame();
		f.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		f.add(new Label("This JAR file is executable!   ="+Integer.toString(sum(21,12))));
		f.setSize(500, 500);
		f.setVisible(true);
	}
}

import java.awt.*;
import java.awt.event.*;

public class Demo_08_button {
    public static void main(String args[]) {
            Frame f = new Frame("Test");
            Button b = new Button("Press Me!");
            Monitor bh = new Monitor();
            b.addActionListener(bh);
            f.add(b,BorderLayout.CENTER);
            f.pack();  //调整此窗口大小，以适应其组件的首先大小和布局
            f.setVisible(true);
    }
}

class Monitor implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        System.out.println("a button has been pressed");    
    }
}

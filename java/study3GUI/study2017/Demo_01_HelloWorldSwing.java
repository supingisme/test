import javax.swing.*;
import java.awt.*;

public class Demo_01_HelloWorldSwing {
    private static void createAndShowGUI() {
        JFrame frame = new JFrame("HelloWorld");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Pane's layout
        Container cp = frame.getContentPane();
        cp.setLayout(new FlowLayout());

        // create button
        JButton b1 = new JButton("click me");
        JButton b2 = new JButton("shit");

        // add buttons
        cp.add(b1);
        cp.add(b2);

        // show the window
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        Runnable tr = new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        };
        javax.swing.SwingUtilities.invokeLater(tr);
    }
}

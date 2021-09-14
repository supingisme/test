import javax.swing.*;
import java.awt.*;
public class Demo_01_HelloWorldSwing02 {
    private static void createAndShowGUI() {
        JFrame frame = new JFrame("HelloWorld");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Pane's layout
        Container cp = frame.getContentPane();
        cp.setLayout(new GridLayout(0,2));

        // JButton
        JButton button = new JButton("click me");
        JLabel label = new JLabel("OK");

        // JPanel       
        JPanel panel1 = new JPanel(new BorderLayout());
        JPanel panel2 = new JPanel(new BorderLayout());
        panel2.setBackground(Color.red);

        panel1.add(button, BorderLayout.CENTER);
        cp.add(panel1);
        panel2.add(label, BorderLayout.EAST);
        cp.add(panel2);

        // JList
        String[] lines = {"a", "b", "c"};
        JList list = new JList(lines);
        cp.add(list);

        // JCheckBox
        cp.add(new JCheckBox());

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

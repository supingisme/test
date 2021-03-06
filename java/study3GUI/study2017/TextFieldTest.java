import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class TextFieldTest extends JFrame
        implements ActionListener
{
        private JLabel result;
        private JTextField first, last;

        TextFieldTest()
        {
                setTitle("TextFieldTest");
                addWindowListener(new WindowHandler());
                Container cp = getContentPane();
                cp.setLayout(new FlowLayout()); // override default
                cp.add(new JLabel("Enter your first name"));
                cp.add(first = new JTextField(15));
                cp.add(new JLabel("Enter your last name"));
                cp.add(last = new JTextField(15));
                JButton done = new JButton("Done");
                cp.add(done);
                done.addActionListener(this);
                result = new JLabel("********************");
                cp.add(result);
        }
        public void actionPerformed(ActionEvent e)
        {
                String firstName = first.getText();
                String lastName = last.getText();
                result.setText("Hello, " + firstName + " " + lastName); 
        }
        class WindowHandler extends WindowAdapter
        {
                public void windowClosing(WindowEvent e)
                { System.exit(0); }
        }

        public static void main(String [] a)
        {
                JFrame jf = new TextFieldTest();
                jf.setSize(160, 200);
                jf.setVisible(true);
        }
}

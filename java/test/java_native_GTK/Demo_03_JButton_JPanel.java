import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

class Demo extends JFrame {

        private Toolkit toolkit;

        public native void gtk_draw();

        Demo() {

                setTitle("Demo");
                setSize(300, 200);

                toolkit = getToolkit();
                Dimension size = toolkit.getScreenSize();

                System.loadLibrary("GTK");

                setLocation((size.width/2 - getWidth())/2, (size.height - getHeight())/2);
                setDefaultCloseOperation(EXIT_ON_CLOSE);

                JPanel panel = new JPanel();
                //getContentPane().add(panel);
                add(panel);

                //panel.setLayout(new GridLayout(2,2));
                panel.setLayout(null);

                JButton beep = new JButton("Beep");
                beep.setBounds(150, 60, 80, 30);

                beep.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent event) {
                                toolkit.beep();
                                System.out.println("Beep");
                                gtk_draw();
                              }
                    });

                JButton close = new JButton("Close");
                close.setBounds(50, 60, 80, 30);

                close.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent event) {
                                System.exit(0);
                              }
                    });

                panel.add(beep);
                panel.add(close);
          }
        public static void main(String[] args) {
                Demo demo = new Demo();
                demo.setVisible(true);
          }
}


/*a##############################################################################
a###
a###             
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_09 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_09(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_09 Demo_09 = new Demo_09();

                Demo_09.showCanvasDemo();

          }

        private void prepareGUI(){

                frame = new Frame("Java AWT Examples");
                frame.setSize(500,500);
                frame.setLayout(new GridLayout(3, 1));

                frame.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                              }
                    });

                label1 = new Label();
                label1.setAlignment(Label.CENTER);

                label2 = new Label();
                label2.setAlignment(Label.CENTER);
                //label2.setSize(350,100);

                panel = new Panel();
                panel.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);

                frame.setVisible(true);
          }

        private void showCanvasDemo(){

                label1.setText("Control in action: Canvas");

                panel.add(new MyCanvas());

                frame.setVisible(true);

          }
        class MyCanvas extends Canvas {

                public MyCanvas () {

                        setBackground (Color.GRAY);
                        setSize(400, 400);
                    }

                public void paint (Graphics g) {

                        Graphics2D g2;

                        g2 = (Graphics2D) g;

                        g2.drawString ("It is a custom canvas area", 70, 70);
                    }
          }
}

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

class Demo_30 extends Frame {

        public Demo_30(){

                super("Java AWT Examples");
                prepareGUI();
          }
        public static void main(String[] args){

                Demo_30 Demo_30 = new Demo_30();
                Demo_30.setVisible(true);
          }
        private void prepareGUI(){

                setSize(400,400);
                addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                              }
                    });
          }

        @Override
        public void paint(Graphics g) {

                g.setColor(Color.RED);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 150);
                repaint(g);
          }

        public void repaint(Graphics g){

                g.setColor(Color.BLACK);
                Font font = new Font("Serif", Font.PLAIN, 28);
                g.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 50);
          }  
}

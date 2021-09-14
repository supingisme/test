import java.awt.*;
import java.awt.event.*;
class Demo_16 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;

        public Demo_16(){

                prepareGUI();
          }
        public static void main(String[] args){

                Demo_16 Demo_16 = new Demo_16();
                Demo_16.showMouseListenerDemo();
          }

        private void prepareGUI(){

                frame = new Frame("Java AWT Examples");
                frame.setSize(400,400);
                frame.setLayout(new GridLayout(3, 1));

                frame.addWindowListener(new WindowAdapter() {

                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                              }
                    });

                //frame.addMouseListener(new CustomMouseListener());

                label1 = new Label();
                label1.setAlignment(Label.CENTER);
                label1.addMouseListener(new CustomMouseListener());
                label2 = new Label();
                label2.setAlignment(Label.CENTER);
                label2.setSize(350,100);
                label2.addMouseListener(new CustomMouseListener());

                panel0 = new Panel();
                panel0.setLayout(new FlowLayout());
                panel0.addMouseListener(new CustomMouseListener());

                frame.add(label1);
                frame.add(panel0);
                frame.add(label2);

                frame.setVisible(true);
          }

        private void showMouseListenerDemo(){

                label1.setText("Listener in action: MouseListener");

                Panel panel = new Panel();
                panel.setBackground(Color.magenta);
                panel.setLayout(new FlowLayout());

                panel.addMouseListener(new CustomMouseListener());

                Label msglabel = new Label();
                msglabel.setAlignment(Label.CENTER);
                msglabel.setText("Welcome to TutorialsPoint AWT Tutorial.");

                msglabel.addMouseListener(new CustomMouseListener());

                panel.add(msglabel);
                panel0.add(panel);

                frame.setVisible(true);
          }

        class CustomMouseListener implements MouseListener{

/*
Interface: MouseListener

1	void mouseClicked(MouseEvent e) 
Invoked when the mouse button has been clicked (pressed and released) on a component.
2	void mouseEntered(MouseEvent e) 
Invoked when the mouse enters a component.
3	void mouseExited(MouseEvent e) 
Invoked when the mouse exits a component.
4	void mousePressed(MouseEvent e) 
Invoked when a mouse button has been pressed on a component.
5	void mouseReleased(MouseEvent e)
Invoked when a mouse button has been released on a component.
*/

                public void mouseClicked(MouseEvent e) {

                        label2.setText("Mouse Clicked: ("
                                        +e.getX()+", "+e.getY() +")");
                    }

                public void mousePressed(MouseEvent e) {}

                public void mouseReleased(MouseEvent e) {}

                public void mouseEntered(MouseEvent e) {}

                public void mouseExited(MouseEvent e) {}
          }
}

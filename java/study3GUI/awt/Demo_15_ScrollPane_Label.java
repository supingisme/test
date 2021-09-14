import java.awt.*;
import java.awt.event.*;

class Demo_15 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_15(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_15 Demo_15 = new Demo_15();
                Demo_15.showComponentListenerDemo();
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

                label1 = new Label();
                label1.setAlignment(Label.CENTER);
                label2 = new Label();
                label2.setAlignment(Label.CENTER);
                label2.setSize(350,100);

                panel = new Panel();
                panel.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);

                frame.setVisible(true);
          }
        private void showComponentListenerDemo(){

                label1.setText("Listener in action: ComponentListener");

                ScrollPane panel1 = new ScrollPane();
                panel1.setBackground(Color.magenta);

                Label msglabel = new Label();
                msglabel.setAlignment(Label.CENTER);
                msglabel.setText("Welcome to TutorialsPoint AWT Tutorial.");

                panel1.add(msglabel);

                msglabel.addComponentListener(new CustomComponentListener());

                panel.add(panel1);

                frame.setVisible(true);
          }
        class CustomComponentListener implements ComponentListener {

                public void componentResized(ComponentEvent e) {

                        label2.setText(label2.getText()
                                + e.getComponent().getClass().getSimpleName() + " resized. ");
                    }

                public void componentMoved(ComponentEvent e) {

                        label2.setText(label2.getText()
                                + e.getComponent().getClass().getSimpleName() + " moved. ");
                    }

                public void componentShown(ComponentEvent e) {

                        label2.setText(label2.getText()
                                + e.getComponent().getClass().getSimpleName() + " shown. ");
                    }

                public void componentHidden(ComponentEvent e) {

                        label2.setText(label2.getText()
                                + e.getComponent().getClass().getSimpleName() + " hidden. ");
                    }
          }
}

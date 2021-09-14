import java.awt.*;
import java.awt.event.*;
class Demo_19 {

        private Frame frame2;
        private Frame frame1;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_19(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_19 Demo_19 = new Demo_19();
                Demo_19.showWindowListenerDemo();
          }

        private void prepareGUI(){

                frame1 = new Frame("Java AWT Examples");
                frame1.setSize(400,400);
                frame1.setLayout(new GridLayout(4, 1));

                frame1.addWindowListener(new WindowAdapter() {
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
                Button okButton = new Button("OK");
                panel.add(okButton);

                frame1.add(label1);
                frame1.add(panel);
                frame1.add(label2);

                okButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                                frame2.setVisible(true);
                              }
                    });

                frame1.setVisible(true);
          }
        private void showWindowListenerDemo(){

                label1.setText("Listener in action: WindowListener");



                frame2 = new Frame();
                frame2.setSize(300,200);;
                frame2.setTitle("WindowListener Demo");
                frame2.addWindowListener(new CustomWindowListener());

                Label msgLabel = new Label("Welcome to tutorial spoint.");
                msgLabel.setAlignment(Label.CENTER);
                msgLabel.setSize(100,100);

                frame2.add(msgLabel);

                frame2.setVisible(false);

          }
        class CustomWindowListener implements WindowListener {

                public void windowOpened(WindowEvent e) {}
                public void windowClosing(WindowEvent e) {frame2.dispose();}
                public void windowClosed(WindowEvent e) {}
                public void windowIconified(WindowEvent e) {}
                public void windowDeiconified(WindowEvent e) {}
                public void windowActivated(WindowEvent e) {}
                public void windowDeactivated(WindowEvent e) {}
          }
}

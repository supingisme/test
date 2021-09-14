import java.awt.*;
import java.awt.event.*;

class Demo_14 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_14(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_14 Demo_14 = new Demo_14();
                Demo_14.showActionListenerDemo();
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
        private void showActionListenerDemo(){

                label1.setText("Listener in action: ActionListener");

                ScrollPane scrollpanel = new ScrollPane();
                scrollpanel.setBackground(Color.magenta);

                Button okButton = new Button("OK");
                okButton.addActionListener(new CustomActionListener());

                scrollpanel.add(okButton);
                panel.add(scrollpanel);

                frame.setVisible(true);
          }
        class CustomActionListener implements ActionListener{

                public void actionPerformed(ActionEvent e) {

                        label2.setText("Ok Button Clicked.");
                    }
          }
}

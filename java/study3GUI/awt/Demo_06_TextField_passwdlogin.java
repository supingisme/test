/*a##############################################################################
a###
a###             
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_06 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        private float passwd;

        public Demo_06(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_06 Demo_06 = new Demo_06();
                Demo_06.showTextFieldDemo();
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
                //label2.setSize(350,100);

                panel = new Panel();
                panel.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);

                frame.setVisible(true);
          }

        private void showTextFieldDemo(){

                label1.setText("Control in action: TextField");

                Label namelabel= new Label("User ID: ", Label.RIGHT);
                Label passwordLabel = new Label("Password: ", Label.CENTER);

                final TextField userText = new TextField(6);
                final TextField passwordText = new TextField(6);

                //passwordText.setEchoChar('*');

                Button loginButton = new Button("Login");

                loginButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {

                                String data = "Username: " + userText.getText();
                                data += ", Password: " + passwordText.getText();

                                passwd = (float) Integer.parseInt(passwordText.getText());
                                System.out.println("passwd = "+passwd);

                                if(passwordText.getText().equals("")||userText.getText().equals(""))
                                        data="Please input text!";

                                label2.setText(data);

                              }
                    });

                panel.add(namelabel);
                panel.add(userText);
                panel.add(passwordLabel);
                panel.add(passwordText);
                panel.add(loginButton);

                frame.setVisible(true);
          }
}

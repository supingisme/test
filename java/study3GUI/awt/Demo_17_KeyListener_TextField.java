import java.awt.*;
import java.awt.event.*;

class Demo_17 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;
        private TextField textField;

        public Demo_17(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_17 Demo_17 = new Demo_17();
                Demo_17.showKeyListenerDemo();
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
        private void showKeyListenerDemo(){

                label1.setText("Listener in action: KeyListener");

                textField = new TextField(10);
                textField.addKeyListener(new CustomKeyListener());

                Button okButton = new Button("OK");

                okButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                                label2.setText("Entered text: " + textField.getText());
                              }
                    });

                panel.add(textField);
                panel.add(okButton);

                frame.setVisible(true);
          }

        class CustomKeyListener implements KeyListener{

/*
interface: KeyListener

1	void keyPressed(KeyEvent e) 
Invoked when a key has been pressed.
2	void keyReleased(KeyEvent e) 
Invoked when a key has been released.
3	void keyTyped(KeyEvent e) 
Invoked when a key has been typed.
*/

                public void keyTyped(KeyEvent e) {}

                public void keyPressed(KeyEvent e) {

                        //System.out.print(Integer.parseInt(textField.getText())+" ");

                        if(e.getKeyCode() == KeyEvent.VK_ENTER){

                                label2.setText("Entered text: " + textField.getText());
                              }
                    }
                public void keyReleased(KeyEvent e) {}
          }
}

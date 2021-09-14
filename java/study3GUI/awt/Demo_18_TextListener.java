import java.awt.*;
import java.awt.event.*;

class Demo_18 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Label label3;
        private Panel panel;
        private TextField textField;

        public Demo_18(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_18 Demo_18 = new Demo_18();
                Demo_18.showTextListenerDemo();
          }

        private void prepareGUI(){

                frame = new Frame("Java AWT Examples");
                frame.setSize(400,400);
                frame.setLayout(new GridLayout(4, 1));

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
                label3 = new Label();
                label3.setAlignment(Label.CENTER);
                label3.setSize(350,100);
                panel = new Panel();
                panel.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);
                frame.add(label3);

                frame.setVisible(true);
          }
        private void showTextListenerDemo(){

                label1.setText("Listener in action: TextListener");

                textField = new TextField(10);
                textField.addTextListener(new CustomTextListener());

                Button okButton = new Button("OK");
                okButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {
                                label3.setText("Button text: "
                                                + textField.getText());
                              }
                    });

                panel.add(textField);
                panel.add(okButton);

                frame.setVisible(true);
          }

/*
interface: TextListener

1	void textValueChanged(TextEvent e) 
Invoked when the value of the text has changed.
*/
        class CustomTextListener implements TextListener {

                public void textValueChanged(TextEvent e) {

                        label2.setText("Entered text: " + textField.getText());
                    }
          }
}

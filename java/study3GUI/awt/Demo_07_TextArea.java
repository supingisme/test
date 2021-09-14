/*a##############################################################################
a###
a###             
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_07 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_07(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_07 Demo_07 = new Demo_07();
                Demo_07.showTextAreaDemo();
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
                //panel.setSize(200,200);

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);

                frame.setVisible(true);
          }

        private void showTextAreaDemo(){

                label1.setText("Control in action: TextArea");

                Label commentlabel= new Label("Comments: ", Label.RIGHT);

                final TextArea commentTextArea = new TextArea("This is a AWT tutorial "
                                                        +"to make GUI application in Java.",5,30);

                Button showButton = new Button("Show");

                showButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {

                                label2.setText( commentTextArea.getText());

                              }
                    });

                panel.add(commentlabel);
                panel.add(commentTextArea);
                panel.add(showButton);

                frame.setVisible(true);
          }
}

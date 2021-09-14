/*a##############################################################################
a###
a###             
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_08 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_08(){

                prepareGUI();
          }
        public static void main(String[] args){

                Demo_08 Demo_08 = new Demo_08();
                Demo_08.showChoiceDemo();
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
        private void showChoiceDemo(){

                label1.setText("Control in action: Choice");

                final Choice choice = new Choice();

                choice.add("choice1");
                choice.add("choice2");
                choice.add("choice3");
                choice.add("choice4");

                Button button = new Button("Show");

                button.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {

                                String data = "Choice Selected: "
                                        + choice.getItem(choice.getSelectedIndex());

                                label2.setText(data);
                              }
                    });

                panel.add(choice);
                panel.add(button);

                frame.setVisible(true);
          }
}

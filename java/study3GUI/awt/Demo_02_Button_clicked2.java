/*a##############################################################################
a###
a###             Button demo2
a###
a#################################################################################*/

import java.awt.*;
import java.awt.event.*;

class Demo_02 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_02(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_02 Demo_02 = new Demo_02();
                Demo_02.showEventDemo();
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
        private void showEventDemo(){

                label1.setText("Control in action: Button");

                Button button1 = new Button("button1");
                Button button2 = new Button("button2");
                Button button3 = new Button("button3");

                button1.setActionCommand("button1");
                button2.setActionCommand("button2");
                button3.setActionCommand("button3");

                button1.addActionListener(new ButtonClickListener());
                button2.addActionListener(new ButtonClickListener());
                button3.addActionListener(new ButtonClickListener());

                panel.add(button1);
                panel.add(button2);
                panel.add(button3);

                frame.setVisible(true);
          }
        private class ButtonClickListener implements ActionListener{

                public void actionPerformed(ActionEvent e) {

                        String command = e.getActionCommand();

                        if( command.equals( "button1" )) {

                                label2.setText("button1 Button clicked.");

                        }else if( command.equals( "button2" ) ) {

                                label2.setText("button2 Button clicked.");

                        }else {

                                label2.setText("button3 Button clicked.");
                              }
                    }
          }
}

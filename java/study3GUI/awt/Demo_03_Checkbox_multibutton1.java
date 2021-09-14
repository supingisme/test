/*a##############################################################################
a###
a###             CheckBox
a###
a#################################################################################*/

import java.awt.*;
import java.awt.event.*;

class Demo_03 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public boolean f1=false,f2=false,f3=false;

        public Demo_03(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_03 Demo_03 = new Demo_03();
                Demo_03.showCheckBoxDemo();
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
        private void showCheckBoxDemo(){

                label1.setText("Control in action: CheckBox");

                Checkbox checkbox1 = new Checkbox("定义checkbox1");
                Checkbox checkbox2 = new Checkbox("定义checkbox2");
                Checkbox checkbox3 = new Checkbox("定义checkbox3");

                checkbox1.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f1 = !f1;

                                label2.setText("checkbox1:"
                                        + (e.getStateChange()==1?"checked":"unchecked"));

                                System.out.println("checkbox1:"+f1);
                              }
                    });

                checkbox2.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f2 = !f2;

                                label2.setText("checkbox2: "
                                        + (e.getStateChange()==1?"checked":"unchecked"));

                                System.out.println("checkbox2:"+f2);
                              }
                    });

                checkbox3.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f3 = !f3;

                                label2.setText("checkbox3: "
                                        + (e.getStateChange()==1?"checked":"unchecked"));

                                System.out.println("checkbox3:"+f3);
                              }
                    });

                panel.add(checkbox1);
                panel.add(checkbox2);
                panel.add(checkbox3);

                frame.setVisible(true);
          }
}

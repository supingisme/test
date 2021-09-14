/*a##############################################################################
a###
a###             CheckBoxGroup
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_04 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public boolean f1=false, f2=false,f3=false;

        public Demo_04(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_04 Demo_04 = new Demo_04();
                Demo_04.showCheckBoxGroupDemo();
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

        private void showCheckBoxGroupDemo(){

                label1.setText("Control in action: CheckBoxGroup");

                CheckboxGroup group = new CheckboxGroup();
                Checkbox checkbox1 = new Checkbox("checkbox1",group,true);
                Checkbox checkbox2 = new Checkbox("checkbox2",group,false);
                Checkbox checkbox3 = new Checkbox("checkbox3",group,false);

                label2.setText("checkbox1: checked");

                checkbox1.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f1=true;f2=false;f3=false;

                                label2.setText("checkbox1: checked");

                                System.out.println("checkbox1: "+f1
                                                  +",  checkbox2: " +f2
                                                  +",  checkbox3: "+f3);
                              }
                    });

                checkbox2.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f1=false;f2=true;f3=false;

                                label2.setText("checkbox2: checked");

                                System.out.println("checkbox1: "+f1
                                                  +",  checkbox2: "+f2
                                                  +",  checkbox3: "+f3);
                              }
                    });

                checkbox3.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {

                                f1=false;f2=false;f3=true;

                                label2.setText("checkbox3: checked");

                                System.out.println("checkbox1: "+f1
                                                  +",  checkbox2: "+f2
                                                  +",  checkbox3: "+f3);
                              }
                     });

                panel.add(checkbox1);
                panel.add(checkbox2);
                panel.add(checkbox3);
                frame.setVisible(true);
          }
}

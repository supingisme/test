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

        private boolean cb1 = false, cb2 = false, cb3 = false;

        public Demo_03(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_03 Demo_03 = new Demo_03();
                Demo_03.showItemListenerDemo();
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
        private void showItemListenerDemo(){

                label1.setText("Listener in action: ItemListener");

                Checkbox checkbox1 = new Checkbox("checkbox1");
                Checkbox checkbox2 = new Checkbox("checkbox2");
                Checkbox checkbox3 = new Checkbox("checkbox3");

                checkbox1.addItemListener(new CustomItemListener());
                checkbox2.addItemListener(new CustomItemListener());
                checkbox3.addItemListener(new CustomItemListener());

                panel.add(checkbox1);
                panel.add(checkbox2);
                panel.add(checkbox3);

                frame.setVisible(true);
          }
        class CustomItemListener implements ItemListener {

                public void itemStateChanged(ItemEvent e) {

                        if(e.getItem()=="checkbox1") cb1=!cb1;
                        if(e.getItem()=="checkbox2") cb2=!cb2;
                        if(e.getItem()=="checkbox3") cb3=!cb3;

                        System.out.println("checkbox1: "+cb1+", checkbox2: "+cb2+", checkbox3: "+cb3);

                        label2.setText(e.getItem()
                                        +" Checkbox: "
                                        + (e.getStateChange()==1?"checked":"unchecked"));
                    }
          }
}


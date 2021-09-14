/*a##############################################################################
a###
a###             List
a###
a#################################################################################*/
import java.awt.*;
import java.awt.event.*;

class Demo_05 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public boolean fa=false,fb=false,fc=false,fd=false;
        public boolean fe=false,ff=false,fg=false,fh=false;

        public Demo_05(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_05 Demo_05 = new Demo_05();
                Demo_05.showListDemo();
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

        private void showListDemo(){

                label1.setText("Control in action: List");

                final List list1 = new List(4,false);

                list1.add("A");
                list1.add("B");
                list1.add("C");
                list1.add("D");

                final List list2 = new List(4,true);

                list2.add("E");
                list2.add("F");
                list2.add("G");
                list2.add("H");

                Button showButton = new Button("Show");

                showButton.addActionListener(new ActionListener() {
                        public void actionPerformed(ActionEvent e) {


                                if(list1.getItem(list1.getSelectedIndex())=="A"){
                                        fa=true;fb=false;fc=false;fd=false;
                                }else if(list1.getItem(list1.getSelectedIndex())=="B"){
                                        fa=false;fb=true;fc=false;fd=false;
                                }else if(list1.getItem(list1.getSelectedIndex())=="C"){
                                        fa=false;fb=false;fc=true;fd=false;
                                }else if(list1.getItem(list1.getSelectedIndex())=="D"){
                                        fa=false;fb=false;fc=false;fd=true;
                                        }


                                fe=false;ff=false;fg=false;fh=false;
                                for(String efgh:list2.getSelectedItems()){
                                        if(efgh=="E")fe=true;
                                        if(efgh=="F")ff=true;
                                        if(efgh=="G")fg=true;
                                        if(efgh=="H")fh=true;
                                        }

                                System.out.print("a: "+fa
                                                  +", b: "+fb
                                                  +", c: "+fc
                                                  +", d: "+fd);
                                System.out.println(", e: "+fe
                                                  +", f: "+ff
                                                  +", g: "+fg
                                                  +", h: "+fh);

                                String data = "ABCD Selected: "
                                        + list1.getItem(list1.getSelectedIndex());

                                data += ", EFGH selected: ";

                                for(String efgh:list2.getSelectedItems()){
                                        data += efgh + " ";
                                        }

                                label2.setText(data);

                               }
                    });

                panel.add(list1);
                panel.add(list2);

                panel.add(showButton);

                frame.setVisible(true);
          }
}

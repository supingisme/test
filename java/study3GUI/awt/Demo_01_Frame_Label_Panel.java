/*a##############################################################################
a###
a###             Frame, Label, Panel
a###
a#################################################################################*/

import java.awt.*;
import java.awt.event.*;
/*
setLayout
​函数声明格式:public void setLayout(LayoutManager manager)
常用的有5种:FlowLayout、BorderLayout、GridLayout、CardLayout、GridBagLayout。
一般来说都要放在构造函数或初始化函数中，设置后再加入控件。


gridlayout
GridLayout所切割出来的版面就如同表格一般整齐，加入的组件会按顺序由左至右、由上至下摆放，所以无法直接指定要摆放的区域。
除此之外，组件放入后会变成方形，所以不适合放入JButton这类组件中，而比较适合加入JPanel。

*/
class Demo_01{

        private Frame frame;
        private Label label1;
        private Label label2;
        private Label label3;
        private Label label4;
        private Label label5;
        private Panel panel;

        public Demo_01(){
        
                prepareGUI();
          }

        private void prepareGUI(){

                frame = new Frame("Java AWT");
                frame.setSize(300,300);
                //frame.setLayout(new GridLayout(2,3));
                frame.setLayout(new GridLayout(2,3,30,30));
                //frame.setLayout(new CardLayout(2,3));
                //frame.setLayout(new BorderLayout(2,3));

                frame.addWindowListener(new WindowAdapter(){
                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                              }
                    });

                label1 = new Label();
                label1.setText("label1");
                label1.setAlignment(Label.CENTER);
                label1.setBackground(Color.GRAY);
                label1.setSize(100,100);

                label2 = new Label();
                label2.setText("label2");
                label2.setAlignment(Label.CENTER);
                label2.setBackground(Color.GREEN);
                label2.setSize(100,100);

                label3 = new Label();
                label3.setText("label3");
                label3.setAlignment(Label.CENTER);
                label3.setBackground(Color.RED);
                label3.setSize(100,100);

                label4 = new Label();
                label4.setText("label4");
                label4.setAlignment(Label.CENTER);
                label4.setBackground(Color.BLUE);
                label4.setSize(100,100);

                label5 = new Label();
                label5.setText("label5");
                label5.setAlignment(Label.CENTER);
                label5.setBackground(Color.YELLOW);
                label5.setSize(100,100);

                panel = new Panel();
                panel.setLayout(new FlowLayout());


                frame.add(panel);
                frame.add(label1);      
                frame.add(label2);
                frame.add(label3);
                frame.add(label4);
                frame.add(label5);

                frame.setVisible(true);
          }

        private void showLabelDemo(){
                
                Label l = new Label();

                l.setText("showLabelDemo");
                l.setAlignment(Label.CENTER);
                l.setBackground(Color.GRAY);
                l.setForeground(Color.RED);

                panel.add(l);

                //panel.setVisible(false);
          }

        public static void  main(String[]args){

                Demo_01 demo = new Demo_01();

                demo.showLabelDemo();
          }

}

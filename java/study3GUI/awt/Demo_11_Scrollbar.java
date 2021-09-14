import java.awt.*;
import java.awt.event.*;

class Demo_11 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        private int a,b;

        public Demo_11(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_11 Demo_11 = new Demo_11();
                Demo_11.showScrollbarDemo();
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
        private void showScrollbarDemo(){

                label1.setText("Control in action: Scrollbar");

                final Scrollbar hScroller = new Scrollbar(Scrollbar.HORIZONTAL);
                final Scrollbar vScroller = new Scrollbar();

                vScroller.setOrientation(Scrollbar.VERTICAL);

                hScroller.setMaximum (20);
                hScroller.setMinimum (1);

                vScroller.setMaximum (20);
                vScroller.setMinimum (1);

                hScroller.addAdjustmentListener(new AdjustmentListener() {

/*
@Override
  帮助自己检查是否正确的复写了父类中已有的方法
  告诉读代码的人，这是一个复写的方法
*/
                        @Override
                        public void adjustmentValueChanged(AdjustmentEvent e) {
                                label2.setText("Horozontal: "
                                                +hScroller.getValue()
                                                +" ,Vertical: "
                                                + vScroller.getValue());

                                a=hScroller.getValue();
                                b=vScroller.getValue();
                                System.out.println("h = "+a+", v = "+b);
                              }
                    });

                vScroller.addAdjustmentListener(new AdjustmentListener() {

                        @Override
                        public void adjustmentValueChanged(AdjustmentEvent e) {
                                label2.setText("Horozontal: "
                                                +hScroller.getValue()
                                                +" ,Vertical: "+ vScroller.getValue());

                                a=hScroller.getValue();
                                b=vScroller.getValue();
                                System.out.println("h = "+a+", v = "+b);

                              }
                    });

                panel.add(hScroller);
                panel.add(vScroller);

                frame.setVisible(true);
          }
}

import java.awt.*;
import java.awt.event.*;

class Demo_20 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panela;

        public Demo_20(){

                prepareGUI();
          }
        public static void main(String[] args){

                Demo_20 Demo_20 = new Demo_20();
                Demo_20.showAdjustmentListenerDemo();
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
                panela = new Panel();
                panela.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panela);
                frame.add(label2);

                frame.setVisible(true);
          }
        private void showAdjustmentListenerDemo(){

                label1.setText("Listener in action: AdjustmentListener");

                ScrollPane panel1 = new ScrollPane();
                panel1.setBackground(Color.magenta);
                panel1.getHAdjustable().addAdjustmentListener(new CustomAdjustmentListener());

                ScrollPane panel2 = new ScrollPane();
                panel2.setBackground(Color.magenta);
                panel2.addContainerListener(new CustomContainerListener());


                Label msglabel1 = new Label();
                msglabel1.setAlignment(Label.CENTER);
                msglabel1.setText("AWT11111111111111111111111111");

                Label msglabel2 = new Label();
                msglabel2.setAlignment(Label.CENTER);
                msglabel2.setText("AWT22222222222222222222222222");

                panel1.add(msglabel1);
                panel2.add(msglabel2);

                panela.add(panel1);
                panela.add(panel2);

                frame.setVisible(true);
          }
/*
interface: AdjustmentLisenter

1	void adjustmentValueChanged(AdjustmentEvent e) 
Invoked when the value of the adjustable has changed.
*/
        class CustomAdjustmentListener implements AdjustmentListener {

                public void adjustmentValueChanged(AdjustmentEvent e) {

                        label2.setText(label2.getText()
                                        +Integer.toString(e.getValue()));
                    }
          }

/*
interface: ContainerListener

1	void componentAdded(ContainerEvent e) 
Invoked when a component has been added to the container.
2	void componentRemoved(ContainerEvent e) 
Invoked when a component has been removed from the container.
*/
        class CustomContainerListener implements ContainerListener {
                public void componentAdded(ContainerEvent e) {
                        label2.setText(label2.getText()
                                        + e.getComponent().getClass().getSimpleName() + " added. ");
                    }
                public void componentRemoved(ContainerEvent e) {
                        label2.setText(label2.getText()
                                        + e.getComponent().getClass().getSimpleName() + " removed. ");
                    }
          }


}




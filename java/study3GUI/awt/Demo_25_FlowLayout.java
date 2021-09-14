import java.awt.*;
import java.awt.event.*;
/*

*/
class Demo_25 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;
        private Label msglabel;

        public Demo_25(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_25 Demo_25 = new Demo_25();
                Demo_25.showFlowLayoutDemo();
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

                msglabel = new Label();
                msglabel.setAlignment(Label.CENTER);
                msglabel.setText("Welcome to TutorialsPoint AWT Tutorial.");

                panel0 = new Panel();
                panel0.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel0);
                frame.add(label2);

                frame.setVisible(true);
          }
        private void showFlowLayoutDemo(){

                label1.setText("Layout in action: FlowLayout");

                Panel panel = new Panel();
                panel.setBackground(Color.gray);
                panel.setSize(200,200);

                FlowLayout layout = new FlowLayout();
                layout.setHgap(10);
                layout.setVgap(10);

                panel.setLayout(layout);

                panel.add(new Button("OK"));
                panel.add(new Button("Cancel"));

                panel0.add(panel);

                frame.setVisible(true);
          }
}

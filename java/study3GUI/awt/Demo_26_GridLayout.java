import java.awt.*;
import java.awt.event.*;
/*

*/
class Demo_26 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;
        private Label msglabel;

        public Demo_26(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_26 Demo_26 = new Demo_26();
                Demo_26.showGridLayoutDemo();
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
        private void showGridLayoutDemo(){

                label1.setText("Layout in action: FlowLayout");

                Panel panel = new Panel();
                panel.setBackground(Color.gray);
                panel.setSize(200,200);

                GridLayout layout = new GridLayout(6,3);
                layout.setHgap(6);
                layout.setVgap(6);

                panel.setLayout(layout);

                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));
                panel.add(new Button("a"));


                panel0.add(panel);

                frame.setVisible(true);
          }
}

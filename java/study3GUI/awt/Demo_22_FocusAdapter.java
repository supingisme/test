import java.awt.*;
import java.awt.event.*;
class Demo_22 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;

        private Button okButton;
        private Button cancelButton;

        public Demo_22(){

                prepareGUI();
          }
        public static void main(String[] args){

                Demo_22 Demo_22 = new Demo_22();
                Demo_22.showFocusAdapterDemo();
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

                //frame.addFocusListener(new CustomFocusListener());

                label1 = new Label();
                label1.setAlignment(Label.CENTER);
                //label1.addFocusListener(new CustomFocusListener());
                label2 = new Label();
                label2.setAlignment(Label.CENTER);
                label2.setSize(350,100);
                //label2.addFocusListener(new CustomFocusListener());

                panel0 = new Panel();
                panel0.setLayout(new FlowLayout());
                //panel0.addFocusListener(new CustomFocusListener());

                frame.add(label1);
                frame.add(panel0);
                frame.add(label2);

                frame.setVisible(true);
          }

        private void showFocusAdapterDemo(){

                label1.setText("Listener in action: FocusListener");

                okButton = new Button("OK");
                cancelButton = new Button("Cancel");

                okButton.addFocusListener(new FocusAdapter(){
                        public void focusGained(FocusEvent e) {
                                label2.setText(label2.getText()
                                        + e.getComponent().getClass().getSimpleName()
                                        + " gained focus. ");
                              }
                    });
                cancelButton.addFocusListener(new FocusAdapter(){
                        public void focusLost(FocusEvent e) {
                                label2.setText(label2.getText()
                                        + e.getComponent().getClass().getSimpleName()
                                        + " lost focus. ");
                              }
                    });


                panel0.add(okButton);
                panel0.add(cancelButton);


                frame.setVisible(true);
          }

}

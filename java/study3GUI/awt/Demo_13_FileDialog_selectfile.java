import java.awt.*;
import java.awt.event.*;

class Demo_13 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_13(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_13 Demo_13 = new Demo_13();
                Demo_13.showFileDialogDemo();
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

        private void showFileDialogDemo(){

                label1.setText("Control in action: FileDialog");

                final FileDialog fileDialog = new FileDialog(frame,"Select file");

                Button button = new Button("Open File");

                button.addActionListener(new ActionListener() {

                        @Override
                        public void actionPerformed(ActionEvent e) {

                                fileDialog.setVisible(true);

                                label2.setText("File Selected :"
                                        + fileDialog.getDirectory() + fileDialog.getFile());

                              }
                    });

                panel.add(button);

                frame.setVisible(true);
          }
}

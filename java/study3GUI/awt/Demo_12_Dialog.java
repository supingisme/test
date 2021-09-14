import java.awt.*;
import java.awt.event.*;

class Demo_12 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_12(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_12 Demo_12 = new Demo_12();
                Demo_12.showDialogDemo();
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
        private void showDialogDemo(){

                label1.setText("Control in action: Dialog");

                Button showAboutDialogButton = new Button("Show About Dialog");

                showAboutDialogButton.addActionListener(new ActionListener() {

                        @Override
                        public void actionPerformed(ActionEvent e) {

                                AboutDialog aboutDialog = new AboutDialog(frame);
                                aboutDialog.setVisible(true);
                              }
                    });

                panel.add(showAboutDialogButton);

                frame.setVisible(true);
          }
        class AboutDialog extends Dialog {

                public AboutDialog(Frame parent){
/*
http://www.yiibai.com/html/awt/awt_dialog.html

Dialog(Dialog owner) ;
Dialog(Dialog owner, String title) ;
Dialog(Dialog owner, String title, boolean modal) ;
Dialog(Dialog owner, String title, boolean modal, GraphicsConfiguration gc) ;
Dialog(Frame owner) ;
Dialog(Frame owner, boolean modal) ;
Dialog(Frame owner, String title) ;
Dialog(Frame owner, String title, boolean modal) ;
Dialog(Frame owner, String title, boolean modal, GraphicsConfiguration gc) ;
Dialog(Window owner) ;
Dialog(Window owner, Dialog.ModalityType modalityType) ;
Dialog(Window owner, String title) ;
Dialog(Window owner, String title, Dialog.ModalityType modalityType) ;
Dialog(Window owner, String title, Dialog.ModalityType modalityType, GraphicsConfiguration gc) ;
*/
                        super(parent, "mydialog",true);

                        setBackground(Color.gray);
                        setLayout(new BorderLayout());

                        Panel panel = new Panel();
                        panel.add(new Button("Close"));

                        add("South", panel);
                        setSize(200,200);


                        Button button1 = new Button("close");

                        button1.addActionListener(new ActionListener() {

                                @Override
                                public void actionPerformed(ActionEvent e) {

                                        dispose();
                                        }
                              });

                        add(button1);

                        //setVisible(true);

                        addWindowListener(new WindowAdapter() {
                                public void windowClosing(WindowEvent windowEvent){
                                        dispose();
                                        }
                              });

                    }
/*
-bash-4.1$ javac Demo_12_Dialog.java
注: Demo_12_Dialog.java使用或覆盖了已过时的 API。
注: 有关详细信息, 请使用 -Xlint:deprecation 重新编译。
           Object arg  ->    String arg
*/
             /*   public boolean action(Event evt, Object arg){

                        if(arg.equals("Close")){

                                dispose();
                                return true;
                              }
                        return false;
                    } */

                public void paint(Graphics g){

                        g.setColor(Color.white);

                        g.drawString("TutorialsPoint.Com", 25,70 );
                        g.drawString("Version 1.0", 60, 90);

                    }
          }
}

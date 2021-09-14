import java.awt.*;
import java.awt.event.*;

class Demo_29 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_29(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_29 Demo_29 = new Demo_29();
                Demo_29.showPopupMenuDemo();
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
                label1.setText("label1");
                label2 = new Label();
                label2.setAlignment(Label.CENTER);
                label2.setSize(350,100);
                label2.setText("label2");
                panel = new Panel();
                panel.setLayout(new FlowLayout());

                frame.add(label1);
                frame.add(panel);
                frame.add(label2);
                frame.setVisible(true);
          }

        private void showPopupMenuDemo(){


                final PopupMenu editMenu = new PopupMenu("Edit");

                MenuItem cutMenuItem = new MenuItem("Cut");
                cutMenuItem.setActionCommand("Cut");

                MenuItem copyMenuItem = new MenuItem("Copy");
                copyMenuItem.setActionCommand("Copy");

                MenuItem pasteMenuItem = new MenuItem("Paste");
                pasteMenuItem.setActionCommand("Paste");

                MenuItemListener menuItemListener = new MenuItemListener();

                cutMenuItem.addActionListener(menuItemListener);
                copyMenuItem.addActionListener(menuItemListener);
                pasteMenuItem.addActionListener(menuItemListener);

                editMenu.add(cutMenuItem);
                editMenu.add(copyMenuItem);
                editMenu.add(pasteMenuItem);

                panel.addMouseListener(new MouseAdapter() {
                        public void mouseClicked(MouseEvent e) {
                                editMenu.show(panel, e.getX(), e.getY());
                              }
                    });

                panel.add(editMenu);


                frame.setVisible(true);
          }
        class MenuItemListener implements ActionListener {
                public void actionPerformed(ActionEvent e) {
                        label2.setText(e.getActionCommand()
                                + " MenuItem clicked.");
                    }
          }
}

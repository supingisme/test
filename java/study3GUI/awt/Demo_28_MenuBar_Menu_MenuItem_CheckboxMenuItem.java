import java.awt.*;
import java.awt.event.*;

class Demo_28 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_28(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_28 Demo_28 = new Demo_28();
                Demo_28.showMenuDemo();
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

        private void showMenuDemo(){

                //create a menu bar
                final MenuBar menuBar = new MenuBar();

                //create menus
                Menu fileMenu = new Menu("File");
                Menu editMenu = new Menu("Edit");

                final Menu aboutMenu = new Menu("About");

                //create menu items
                //MenuItem newMenuItem = new MenuItem("New");
                MenuItem newMenuItem = new MenuItem("New",new MenuShortcut(KeyEvent.VK_N));
                newMenuItem.setActionCommand("New");

                MenuItem openMenuItem = new MenuItem("Open",new MenuShortcut(KeyEvent.VK_O));
                openMenuItem.setActionCommand("Open");

                MenuItem saveMenuItem = new MenuItem("Save",new MenuShortcut(KeyEvent.VK_S));
                saveMenuItem.setActionCommand("Save");

                MenuItem exitMenuItem = new MenuItem("Exit");
                exitMenuItem.setActionCommand("Exit");

                MenuItem cutMenuItem = new MenuItem("Cut");
                cutMenuItem.setActionCommand("Cut");

                MenuItem copyMenuItem = new MenuItem("Copy");
                copyMenuItem.setActionCommand("Copy");

                MenuItem pasteMenuItem = new MenuItem("Paste");
                pasteMenuItem.setActionCommand("Paste");

                MenuItemListener menuItemListener = new MenuItemListener();
                newMenuItem.addActionListener(menuItemListener);
                //openMenuItem.addActionListener(menuItemListener);
                final FileDialog fileDialog = new FileDialog(frame,"Select file");
                openMenuItem.addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent e) {

                                fileDialog.setVisible(true);

                                System.out.println("File Selected :"
                                        + fileDialog.getDirectory() + fileDialog.getFile());

                              }
                    });

                saveMenuItem.addActionListener(menuItemListener);

                //exitMenuItem.addActionListener(menuItemListener);
                exitMenuItem.addActionListener(new ActionListener(){
                        public void actionPerformed(ActionEvent e) {

                                System.exit(0);

                              }
                    });
                cutMenuItem.addActionListener(menuItemListener);
                copyMenuItem.addActionListener(menuItemListener);
                pasteMenuItem.addActionListener(menuItemListener);

                final CheckboxMenuItem showWindowMenu = new CheckboxMenuItem("Show About", true);
                showWindowMenu.addItemListener(new ItemListener() {
                        public void itemStateChanged(ItemEvent e) {
                                if(showWindowMenu.getState()){
                                        menuBar.add(aboutMenu);
                                }else{
                                        menuBar.remove(aboutMenu);
                                        }
                            }
                    });
                //add menu items to menus
                fileMenu.add(newMenuItem);
                fileMenu.add(openMenuItem);
                fileMenu.add(saveMenuItem);
                fileMenu.addSeparator();
                fileMenu.add(showWindowMenu);
                fileMenu.addSeparator();
                fileMenu.add(exitMenuItem);

                editMenu.add(cutMenuItem);
                editMenu.add(copyMenuItem);
                editMenu.add(pasteMenuItem);

                //add menu to menubar
                menuBar.add(fileMenu);
                menuBar.add(editMenu);
                menuBar.add(aboutMenu);

                //add menubar to the frame
                frame.setMenuBar(menuBar);

                frame.setVisible(true);
          }
        class MenuItemListener implements ActionListener {
                public void actionPerformed(ActionEvent e) {
                        label2.setText(e.getActionCommand()
                                + " MenuItem clicked.");
                    }
          }
}

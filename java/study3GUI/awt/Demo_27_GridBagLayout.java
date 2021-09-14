import java.awt.*;
import java.awt.event.*;
/*
GridBagLayout 类组件排列在一个水平和垂直的方式。
http://www.yiibai.com/html/awt/awt_gridbaglayout.html

GridBagLayout()
Creates a grid bag layout manager.
*/
class Demo_27 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;
        private Label msglabel;

        public Demo_27(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_27 Demo_27 = new Demo_27();
                Demo_27.showGridBagLayoutDemo();
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
        private void showGridBagLayoutDemo(){

                label1.setText("Layout in action: GridBagLayout");

                Panel panel = new Panel();
                panel.setBackground(Color.gray);
                panel.setSize(200,200);

                GridBagLayout layout = new GridBagLayout();

                panel.setLayout(layout);

                GridBagConstraints gbc = new GridBagConstraints();/*约束*/

                //gbc.fill = GridBagConstraints.VERTICAL;
                gbc.gridx = 5;
                gbc.gridy = 5;
                panel.add(new Button("Button 1"),gbc);
                gbc.gridx = 2;
                gbc.gridy = 2;
                panel.add(new Button("Button 2"),gbc);

                //gbc.fill = GridBagConstraints.VERTICAL;
                gbc.ipady = 20;//按钮逐渐变宽
                gbc.gridx = 1;
                gbc.gridy = 1;
                panel.add(new Button("Button 3"),gbc);
                gbc.gridx = 3;
                gbc.gridy = 3;
                panel.add(new Button("Button 4"),gbc);
                gbc.gridx = 4;
                gbc.gridy = 4;
                //gbc.fill = GridBagConstraints.VERTICAL;
                //gbc.gridwidth = 2;
                panel.add(new Button("Button 5"),gbc);
                gbc.gridx = 6;
                gbc.gridy = 6;
                //gbc.fill = GridBagConstraints.VERTICAL;
                //gbc.gridwidth = 2;
                panel.add(new TextField(10),gbc);



                panel0.add(panel);

                frame.setVisible(true);
          }
}

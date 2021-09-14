import java.awt.*;
import java.awt.event.*;
/*
CardLayout类排列一张牌的容器中的每个组件。只有一张卡是可见的时间，与容器作为将整叠卡片。
http://www.yiibai.com/html/awt/awt_cardlayout.html

1	CardLayout() 
Creates a new card layout with gaps of size zero.
2	CardLayout(int hgap, int vgap) 
Creates a new card layout with the specified horizontal and vertical gaps.
*/
class Demo_24 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;
        private Label msglabel;

        public Demo_24(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_24 Demo_24 = new Demo_24();
                Demo_24.showCardLayoutDemo();
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
        private void showCardLayoutDemo(){

                label1.setText("Layout in action: BorderLayout");
/*
从内部类中访问本地变量panel; 需要被声明为最终类型
*/
                final Panel panel = new Panel();
                panel.setBackground(Color.gray);
                panel.setSize(300,300);

                CardLayout layout = new CardLayout();
                layout.setHgap(20);
                layout.setVgap(20);

                panel.setLayout(layout);


                Panel buttonPanel = new Panel(new FlowLayout());
                buttonPanel.add(new Button("OK"));
                buttonPanel.add(new Button("Cancel"));

                Panel textBoxPanel = new Panel(new FlowLayout());
                textBoxPanel.add(new Label("Name:"));
                textBoxPanel.add(new TextField(20));

                panel.add("Button", buttonPanel);
                panel.add("Text", textBoxPanel);

                Choice choice = new Choice();
                choice.add("Button");
                choice.add("Text");

                choice.addItemListener(new ItemListener() {

                        public void itemStateChanged(ItemEvent e) {

                                CardLayout cardLayout = (CardLayout)(panel.getLayout());
                                        /*
                                void show(Container parent, String name) 
                                Flips to the component that was added to this layout with 
                                        the specified name, using addLayoutComponent.
                                        */
                                cardLayout.show(panel, (String)e.getItem());
                              }
                    });

                panel0.add(choice);
                panel0.add(panel);

                frame.setVisible(true);

          }
}

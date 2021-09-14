import java.awt.*;
import java.awt.event.*;
/*
BorderLayout类排列的组成部分，以适应在五个区域：东部，西部，北部，南部和中心。
每个区域只能包含一个组件，每个组件在每个区域确定相应的固定 NORTH, SOUTH, EAST, WEST和CENTER.

下面是java.awt.BorderLayout类的字段：
static String AFTER_LAST_LINE -- Synonym for PAGE_END.
static String AFTER_LINE_ENDS -- Synonym for LINE_END.
static String BEFORE_FIRST_LINE -- Synonym for PAGE_START.
static String BEFORE_LINE_BEGINS -- Synonym for LINE_START.
static String CENTER -- The center layout constraint (middle of container).
static String EAST -- The east layout constraint (right side of container).
static String LINE_END -- The component goes at the end of the line direction for the layout.
static String LINE_START -- The component goes at the beginning of the line direction for the layout.
static String NORTH -- The north layout constraint (top of container).
static String PAGE_END -- The component comes after the last line of the layout's content.
static String PAGE_START -- The component comes before the first line of the layout's content.
static String SOUTH -- The south layout constraint (bottom of container).
static String WEST -- The west layout constraint (left side of container).
*/
class Demo_23 {
        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel0;
        private Label msglabel;

        public Demo_23(){

                prepareGUI();
          }

        public static void main(String[] args){

                Demo_23 Demo_23 = new Demo_23();
                Demo_23.showBorderLayoutDemo();
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
        private void showBorderLayoutDemo(){

                label1.setText("Layout in action: BorderLayout");

                Panel panel = new Panel();
                panel.setBackground(Color.gray);
                panel.setSize(300,300);

                BorderLayout layout = new BorderLayout();
                layout.setHgap(20);
                layout.setVgap(20);

                panel.setLayout(layout);


                panel.add(new Button("AFTER_LAST_LINE"),BorderLayout.AFTER_LAST_LINE);
                panel.add(new Button("AFTER_LINE_ENDS"),BorderLayout.AFTER_LINE_ENDS);
                panel.add(new Button("BEFORE_FIRST_LINE"),BorderLayout.BEFORE_FIRST_LINE);
                panel.add(new Button("BEFORE_LINE_BEGINS"),BorderLayout.BEFORE_LINE_BEGINS);
                //panel.add(new Button("PAGE_END"),BorderLayout.PAGE_END);
                //panel.add(new Button("PAGE_START"),BorderLayout.PAGE_START);
                //panel.add(new Button("Center"),BorderLayout.CENTER);
                panel.add(new Button("Line Start"),BorderLayout.LINE_START);
                panel.add(new Button("Line End"),BorderLayout.LINE_END);
                //panel.add(new Button("East"),BorderLayout.EAST);
                //panel.add(new Button("West"),BorderLayout.WEST);
                //panel.add(new Button("North"),BorderLayout.NORTH);
                //panel.add(new Button("South"),BorderLayout.SOUTH);

                panel0.add(panel);

                frame.setVisible(true);
          }
}

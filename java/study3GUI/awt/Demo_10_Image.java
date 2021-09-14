import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;

class Demo_10 {

        private Frame frame;
        private Label label1;
        private Label label2;
        private Panel panel;

        public Demo_10(){

                prepareGUI();
          }
        public static void main(String[] args){

                Demo_10 Demo_10 = new Demo_10();
                Demo_10.showImageDemo();
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
        private void showImageDemo(){

                label1.setText("Control in action: Image");

                panel.add(new ImageComponent("java.jpg"));

                frame.setVisible(true);
          }
        class ImageComponent extends Component {

                BufferedImage img;

                public void paint(Graphics g) {

                        g.drawImage(img, 0, 0, null);
                    }

                public ImageComponent(String path) {

                        try {
                                img = ImageIO.read(new File(path));
                        } catch (IOException e) {
/*
System.out.println(e)，这个方法打印出异常，并且输出在哪里出现的异常，
不过它和另外一个e.printStackTrace()方法不同。后者也是打印出异常，但是它还将显示出更深的调用信息。
*/
                                e.printStackTrace();
                              }
                    }

                public Dimension getPreferredSize() {

                        if (img == null) {
                                return new Dimension(100,100);
                        } else {
                                return new Dimension(img.getWidth(), img.getHeight());
                              }
                    }
          }
}

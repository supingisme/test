import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

class Demo_31 extends Frame {

        public Demo_31(){

                super("Java AWT Examples");
                prepareGUI();
          }
        public static void main(String[] args){

                Demo_31 Demo_31 = new Demo_31();
                Demo_31.setVisible(true);
          }
        private void prepareGUI(){

                setSize(400,400);
                addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                              }
                    });
          }

        @Override
        public void paint(Graphics g) {

                /*#####  Graphics2D  #####*/
         /*       Graphics2D g2 = (Graphics2D)g;
                g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g2.drawString("Welcome to TutorialsPoint", 50, 70); */


                /*#####  Arc2D  #####*/
         /*       Arc2D.Float arc = new Arc2D.Float(Arc2D.PIE);
                arc.setFrame(70, 200, 150, 150);
                arc.setAngleStart(0);
                arc.setAngleExtent(145);
                Graphics2D g2 = (Graphics2D) g;
                g2.setColor(Color.gray);
                g2.draw(arc);
                g2.setColor(Color.red);
                g2.fill(arc);
                g2.setColor(Color.black);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("Arc2D.PIE", 100, 120);    */


                /*#####  Arc2D  #####*/
           /*     CubicCurve2D shape = new CubicCurve2D.Float();
                shape.setCurve(250F,250F,20F,90F,140F,100F,350F,330F);
                Graphics2D g2 = (Graphics2D) g;
                g2.draw (shape);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("CubicCurve2D.Curve", 100, 120);    */


                /*##### Ellipse2D  #####*/
           /*     Ellipse2D shape = new Ellipse2D.Float();
                shape.setFrame(100, 150, 200,100);
                Graphics2D g2 = (Graphics2D) g;
                g2.draw (shape);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("Ellipse2D.Oval", 100, 120);      */


                /*##### Rectangle2D  #####*/
            /*    Rectangle2D shape = new Rectangle2D.Float();
                shape.setFrame(100, 150, 200,100);
                Graphics2D g2 = (Graphics2D) g;
                g2.draw (shape);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("Rectangle2D.Rectangle", 100, 120);        */


                /*##### QuadCurve2D  #####*/
           /*     QuadCurve2D shape = new QuadCurve2D.Double();
                shape.setCurve(250D,250D,100D,100D,200D,150D);
                Graphics2D g2 = (Graphics2D) g;
                g2.draw (shape);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("QuadCurve2D.Curve", 100, 120);   */


                /*##### Line2D  #####*/
                Line2D shape = new Line2D.Double();
                shape.setLine(250D,250D,150D,150D);
                Graphics2D g2 = (Graphics2D) g;
                g2.draw (shape);
                Font font = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(font);
                g.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.drawString("Line2D.Line", 100, 120);
          }

}

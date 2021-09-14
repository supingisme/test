/*
Font

 static int BOLD -- The bold style constant.
 static int CENTER_BASELINE --The baseline used in ideographic scripts like Chinese, Japanese, and Korean when laying out text.
 static String DIALOG --A String constant for the canonical family name of the logical font "Dialog".
 static String DIALOG_INPUT --A String constant for the canonical family name of the logical font "DialogInput".
 static int HANGING_BASELINE -- The baseline used in Devanigiri and similar scripts when laying out text.
 static int ITALIC -- The italicized style constant.
 static int LAYOUT_LEFT_TO_RIGHT -- A flag to layoutGlyphVector indicating that text is left-to-right as determined by Bidi analysis.
 static int LAYOUT_NO_LIMIT_CONTEXT -- A flag to layoutGlyphVector indicating that text in the char array after the indicated limit should not be examined.
 static int LAYOUT_NO_START_CONTEXT -- A flag to layoutGlyphVector indicating that text in the char array before the indicated start should not be examined.
 static int LAYOUT_RIGHT_TO_LEFT -- A flag to layoutGlyphVector indicating that text is right-to-left as determined by Bidi analysis.
 static String MONOSPACED -- A String constant for the canonical family name of the logical font "Monospaced".
 protected String name -- The logical name of this Font, as passed to the constructor.
 static int PLAIN --The plain style constant.
 protected float pointSize -- The point size of this Font in float.
 static int ROMAN_BASELINE --The baseline used in most Roman scripts when laying out text.
 static String SANS_SERIF -- A String constant for the canonical family name of the logical font "SansSerif".
 static String SERIF -- A String constant for the canonical family name of the logical font "Serif".
 protected int size --The point size of this Font, rounded to integer.
 protected int style -- The style of this Font, as passed to the constructor.
 static int TRUETYPE_FONT -- Identify a font resource of type TRUETYPE.
 static int TYPE1_FONT -- Identify a font resource of type TYPE1.


Color

 static Color black -- The color black.
 static Color BLACK -- The color black.
 static Color blue -- The color blue.
 static Color BLUE -- The color blue.
 static Color cyan -- The color cyan.
 static Color CYAN -- The color cyan.
 static Color DARK_GRAY -- The color dark gray.
 static Color darkGray -- The color dark gray.
 static Color gray -- The color gray.
 static Color GRAY -- The color gray.
 static Color green -- The color green.
 static Color GREEN -- The color green.
 static Color LIGHT_GRAY -- The color light gray.
 static Color lightGray -- The color light gray.
 static Color magenta -- The color magenta.
 static Color MAGENTA -- The color magenta.
 static Color orange -- The color orange.
 static Color ORANGE -- The color orange.
 static Color pink -- The color pink.
 static Color PINK -- The color pink.
 static Color red -- The color red.
 static Color RED -- The color red.
 static Color white -- The color white.
 static Color WHITE -- The color white.
 static Color yellow -- The color yellow.
 static Color YELLOW -- The color yellow.
*/

import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;

class Demo_32 extends Frame {

        public Demo_32(){

                super("Java AWT Examples");
                prepareGUI();
          }
        public static void main(String[] args){

                Demo_32 Demo_32 = new Demo_32();
                Demo_32.setVisible(true);
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


                /*#### Font ####*/
      /*          Graphics2D g2 = (Graphics2D)g;
                Font plainFont = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(plainFont);
                g2.drawString("Welcome to TutorialsPoint", 50, 70);
                Font italicFont = new Font("Serif", Font.ITALIC, 24);
                g2.setFont(italicFont);
                g2.drawString("Welcome to TutorialsPoint", 50, 120);
                Font boldFont = new Font("Serif", Font.BOLD, 24);
                g2.setFont(boldFont);
                g2.drawString("Welcome to TutorialsPoint", 50, 170);
                Font boldItalicFont = new Font("Serif", Font.BOLD+Font.ITALIC, 24);
                g2.setFont(boldItalicFont);
                g2.drawString("Welcome to TutorialsPoint", 50, 220);    */


                /*#### Color ####*/
                Graphics2D g2 = (Graphics2D)g;
                Font plainFont = new Font("Serif", Font.PLAIN, 24);
                g2.setFont(plainFont);
                g2.setColor(Color.red);
                g2.drawString("Welcome to TutorialsPoint", 50, 70);
                g2.setColor(Color.GRAY);
                g2.drawString("Welcome to TutorialsPoint", 50, 120);
          }

}

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class CloseableFrame extends Frame implements WindowListener
{
        public CloseableFrame( )
        { this(" " ); }
        public CloseableFrame( String title )
        { super( title ); addWindowListener( this ); }
        public void windowClosing( WindowEvent event )
        { System.exit( 0 ); }
        public void windowClosed ( WindowEvent event ) { }
        public void windowDeiconified( WindowEvent event ) { }
        public void windowIconified ( WindowEvent event ) { }
        public void windowActivated ( WindowEvent event ) { }
        public void windowDeactivated( WindowEvent event ) { }
        public void windowOpened ( WindowEvent event ) { }
}
class CloseFrame{

        public static void main(String[]args){
        
                CloseableFrame cf = new CloseableFrame("");

                cf.setSize(new Dimension(300, 300));
                cf.setTitle("An AWT-Based Application");
                cf.setVisible(true);

                JFrame jf = new JFrame("title"); // or JFrame()
                jf.setSize(300, 200); // width, height in pixels (required)
                jf.setVisible(true); // (required)
                jf.setTitle("New Title");
                jf.setLocation(50, 100); // x and y from upper-left corner

                JPanel jp = new JPanel();
                jf.add(jp);
        }
}

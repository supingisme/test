/**
 *  PinBall
 *
 *   RongTao 2018.05
 *
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
/**
 *  JPanel: for drawing
 *
 */
class myJPanel extends JPanel
{
    private static final long serialVersionUID = 1L;
    /**
     *  painting
     *
     */
    public void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        
        g.fillRect(10,10,15,15);
        
        repaint(g);
    }
    protected void repaint(Graphics g)
	{        
        g.fillRect(10,10,35,35);
	}
}

public class Pinball extends JFrame implements ActionListener, MouseListener, KeyListener
{
    private Toolkit toolkit;
    public static Pinball pinball;

    /**
     * construction function
     */
    Pinball(String title, int width, int height)
    {
        this.setTitle(title);
        this.setSize(width,height);
        this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        toolkit = getToolkit();  
        Dimension size = toolkit.getScreenSize();  
        setLocation((size.width/2 - getWidth())/2, (size.height - getWidth())/2); 
    }
    
    public void paintColumn(Graphics g, Rectangle column)
	{
		g.setColor(Color.green.darker());
		g.fillRect(column.x, column.y, column.width, column.height);
	}
    
    public static void main(String[] args)
    {
        System.out.println("Hello World!");
        
        pinball = new Pinball("PinBall",300,400);
        
        //Timer timer = new Timer(2000,pinball);
        
        pinball.add(new myJPanel());
        
        
        pinball.setVisible(true);
        pinball.setResizable(false);
        
        //timer.start();
    }
    public void actionPerformed(ActionEvent e)
	{
        int speed = 10;
    }
    public void mouseClicked(MouseEvent e)
	{
		
	}
	public void mousePressed(MouseEvent e){}
	public void mouseReleased(MouseEvent e){}
	public void mouseEntered(MouseEvent e){}
	public void mouseExited(MouseEvent e){}

	public void keyPressed(KeyEvent e){}
	public void keyTyped(KeyEvent e){}
	public void keyReleased(KeyEvent e)
	{
		if(e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			
		}
	}
}
import java.awt.*; 
public class Demo_08_button03{ 
    public static void main(String[] args) { 
        Frame f = new Frame("流动布局"); 
        Button b1 = new Button("按钮1"); 
        Button b2 = new Button("按钮2"); 
        Button b3 = new Button("按钮3"); 
         
        f.setLayout(new FlowLayout()); 
        f.add(b1); 
        f.add(b2); 
        f.add(b3); 
         
        f.setSize(200,300); 
        f.setVisible(true); 
    } 
} 
/*
import java.awt.*;
public class Demo_08_button03{
	public static void main(String[] args) {
		Frame f = new Frame("流动布局");
 		Button b1 = new Button("按钮1");
		Button b2 = new Button("按钮2");
		Button b3 = new Button("按钮3");
  
		f.setLayout(new FlowLayout());
		f.add(b1);
		f.add(b2);
		f.add(b3);
  
		f.setSize(200,300);
		f.setVisible(true);
	}
}
*/

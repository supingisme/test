import java.awt.*;  
import java.awt.event.*;  
public class Demo_05_TextField {  
  
    public static void main(String[] args) {  
        new TFFrame();  
    }  
  
}  
  
class TFFrame extends Frame  
{  
    TFFrame()  
    {  
        TextField tf = new TextField();  
        add(tf);  
        //TextField上添加监视器  
        tf.addActionListener(new TFActionListener());  
        pack();  
        setVisible(true);  
    }  
}  
  
class TFActionListener implements ActionListener  
{  
    public void actionPerformed(ActionEvent e)  
    {  
        //(TextField)e.getSource()强制将对象转换为TextField  
        TextField tf = (TextField)e.getSource();  
        System.out.println(tf.getText());  
    }  
} 

import java.awt.*; 
public class Demo_08_button05 extends Frame { 
    Button[] b = new Button[5]; 
    public Demo_08_button05(){ 
        super("网格布局"); 
        for(int i=0; i<b.length; i++){ 
            b[i] = new Button("按钮"+i); 
        } 
        setLayout(new GridLayout(3,2)); 
        add(b[0]); 
        add(b[1]); 
        add(b[2]); 
        add(b[3]); 
        add(b[4]); 
        pack(); 
        setSize(300,100); 
        setLocation(100,200); 
        //setBounds(200.100,300,100);  
        setVisible(true);    
    } 
    public static void main(String[] args) { 
        new Demo_08_button05(); 
    } 
} 


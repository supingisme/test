import java.awt.*; 
public class Demo_08_button02 { 
    public static void main(String[] args) { 
        Frame f = new Frame("容器组件Pane的使用"); 
        Panel p = new Panel(); 
        Button b = new Button("确定"); 
         
        p.setBackground(Color.pink); 
        p.setBounds(50,50,80,60); 
         
        f.setLayout(null); 
        f.add(p); 
        p.add(b); 
        f.setBounds(200,200,200,160); 
        f.setVisible(true); 
    } 
} 

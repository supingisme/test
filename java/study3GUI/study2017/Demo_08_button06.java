import java.awt.*;

public class Demo_08_button06 { 
    public static void main(String[] args) { 
        Frame f=new Frame("CardLayout Example"); 
        CardLayout c1=new CardLayout(); 
        f.setLayout(c1); 
        Label lbl[]=new Label[4]; 
        for(int i=0;i<4;i++){ 
        lbl[i]=new Label("第"+i+"页"); 
        f.add(lbl[i],"card"+i); 
        } 
        while(true){ 
            try{ 
                Thread.sleep(1000); 
                }catch(InterruptedException e){ 
                    e.printStackTrace(); 
                    } 
            c1.next(f); 
            } 
        } 
} 

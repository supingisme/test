import java.awt.Button;  
import java.awt.FlowLayout;  
import java.awt.Frame;  
import java.awt.event.ActionEvent;  
import java.awt.event.ActionListener;  
import java.awt.event.WindowAdapter;  
import java.awt.event.WindowEvent;  
  
public class Demo_02_Frame {  
  
    //定义该图像中所需要的组件的引用  
    private Frame f;  
    private Button but;  
      
    Demo_02_Frame(){  
        init();  
          
    }  
      
    public void init(){  
          
        f=new Frame("my freame");  
        f.setBounds(300,100,600,500);  
        f.setLayout(new FlowLayout());  //采用流式布局  
          
        but=new  Button("my button");  
        //将组件添加到 frame中  
        f.add(but);  
          
        //加载一下窗体上的事件.  
        myEvent();  
        //显示窗体  
        f.setVisible(true);  
    }  
    private void myEvent(){  
        f.addWindowListener(new WindowAdapter(){  
            @Override  
            public void windowClosing(WindowEvent e) {  
                // TODO Auto-generated method stub  
                //super.windowClosing(e);  
                System.exit(0);  
            }  
        });  
          
        //让按钮具备退出程序的功能  
        /* 
         * 按钮就是事件源 
         * 那么选择那个监听器呢? 
         * 通过关闭窗体实例了解到,下个要知道那个组件具备什么样的特有监听器, 
         * 需要查看该组件对象的功能. 
         */  
        //添加一个活动监听  
        but.addActionListener(new ActionListener() {  
              
            @Override  
            public void actionPerformed(ActionEvent e) {  
                // TODO Auto-generated method stub  
                System.out.println("退出, 按钮干的");  
                System.exit(0);  
            }  
        });  
          
    }  
      
    public static void main(String[] args) {  
        Demo_02_Frame f=new Demo_02_Frame();  
    }  
  
}

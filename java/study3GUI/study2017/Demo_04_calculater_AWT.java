import static java.awt.BorderLayout.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Demo_04_calculater_AWT
{
	public static void main(String[] args)
	{
		Frame f = new Frame("计算器");
		Panel p1 = new Panel();
		p1.add(new TextField(30));
		f.add(p1 , NORTH);
		Panel p2 = new Panel();
		// 设置Panel使用GridLayout布局管理器
		p2.setLayout(new GridLayout(4, 4 , 6, 6));
		String[] name = {"7" , "8" , "9" , "/"
			, "4" , "5" , "6" , "*" , "1" , "2"
			, "3" , "-" ,"0" , "." , "=" , "+"};
		// 向Panel中依次添加16个按钮
		for (int i = 0 ; i < name.length; i++ )
		{
			p2.add(new Button(name[i]));
		}
		// 默认将Panel对象添加Frame窗口的中间
		f.add(p2);
		// 设置窗口为最佳大小
		f.pack();
		// 将窗口显示出来（Frame对象默认处于隐藏状态）
		f.setVisible(true);
		
		// 以匿名内部类的形式来创建事件监听器对象，用于关闭窗口
		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				System.exit(0);
			}
		});
	}
}

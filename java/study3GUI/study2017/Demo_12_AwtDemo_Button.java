/*
 创建图形化界面步骤：
1.创建fram窗体。
2.对窗体进行基本设置。
	比如大小，位置，布局。
3.定义组件。
4.将组件通过窗体的add方法添加到窗体中
5.让窗体显示，通过setVisible（true）方法。
 */
import java.awt.*;
import java.awt.event.*;
class  Demo_12_AwtDemo_Button
{
	public static void main(String[] args) 
	{
		Frame f =new Frame("my awt");
		f.setSize(500,400);//设置窗体大小500是宽，400是高
		f.setLocation(300,200);//设置初始显示位置，300是x坐标，200是y坐标
//		上边两个方法可以用它 f.setBounds(x, y, width, height)来统一设置
		f.setLayout(new FlowLayout());//默认的是边界布局管理器
		
		Button b = new Button("我是一个按钮");
		f.add(b);

		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				System.out.println("我关");
				System.exit(0);//这个方法的 关闭的是虚拟机，退出虚拟机，当然就退出了程序  
			}
			public void windowActivated(WindowEvent e)
			{
				System.out.println("我活动的");
			}
			public  void windowOpened(WindowEvent e)  
			{
				System.out.println("我被打开了");

			}
		}); 
		//设置frame显示，这时图形界面线程才启动
		f.setVisible(true);
	}
}
class MyWin extends WindowAdapter
{
	public void windowClosing(WindowEvent e)
	{
		System.exit(0);
		//System.out.println("MyWin------------"+e.toString());
	}
}

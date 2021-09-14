import java.awt.*;
import java.awt.event.*;
class  Demo_13_AwtFrame
{
	//定义该图形中所需的组件的引用。
	private Frame f;
	private Button but;

	Demo_13_AwtFrame()
	{
		init();
	}
	//初始化图形界面
	public void init()//初始化
	{
		f= new Frame("day22-MyFrame");

		//对frame进行基本设置。
		f.setBounds(300,100,600,500);
		f.setLayout(new FlowLayout());
		but = new Button("my button");
		//将组件添加到Frame中
		f.add(but);	
		//加载一下窗体上的事件。
		myEvent();
		//显示窗体
		f.setVisible(true);
	}
	//最好把事件处理和GUI组件的基本初始化分离开
	public void myEvent()//这些都是组件的特有事件，还有共性事件。
	{
		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				System.out.println("关闭窗口");
				System.exit(0);//这个方法的 关闭的是虚拟机，退出虚拟机，当然就退出了程序  
			}
		});
		//让按钮具备退出程序的功能。
		/*
		按钮就是事件源，那么选择哪一个监听器呢？通过关闭窗体实例了解到。想要知道那个组件具备什么样的特与监听器，
		需要查看该组件对象的功能。那么通过查阅button的描述，发现支持一个特有监听addActionListener(ActionListener l)；
		是没有适配器的少数组件之一，只要事件方法超过3个的组件，都有配适器（Adapter）；
		*/
		but.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e) 
			{
				System.out.println("退出，按钮干的");
				System.exit(0);
			}

		});
	}
	//主函数，用于测试
	public static void main(String[] args) 
	{
		new Demo_13_AwtFrame();
	}
}

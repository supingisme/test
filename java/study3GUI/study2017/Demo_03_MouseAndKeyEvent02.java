import java.awt.*;
import java.awt.event.*;
class Demo_03_MouseAndKeyEvent02 
{
	//定义该图形中所需的组件的引用。
	private Frame f;
	private Button but;
	private TextField tf;

	Demo_03_MouseAndKeyEvent02()
	{
		init();
	}
	public void init()//初始化
	{
		f= new Frame("day22-MyFrame");

		//对frame进行基本设置。
		f.setBounds(300,100,600,500);
		f.setLayout(new FlowLayout());

		but = new Button("my button");
		tf = new TextField(10);
		
		f.add(but);
		f.add(tf);
	
		myEvent();
		f.setVisible(true);
	}
	public void myEvent()
	{
		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				System.exit(0);
			}
		});
		//给but添加一个键盘侦听器
		but.addKeyListener(new KeyAdapter()
		{
			private int count;
			public void keyPressed(KeyEvent e)
			{
				//判断组合键
				if(e.isControlDown() && e.getKeyCode()==KeyEvent.VK_ENTER)//从父类InputEvent 找isControlDown
					//System.exit(0);
					System.out.println("Ctrl + Enter is down");
				//System.out.println("按下某个键了---"+count++);
				//System.out.println(e.getKeyChar());
				//打印按下的键上在字符串，及键值。
				System.out.println(KeyEvent.getKeyText(e.getKeyCode())+"....."+e.getKeyCode());
			}
		});

		tf.addKeyListener(new KeyAdapter()
		{
			public void keyPressed(KeyEvent e)
			{
				//限定键值的范围
				int code =e.getKeyCode();
				if(!(code>=KeyEvent.VK_0 && code<=KeyEvent.VK_9))
				{
					//不处理，取消掉事件，具有屏蔽键的作用，如果键入是字符非法则不写入文本框。
					e.consume();//从父类InputEvent中获取的方法consume，不按照默认的方法处理该事件。
					System.out.println(code + "....是非法的");
				}
			}
		});
		
		/*
		//给but添加监听器
		but.addActionListener(new ActionListener()
		{
			public void actionPerformed(ActionEvent e) 
			{
				System.out.println("button action");
			}

		});
	
		//给but添加鼠标监听器
		but.addMouseListener(new MouseAdapter()
		{
			private int count;
			private int clickCount;
			public void mouseEntered(MouseEvent e) 
			{
				System.out.println("鼠标进入组件区域啦--"+count++);				
			}
			public void mouseClicked(MouseEvent e) 
			{
				if(e.getClickCount()==2)
				System.out.println("鼠标双击Button了--"+clickCount++);
			}

		});
		*/

	}

	public static void main(String[] args) 
	{
		new Demo_03_MouseAndKeyEvent02();

	}
}

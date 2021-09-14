package tzq;
import java.awt.*;
import java.awt.event.*;
import java.io.File;

public class MyWindowDemo {
	private Frame f;
	private Button but;
	private TextArea ta;
	private TextField tf;
	
	private Dialog d;
	private Label lab;
	private Button okBut;
	
	
	public MyWindowDemo() {
		init();
	}
	private void init() {
		f=new Frame("My Window");
		f.setBounds(300, 200, 500, 400);
		f.setLayout(new FlowLayout());
		
		tf=new TextField(40);
		but=new Button("转到");
		ta=new TextArea(20,45);
		
		d=new Dialog(f, "提示信息", true);
		d.setBounds(400, 200, 300, 130);
		d.setLayout(new FlowLayout());
		
		lab=new Label();
		okBut=new Button("确定");
		
		d.add(lab);
		d.add(okBut);
		
		f.add(tf);
		f.add(but);
		f.add(ta);
	
		
		myEvent();
		
		f.setVisible(true);
		
		

	}
	
	
	public void myEvent(){
		 //添加按钮活动事件监听器 
		but.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				showDir();
				
			}
		});
		//okBut监听器
		okBut.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				d.setVisible(false);
				
			}
		});
		//添加textField的键盘监听器  
		tf.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				if(e.getKeyCode()==KeyEvent.VK_ENTER){
					showDir();
				}
				
			}
		});
		
		d.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				d.setVisible(false);
			}
			
			
		});
		
		
		//frame监听器
		f.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.out.println("程序关闭");
				System.exit(0);

			}
		});
		
	}
	
	private void showDir(){
		String disPath=tf.getText();
		File dir=new File(disPath);
		if(dir.exists() && dir.isDirectory()){
			ta.setText("");
			String []names=dir.list();
			for(String name:names){
				ta.append(name+"\r\n");
				
			}	
		}else{
			String info="您输入的信息"+disPath+"是错误的，请重新输入！";
			lab.setText(info);
			d.setVisible(true);
		}
		tf.setText("");
	}
	
	
	
	
	
	public static void main(String[] args) {
		new MyWindowDemo();
	}
}

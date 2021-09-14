import javax.swing.*;
import static java.awt.BorderLayout.*;
import java.awt.*;

public class Demo_04_calculater_Swing
{
	public static void main(String[] args)
	{
		JFrame f = new JFrame("计算器");
		JPanel p1 = new JPanel();
		p1.add(new JTextField(30));
		f.add(p1 , NORTH);
		JPanel p2 = new JPanel();
		// 设置Panel使用GridLayout布局管理器
		p2.setLayout(new GridLayout(4, 4 , 6, 6));
		String[] name = {"7" , "8" , "9" , "/"
			, "4" , "5" , "6" , "*" , "1" , "2"
			, "3" , "-" ,"0" , "." , "=" , "+"};
		// 向Panel中依次添加16个按钮
		for (int i = 0 ; i < name.length; i++ )
		{
			p2.add(new JButton(name[i]));
		}
		// 默认将Panel对象添加Frame窗口的中间
		f.add(p2);
		// 设置窗口为最佳大小
		f.pack();
		// 将窗口显示出来（Frame对象默认处于隐藏状态）
		f.setVisible(true);
	}
}

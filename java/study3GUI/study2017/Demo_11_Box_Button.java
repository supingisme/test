import java.awt.*;
import javax.swing.*;
class Demo_11_Box_Button extends JPanel {
  JCheckBox c1 = new JCheckBox("写作",false);
  JCheckBox c2 = new JCheckBox("音乐",false);
  JCheckBox c3 = new JCheckBox("跑步",false);
  JRadioButton rad1 = new JRadioButton("中学");
  JRadioButton rad2 = new JRadioButton("高中");
  JRadioButton rad3 = new JRadioButton("大学");
  JLabel jl = new JLabel("您有什么爱好？" );
  JLabel j2 = new JLabel("爱好产生的时间？" );
  JButton exitbtn = new JButton("退出");
  public Demo_11_Box_Button( )  {
     setLayout(new GridLayout(9,1)); 
     add(jl); add(c1); add(c2); add(c3);
     add(j2); add(rad1); add(rad2); add(rad3); add(exitbtn);
   }

	public static void main(String[]args){
		new Demo_11_Box_Button( );
	}
}

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

public class Demo_04_Calculater{

    private JFrame f; // 窗体
    private JTextField tf; // 文本框

    private JButton btn1; // 按钮 1
    private JButton btn2; // 按钮 2
    private JButton btnAdd; // 按钮 加号 +
    private JButton btnEqual; // 按钮 等于 =
    private JButton btnClear; // 按钮 清除

    StringBuffer sb; // 定义一个变量，存储文本框里面的数值
    Integer number1; // 加数
    Integer number2; // 被加数
    Integer sum; // 和

    boolean b; // 运算符是否被点击

    // 构造方法
    Demo_04_Calculater() {
        // 初始化原始数据
        initData();
        // 控件初始化
        initUI();
    }

    private void initData() {
        sb = new StringBuffer("");
        number1 = 0;
        number2 = 0;
        sum = 0;
        b = false;
    }

    private void initUI() {
        f = new JFrame("计算器");
        f.setSize(400, 200); // 设置窗口的宽高
        f.setLocation(100, 100); // 设置窗口的起始点
        // f.setLayout(new FlowLayout()); // 会重新绘制大小
        f.setResizable(false); // 设置窗口一旦创建好，不能在改变大小。
        // f.setBackground(Color.BLUE);
        // 关闭窗口的事件
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        f.setVisible(true); // 让窗口可见

        // 在窗口上面增加一个文本框
        tf = new JTextField();
        tf.setBounds(20, 50, 360, 33);
        tf.setText("0");
        tf.setHorizontalAlignment(JTextField.RIGHT);
        tf.setBackground(Color.WHITE);
        f.add(tf);
        // tf 鼠标事件
        tfMouseEvent();
        
        // 在窗口上面添加按钮
        btn1 = new JButton("1");
        btn1.setBounds(20, 100, 50, 33);
        f.add(btn1);

        btn2 = new JButton("2");
        btn2.setBounds(btn1.getBounds().x + 70, 100, 50, 33);
        f.add(btn2);

        btnAdd = new JButton("+");
        btnAdd.setBounds(btn2.getBounds().x + 70, 100, 50, 33);
        f.add(btnAdd);

        btnEqual = new JButton("=");
        btnEqual.setBounds(btnAdd.getBounds().x + 70, 100, 50, 33);
        f.add(btnEqual);

        btnClear = new JButton("C");
        btnClear.setBounds(btnEqual.getBounds().x + 70, 100, 50, 33);
        f.add(btnClear);

        // 按钮点击事件
        btnEvent();

        f.repaint();
    }
    private void tfMouseEvent() {
        tf.addMouseListener(new MouseListener() {
            
            @Override
            public void mouseReleased(MouseEvent e) {
                // TODO 自动生成的方法存根
                System.out.println("mouseReleased");
            }
            
            @Override
            public void mousePressed(MouseEvent e) {
                // TODO 自动生成的方法存根
                System.out.println("mousePressed");
            }
            
            @Override
            public void mouseExited(MouseEvent e) {
                // TODO 自动生成的方法存根
                System.out.println("mouseExited");
                tf.setBackground(Color.white);
            }
            
            @Override
            public void mouseEntered(MouseEvent e) {
                // TODO 自动生成的方法存根
                System.out.println("mouseEntered");
                tf.setBackground(Color.cyan);
            }
            
            @Override
            public void mouseClicked(MouseEvent e) {
                // TODO 自动生成的方法存根
                System.out.println("mouseClicked");
            }
        });
    }
    
    private void btnEvent() {
        btn1.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO 自动生成的方法存根
                if (b) {
                    sb = new StringBuffer("");
                    b = false;
                }
                sb.append(btn1.getText());
                tf.setText(sb.toString());
            }
        });

        btn2.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO 自动生成的方法存根
                if (b) {
                    sb = new StringBuffer("");
                    b = false;
                }
                sb.append(btn2.getText());
                tf.setText(sb.toString());
            }
        });
        btnAdd.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO 自动生成的方法存根
                b = true;
                number1 += new Integer(tf.getText());
                tf.setText(number1.toString());
            }
        });
        btnEqual.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO 自动生成的方法存根
                b = false;
                number2 = new Integer(tf.getText());
                sum = number1 + number2;
                tf.setText(sum.toString());
            }
        });
        btnClear.addActionListener(new ActionListener() {
            
            @Override
            public void actionPerformed(ActionEvent e) {
                // TODO 自动生成的方法存根
                initData();
                tf.setText("0");
            }
        });
        
    }

    public static void main(String[] args) {
        // TODO 自动生成的方法存根
        new Demo_04_Calculater();
    }

}

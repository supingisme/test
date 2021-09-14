import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;

public class LightScan extends Applet implements Runnable {
    private String myText;// 声明文本对象
    private Font font;// 声明字体对象
    private int fontSize;// 声明字体的大小
    private Thread mythread;// 声明线程对象
    private int spotPosition = 100;// 声明光标点出现的位置
    private int myTextSize = 20;// 文本的大小
    private int myTextWidth = 0;// 文本的宽度
    private int fontHeight, baseLine, w;
    public void init()// 小程充的初始化
    {
        myText = "Applet小程序";// 在小程序中需要显示的文本对像
        fontSize = 30;// 设置字体的大小
        font = new Font("TimesRoman", Font.BOLD, fontSize); // 创建Font对像
        FontMetrics fm = getFontMetrics(font);// 获取FontMetrics字体规格对象。
        fontHeight = fm.getHeight();
        baseLine = getSize().height / 2 + fontHeight / 3;
        myTextWidth = fm.stringWidth(myText);
        w = fm.stringWidth(myText);
        w = (getSize().width - w) / 2;
        spotPosition = w;
        setBackground(Color.black); // 设置小程序的背景色为黑色
    }
    public void start() {
        if (mythread == null) {
            mythread = new Thread(this);// 创建多线程
            mythread.start();// 启动多线程
        }
    }
    public void stop() {
        mythread.stop();// 停止运行线程
        mythread = null;
    }
    public void run()// 运行线程
    {
        while (true) {
            repaint();// 重绘此组件
            try {
                mythread.sleep(30);
            }// 线程休眠
            catch (InterruptedException e) {
            }
        }
    }
    public void update(Graphics g)// 更新组件
    {
        paint(g);
    }
    // 利用clipRect()方法，每次调用显示方法paint()时，
    // 先用红色的笔画一遍文字，再用白色在裁剪区中画一遍文字
    public void paint(Graphics g) {
        g.setFont(font);
        g.setColor(Color.red);
        g.drawString(myText, w, baseLine); // 第一遍显示
        g.clipRect(spotPosition, 0, myTextSize, getSize().height); // 设置裁剪区域
        g.setColor(Color.white);
        g.drawString(myText, w, baseLine); // 第二遍显示
        spotPosition = (spotPosition + 1) % (myTextWidth + 100); // 移动光标位置
    }
}

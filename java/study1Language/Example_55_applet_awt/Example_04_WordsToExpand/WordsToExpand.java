import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;

public class WordsToExpand extends Applet implements Runnable {
    private Image myImage;//声明Image图象对象
    private Graphics myGraphic;//声明Graphics对象
    private int width = 0, height = 0;//声明高和宽变量
    private String words;//定义文本内容
    private Thread mythread;//声明Thread多线程对象
    private int xPosition = 0, yPosition = 0, myHeight;//定义x和y坐标点
    private int times = 0;//表示线条出现的方向
    private Font font;
    public void init()//初始化Applet小程序
    {
        this.setSize(300, 200);
        font = new Font("TimesRoman", Font.BOLD, 30);
        width = 300;
        height = 200;
        myHeight = height / 3;
        yPosition = myHeight;
        words = "大家好";
        myImage = createImage(width, height);
        myGraphic = myImage.getGraphics();
    }
    public void start()//起动Applet小程序和多线程
    {
        if (mythread == null) {
            mythread = new Thread(this);
            mythread.start();
        }
    }
    public void update(Graphics g)//更新组件
    {
        paint(g);
    }
    public void paint(Graphics g)//绘制组件
    {
        g.drawImage(myImage, 0, yPosition, width, myHeight, this);
    }
    public void run()//运行多线程
    {
        try {
            while (true) {
                yPosition = 0;
                myHeight = height;
                myGraphic.setColor(Color.pink);
                myGraphic.fillRect(0, 0, width, height);
                repaint();
                mythread.sleep(100);
                if (times == 0) {
                    myGraphic.setColor(Color.black);
                    for (int i = width; i >= 0; i--) {
                        myGraphic.fillRect(i, height / 3, width, height / 10);
                        repaint();
                        mythread.sleep(10);
                    }
                } else if (times == 1) {
                    myGraphic.setColor(Color.blue);
                    for (int i = 0; i <= width; i++) {
                        myGraphic.fillRect(0, height / 3, i, height / 10);
                        repaint();
                        mythread.sleep(10);
                    }
                }
                yPosition = height / 3;
                myHeight = height / 3;
                for (int i = height / 3; i >= 0; i--) {
                    xPosition = 0;
                    yPosition--;
                    myHeight = myHeight + 2;
                    if (times == 0)//0表示从右向左移动
                    {
                        myGraphic.setColor(Color.black);
                        myGraphic.fillRect(0, 0, width, height);
                        myGraphic.setFont(font);
                        myGraphic.setColor(Color.yellow);
                        myGraphic.drawString(words, 10, 35);
                        times++;
                    } else if (times == 1)//1表示从左向右移动
                    {
                        myGraphic.setColor(Color.red);
                        myGraphic.fillRect(0, 0, width, height);
                        myGraphic.setFont(font);
                        myGraphic.setColor(Color.black);
                        myGraphic.drawString(words, 10, 35);
                        times = 0;
                    }
                    repaint();
                    mythread.sleep(100);
                }
                mythread.sleep(2500);
                System.out.println(times);
            }
        } catch (InterruptedException e) {
        }
    }
}

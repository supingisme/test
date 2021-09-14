import java.applet.Applet;
import java.applet.AudioClip;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Label;
import java.awt.MediaTracker;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class StrongButton extends Applet implements MouseListener {
    private Graphics grap; // 声明Graphics变量
    private MediaTracker media; // 声明MediaTracker变量
    private AudioClip audioA, audioB; // 声明AudioClip变量
    private int width, height; // 声明int类变量
    private Image image, img1, img2, img3; // 声明Image类型变量
    private Label la = new Label("多功能按键"); // 创建一个带初始值的Label对象
    public void init() { // 为Applet初始化
        audioA = getAudioClip(this.getDocumentBase(), "aa.wav"); // 创建audioA对象
        audioB = getAudioClip(getDocumentBase(), "hh.wav"); // //创建audioB对象
        width = getSize().width; // 返回Applet的宽度
        height = getSize().height; // 返回Applet的高度
        image = createImage(width, height); // 根据参数创建一个Image对象
        grap = image.getGraphics(); // 根据图像创建Graphics对像
        media = new MediaTracker(this); // MediaTracker对像实例化
        img1 = getImage(getDocumentBase(), "2.png"); // 根据参数创建Image对象
        media.addImage(img1, 0); // 将img1放入media对象中
        img2 = getImage(getDocumentBase(), "3.png");
        media.addImage(img2, 1);
        img3 = getImage(getDocumentBase(), "4.png");
        media.addImage(img3, 2);
        try {
            media.waitForAll(); // 等待media加载所有的图像
        } catch (InterruptedException e) {
        }
        la.setSize(100, 20);
        la.setForeground(Color.blue); // 设置标签的前景颜色
        this.add(la, BorderLayout.NORTH); // 将标签组件加载到Applet中
        addMouseListener(this); // 为Applet添加鼠标侦听事件
    }
    public void start() { // 开始Applet程序
        grap.drawImage(img1, 0, 0, width + 5, height, this); // 根据给定的参数绘制图像
        repaint();
    }
    public void mouseClicked(MouseEvent e) { // 鼠标单击事件
    }
    public void mousePressed(MouseEvent e) { // 鼠标按下事件
        grap.drawImage(img3, 0, 0, width + 5, height, this); // 当鼠标被按下时所绘制的图像
        audioA.stop(); // audioA停止播放声音
        audioB.play(); // audioB开始播放声音
        la.setBackground(Color.black); // 设置标签的背景颜色
        la.setForeground(Color.red); // 设置标签的前景颜色
        la.setText("audioB is playing"); // 设置标签中要显示的内容
        this.add(la, BorderLayout.NORTH); // 添加标签组件
        repaint(); // 重新绘制组件
    }
    public void mouseReleased(MouseEvent e) { // 鼠标释放事件
        grap.drawImage(img2, 0, 0, width + 5, height, this);
        repaint();
        audioB.stop();
        audioA.play();
        la.setBackground(Color.red);
        la.setForeground(Color.black);
        la.setText("audioA is playing");
        this.add(la, BorderLayout.NORTH);
    }
    public void mouseEntered(MouseEvent e) { // 鼠标进入Applet所触发的事件
        grap.drawImage(img2, 0, 0, width, height, this);
        repaint();
    }
    public void mouseExited(MouseEvent e) { // 鼠标离开Applet所触发的事件
        grap.drawImage(img1, 0, 0, width, height, this);
        repaint();
    }
    public void paint(Graphics g) {
        g.drawImage(image, 0, 0, width, height, this);
    }
}

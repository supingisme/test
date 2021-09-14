import java.applet.Applet;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Image;

public class RainbowWords extends Applet implements Runnable {
    String str = null;
    Thread thread = null; // 设置一个线程
    char[] ch;
    int p = 0;
    Image image;
    Graphics gphics;
    Color[] color;
    int one = 1;
    int two = 18;
    int three = 18;
    private Font f; // 字体
    private FontMetrics fm; // 字模
    public void init() {
        str = "Java Applet小程序"; // 设置七彩文字内容
        this.setSize(520, 200); // 设置Applet的大小
        setBackground(Color.white); // 设置背景颜色
        ch = new char[str.length()];
        ch = str.toCharArray(); // 将字符串中的各个字符保存到数组中
        image = createImage(getSize().width, getSize().height);
        gphics = image.getGraphics();
        f = new Font("", Font.BOLD, 18);
        fm = getFontMetrics(f); // 获得指定字体的字体规格
        gphics.setFont(f); // 设置组件的字体
        float hue;
        color = new Color[str.length()]; // 颜色的色元
        for (int i = 0; i < str.length(); i++) {
            hue = ((float) i) / ((float) str.length());
            color[i] = new Color(Color.HSBtoRGB(hue, 0.8f, 1.0f)); // 颜色分配
        }
    }
    public void start() { // 线程开始的类
        if (thread == null) { // 如果线程为空，则
            thread = new Thread(this);
            // 开始新的线程
            thread.start(); // 开始
        }
    }
    // 终止线程
    public void stop() {
        if (thread != null) { // 如果线程不为空，则
            thread.stop(); // 终止线程，使它
            thread = null; // 为空
        }
    }
    // 运行线程
    public void run() {
        while (thread != null) {
            try {
                thread.sleep(200); // 让线程沉睡200毫秒
            } catch (InterruptedException e) {
            }
            repaint(); // 重新绘制界面
        }
    }
    public void update(Graphics g) { // 重写update方法，解决闪烁问题
        int x, y;
        double a;
        gphics.setColor(Color.black);
        gphics.fillRect(0, 0, getSize().width, getSize().height);
        p += one;
        p %= 7; // 主要控制字的速度，被除数越小，速度越快
        // System.out.println(p+” p1”);
        for (int i = 0; i < str.length(); i++) {
            a = ((p - i * one) % 7) / 4.0 * Math.PI; // 主要控制弧度的，被除数越小，弧度越大
            x = 30 + fm.getMaxAdvance() * i + (int) (Math.cos(a) * two); // 求x坐标值
            y = 80 + (int) (Math.sin(a) * three); // 求y坐标值
            gphics.setColor(color[(p + i) % str.length()]);
            gphics.drawChars(ch, i, 1, x, y);
        }
        paint(g);
    }
    public void paint(Graphics g) {
        g.drawImage(image, 0, 0, this);
    }
}

import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
public class Reflection extends Applet implements Runnable {
    Thread thread = null;                    // 声明线程
    private Graphics g, inv_g;                // 定义绘制正常图像和倒立后图像的Graphics对象
    private Image image, invimage;            // image用于载入正常图像，invimage用于载入倒立后图像
    private int inv;                        // 应用于形成倒立影象的变量
    private int image_W = 2, image_H = 2;    // 定义装载图片宽和高的变量
    private boolean load_Flag = false;        // 定义标志，其作用是标志加载图片是否完毕
    private final int fre = 14;                // 定义水纹波动的频率，数值越大，波动越慢。
    private String picture_name = "";        // 定义图片名字
    public void init() {                    // 初始化applet
        picture_name = "a.png";
    }
    public void paint(Graphics g) {
        if (!load_Flag)                    // 如果已经载入图片，则返回
            return;
        if (invimage != null) {                // 输出倒影图片
            g.drawImage(invimage, (-inv * image_W), image_H, this);
            g.drawImage(invimage, ((fre - inv) * image_W), image_H, this);
        }
        g.drawImage(image, 0, -1, this);    // 输出正向图片
    }
    public void start() {                    // 启动applet，创建并启动线程
        if (thread == null) {
            thread = new Thread(this);
            thread.start();
        }
    }
    public void run() {// 启动线程
// 加载图片
inv = 0;
g = getGraphics();
MediaTracker imageTracker = new MediaTracker(this);
image = getImage(this.getCodeBase(), picture_name);
imageTracker.addImage(image, 0);
try {
            imageTracker.waitForAll();
            load_Flag = !imageTracker.isErrorAny();    // 检查媒体跟踪器跟踪的所有图像的错误状态
        } catch (InterruptedException e) {
        }
                                            // 图片宽度、图片高度
        image_W = image.getWidth(this);
        image_H = image.getHeight(this);
        this.setSize(image_W+1, image_H * 2 - 19);
        creatWater();                            // 生成倒影
        repaint();                                // 重新输出applet
        while (true) {
            try {
                if (!load_Flag)
                    return;
                if (invimage != null) {
                    g.drawImage(invimage, (-inv * image_W), image_H, this);
                    g.drawImage(invimage, ((fre - inv) * image_W), image_H,
                            this);
                }
                g.drawImage(image, 0, -1, this);
                if (++inv == fre)
                    inv = 0;
                Thread.sleep(50);
            } catch (InterruptedException e) {
                stop();
            }
        }
    }
    public void creatWater() {                        //产生水波特效
        Image back = createImage(image_W+3, image_H + 2);
        Graphics graphics = back.getGraphics();
        int phase = 0;
        int x, y;
        double p1;
        graphics.drawImage(image, 0, 1, this);
        for (int i = 0; i < (image_H >> 1); i++) {
            graphics.copyArea(0, i, image_W, 1, 0, image_H - i);
            graphics.copyArea(0, image_H - 1 - i, image_W, 1, 0, -image_H + 1
                    + (i << 1));
            graphics.copyArea(0, image_H, image_W, 1, 0, -1 - i);
        }
        invimage = createImage((fre + 1) * image_W+20, image_H+2);
        inv_g = invimage.getGraphics();
        inv_g.drawImage(back, fre * image_W, 0, this);
        for (phase = 0; phase < fre; phase++) {
            p1 = 2 * Math.PI * (double) phase / (double) fre;
            x = (fre - phase) * image_W;
            for (int i = 0; i < image_H; i++) {
                y = (int) ((image_H / 14)
                        * ((double) i + 28.0)
                        * Math.sin((double) ((image_H / 14) * (image_H - i))
                                / (double) (i + 1) + p1) / (double) image_H);
                if (i < -y)
                    inv_g.copyArea(fre * image_W, i, image_W, 1, -x, 0);
                else
                    inv_g.copyArea(fre * image_W, i + y, image_W, 1, -x,
                            -y);
            }
        }
graphics.drawImage(image, 0, 1, this);
image = back;
    }
}

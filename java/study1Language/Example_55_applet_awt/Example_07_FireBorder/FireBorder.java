import java.applet.Applet;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;

public class FireBorder extends Applet implements Runnable
// 在applet中支持线程，需要实现Runnable接口
{
    private Image bimg, fimg, offI, virtualI;// 声明Image图象对象
    private Graphics offG, virtualG;// 声明Graphics对象
    private Thread thread = null;// 声明Thread多线程对象
    private MediaTracker imageTracker;// 声明MediaTracker对象
    private int height, width, X, Y;// 声明int型变量
    public void init() {
        // 初始化applet,加载背景图片、前景图片
        this.setSize(300, 200);
        String imageName = "a.png";
        String imageName2 = "a.gif";
        bimg = getImage(getDocumentBase(), imageName);// 获取背景图片
        fimg = getImage(getDocumentBase(), imageName2);// 获取前景图片
        imageTracker = new MediaTracker(this); // 创建一个媒体跟踪器的实例
        // 将图片加入到 MedialTracker 的监视队列中去， image 为要被监视的图像对象，
        // 0 为监视图像在监视队列中的标识号
        imageTracker.addImage(bimg, 0);
        imageTracker.addImage(fimg, 0);
        width = this.getSize().width; // 设置applet宽度
        height = this.getSize().height; // 设置applet高度
        try {
            imageTracker.waitForID(0); // 加载图片
        } catch (InterruptedException e) {
        }
        offI = createImage(width, height);
        offG = offI.getGraphics();
        virtualI = createImage(width * 2, height * 2);
        virtualG = virtualI.getGraphics();
    }
    public void start() {
        // 启动applet,创建并启动一个线程
        if (thread == null) {
            thread = new Thread(this); // 以applet初始化线程
            thread.start(); // 启动线程，调用run()方法
        }
    }
    public void run() {
        // 线程调用开始
        int x = 0, y = 0;
        int tileWidth = bimg.getWidth(this); // 设置招牌宽度
        int tileHeight = bimg.getHeight(this); // 设置招牌高度
        while (thread != null) {
            try {
                Thread.sleep(10);
                x = virtualI.getWidth(this) - width;
                y = virtualI.getHeight(this) - height;
                // 在不同的坐标位置输出图像以产生燃烧效果
                for (; (x > 0) && (y > 0); x--, y--) {
                    if ((x == 0) || (y == 0)) {
                        x = virtualI.getWidth(this) - width;
                        y = virtualI.getHeight(this) - height;
                    }
                    // 输出图像，产生燃烧特效
                    for (int j = 0; j < virtualI.getHeight(this); j = j
                            + tileHeight)
                        for (int i = 0; i < virtualI.getWidth(this); i = i
                                + tileWidth)
                            virtualG.drawImage(bimg, i, j, this);
                    virtualG.drawImage(fimg, x, y, width, height, this);
                    offG.drawImage(virtualI, -x, -y, this);
                    // 输出applet，调用update()方法
                    repaint();
                }
            } catch (InterruptedException e) {
            }
        }
    }
    public void update(Graphics g) {
        // 调用paint()方法
        paint(g);
    }
    public void paint(Graphics g) {
        // 输出applet
        g.drawImage(offI, 0, 0, this);
    }
}

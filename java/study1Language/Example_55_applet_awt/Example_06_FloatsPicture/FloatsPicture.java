import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Point;
import java.awt.image.PixelGrabber;
import java.util.Random;

public class FloatsPicture extends Applet {
    private Image image;// 声明图片对象
    private int x = 25, y = 25;// 定义int型变量 分别表示x和y坐标点的值
    private Random random;// 声明随机数类Random对象
    private int width, height, w, h, image_size, pixels[];// 定义int型变量和数组
    public void init() { // 初始化applet
        this.setSize(400, 400);
        random = new Random();
        // 从网页获取图片文件名参数
        String imageName = "7.png";
        // 加载图片
        image = getImage(getDocumentBase(), imageName);
        MediaTracker imageTracker = new MediaTracker(this);
        imageTracker.addImage(image, 0);
        try {
            imageTracker.waitForID(0);
        } catch (InterruptedException e) {
        }
    }
    public void start() {
        // 启动applet,然后调用paint()方法
        width = getSize().width; // applet宽度
        height = getSize().height; // applet高度
        w = image.getWidth(this); // 图片宽度
        h = image.getHeight(this); // 图片高度
        // 图片输出位置
        x = (width - w) / 2;
        y = (height - h) / 2;
        // 图片大小
        image_size = w * h;
        // 创建图片的像素数组
        pixels = new int[image_size];
        // 创建一个像素获取器的实例，并将其与像素数组关联
        PixelGrabber pg = new PixelGrabber(image, 0, 0, w, h, pixels, 0, w);
        try {
            // 解析图片的像素信息
            pg.grabPixels();
        } catch (InterruptedException e) {
        }
    }
    public void paint(Graphics g) {
        g.setColor(Color.white);
        g.fillRect(0, 0, getSize().width, getSize().height);
        // 调用drawImage()方法，在相应的位置输出图片
        drawImage(g, image, x, y);
    }
    private void drawImage(Graphics g, Image image, int x, int y) {
        // 输出图片
        while (true) {
            g.setColor(Color.white);
            g.fillRect(0, 0, getSize().width, getSize().height);
            try {
                int one_time = w; // 图片宽度
                int S_x = 0, S_y = 0;
                S_x = (int) (random.nextFloat() * width);
                S_y = (int) (random.nextFloat() * height);
                Laser[] nextlot = new Laser[one_time];
                int k = 0, l = 0;
                int step = 1, start = 0;
                float f = random.nextFloat();
                step = (f < 0.8) ? 34759 : (f < 0.9 ? 1 : image_size - 1); // 步长
                // start=(int)(random.nextFloat()*image_size); //起始位置
                f = random.nextFloat();
                start = (f < 0.5) ? image_size : 0; // 如果f小于0.5,则起始位置为图片大小，否则为0
                int sofar = 0;
                // 初始化nextlot数组
                for (k = start; l < image_size; l++, k += step) {
                    Thread.sleep(2);
                    if (k < 0)
                        k += image_size;
                    k %= image_size;
                    int row = k / w;
                    int col = k % w;
                    Color colr = new Color(pixels[k]);
                    int finishx = x + col;
                    int y1 = y + row;
                    nextlot[sofar] = new Laser(colr, new Point(S_x, S_y),
                            new Point(finishx, y1));
                    sofar++;
                    if (sofar == one_time) {
                        Track(g, nextlot);
                        sofar = 0;
                    }
                }
            } catch (Exception e) {
            }
            g.setPaintMode();
            g.drawImage(image, x, y, this);
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
            }
        }
    }
    private synchronized void Track(Graphics g, Laser[] nextlot) {
        Color back = Color.white;
        g.setXORMode(back);
        for (int pass = 0; pass < 2; pass++) {
            for (int pixnr = 0; pixnr < nextlot.length; pixnr++) {
                Laser p = nextlot[pixnr];
                if (!close(p.c, back)) {
                    g.setColor(p.c);
                    g.drawLine(p.start.x, p.start.y, p.finish.x, p.finish.y);
                }
                if (pass == 1) {
                    g.setColor(p.c);
                    g.drawLine(p.finish.x, p.finish.y, p.finish.x, p.finish.y);
                }
            }
        }
        Thread.yield();
    }
    private boolean close(Color c1, Color c2) {
        return (Math.abs(c1.getRed() - c2.getRed())
                + Math.abs(c1.getGreen() - c2.getGreen()) + Math.abs(c1
                .getBlue()
                - c2.getBlue())) < 0xff;
    }
}
class Laser {
    public Color c;
    public Point start, finish;
    public Laser(Color c, Point start, Point finish) {
        this.c = c;
        this.start = start;
        this.finish = finish;
    }
}

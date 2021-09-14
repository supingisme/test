import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.net.URL;
import java.util.Random;
public class MissileDemo extends Applet implements Runnable {
public int speed, variability, Max_Number, Max_Energy, Max_Patch,
            Max_Length, G;
    public String sound;
    private int width, height;                    // 获取当前容器边界的宽和高
    private Thread thread = null;                // 设置线程
    private BeaClassDemo bcd[];                // 创建BeaClassDemo类数组bcd
    public void init() {                        // Applet初始化
        int i;
        this.setSize(400, 400);                 // 设置当前容器的宽和高
        width = getSize().width - 1;
        height = getSize().height - 1;
        speed = 30;                        // 烟花绽放的速度
        variability = 10;
        Max_Number = 100;                    // 可发出烟花的最大数目
        Max_Energy = width + 50;
        Max_Patch = 80;                    // 最大的斑点数
        Max_Length = 200;                    // 斑点的最大距离
        G = 50;                            // 向地面弯曲的力度
        bcd = new BeaClassDemo[Max_Number];            // 初始化BeaClassDemo数组
        for (i = 0; i < Max_Number; i++)
            bcd[i] = new BeaClassDemo(width, height, G);    // 创建BeaClassDemo类对象
    }
    public void start() {        // 启动线程
        if (thread == null) {
            thread = new Thread(this);
            thread.start();
        }
    }
    public void stop() {        // 停止线程
        if (thread != null) {
            thread.stop();
            thread = null;
        }
    }
    public void run() {
        int i;
        int E = (int) (Math.random() * Max_Energy * 3 / 4) + Max_Energy / 4 + 1;
        int P = (int) (Math.random() * Max_Patch * 3 / 4)    // 烟花的斑点数
                + Max_Patch / 4 + 1;
        int L = (int) (Math.random() * Max_Length * 3 / 4)    // 烟花可发射出的距离
                + Max_Length / 4 + 1;
        long S = (long) (Math.random() * 10000);            // 产生的随机数
        boolean sleep;                                // 体眠的标志
        Graphics g = getGraphics();
        URL u = null;
        while (true) {
            try {
                thread.sleep(1000 / speed);
            } catch (InterruptedException x) {
            }
            sleep = true;
            for (i = 0; i < Max_Number; i++)
                sleep = sleep && bcd[i].sleep;
            if (sleep && Math.random() * 100 < variability) {
                E = (int) (Math.random() * Max_Energy * 3 / 4) + Max_Energy / 4
                        + 1;
P = (int) (Math.random() * Max_Patch * 3 / 4) + Max_Patch / 4
                        + 1;
L = (int) (Math.random() * Max_Length * 3 / 4) + Max_Length / 4
                        + 1;
                S = (long) (Math.random() * 10000);
            }
            for (i = 0; i < Max_Number; i++) {
                if (bcd[i].sleep && Math.random() * Max_Number * L < 1) {
bcd[i].init(E, P, L, S);
bcd[i].start();
                }
                bcd[i].show(g);
            }
        }
    }
    public void paint(Graphics g) {                    // 绘制组件
        g.setColor(Color.black);                    // 设置背景颜色为黑
        g.fillRect(0, 0, width + 1, height + 1);            // 根据参数画矩形
    }
}
class BeaClassDemo {
public boolean sleep = true;
private int energy, patch, length, width, height, G, Xx, Xy, Ex[], Ey[], x,
            y, Red, Blue, Green, t;
    private Random random;                        // 声明Random类对象
    public BeaClassDemo(int a, int b, int g) {            // 类BeaClassDemo的构造方法
        width = a;
        height = b;
        G = g;
    }
    public void init(int e, int p, int l, long seed) {// 初始化
        int i;
    // 赋值运算
energy = e;
patch = p;
length = l;
        // 创建一个带种子的随机数生成器
        random = new Random(seed);
        Ex = new int[patch];                        // 初始化int数组Ex，其长度为patch
        Ey = new int[patch];                        // 初始化int数组Ey，其长度为patch
        // 随机生成不透明的sRGB颜色值
        Red = (int) (random.nextDouble() * 128) + 128;
        Blue = (int) (random.nextDouble() * 128) + 128;
        Green = (int) (random.nextDouble() * 128) + 128;
        Xx = (int) (Math.random() * width / 2) + width / 4;
        Xy = (int) (Math.random() * height / 2) + height / 4;
        for (i = 0; i < patch; i++) {
            Ex[i] = (int) (Math.random() * energy) - energy / 2;
            Ey[i] = (int) (Math.random() * energy * 7 / 8) - energy / 8;
        }
    }
    public void start() {
t = 0;
sleep = false;
    }
    public void show(Graphics g) {        // 输出烟花
        if (!sleep)                    // 如果休眠状态为false
            if (t < length) {
                int i, c;
                double s;
                Color color;
                c = (int) (random.nextDouble() * 64) - 32 + Red;
                if (c >= 0 && c < 256)
                    Red = c;
                c = (int) (random.nextDouble() * 64) - 32 + Blue;
                if (c >= 0 && c < 256)
                    Blue = c;
                c = (int) (random.nextDouble() * 64) - 32 + Green;
                if (c >= 0 && c < 256)
                    Green = c;
                color = new Color(Red, Blue, Green);
                for (i = 0; i < patch; i++) {
                    s = (double) t / 100;
                    x = (int) (Ex[i] * s);
                    y = (int) (Ey[i] * s - G * s * s);
                    g.setColor(color);
                    g.drawLine(Xx + x, Xy - y, Xx + x, Xy - y);
                    if (t >= length / 2) {
                        int j;
                        for (j = 0; j < 2; j++) {
                            s = (double) ((t - length / 2) * 2 + j) / 100;
                            x = (int) (Ex[i] * s);
                            y = (int) (Ey[i] * s - G * s * s);
                            g.setColor(Color.black);
                            g.drawLine(Xx + x, Xy - y, Xx + x, Xy - y);
                        }
                    }
                }
                t++;
            } else {
                sleep = true;
            }
    }
}

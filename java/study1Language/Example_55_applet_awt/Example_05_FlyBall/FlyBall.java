import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

public class FlyBall extends Applet implements Runnable {
    Thread artist = null;
    int bubble = 0, thisbubble = 0; // 气球数量，当前气球编号
    int MAXBUBBLES = 25; // 最大气球数量
    int stepper = 4; // Counter for which bubbles to move when
    int record[][] = new int[MAXBUBBLES][5]; // 记录气球的二维数组
    public void init() {        // 初始化applet
        resize(400, 400);     // 设定applet尺寸
    }
    public void draw_bubble(int x, int y, int r, Color col, Graphics g) {
        // 输出气球
        int i;
        // 输出一个圆形
        for (i = x - r; i <= x + r; i++) {
            g.setColor(col);
            g.drawLine(i, y - (int) (Math.sqrt(r * r - ((i - x) * (i - x)))),
                    i, y + (int) (Math.sqrt(r * r - ((i - x) * (i - x)))));
        }
    }
    public void move_bubble(int x, int y, int r, Color col, int step, Graphics g) {
        // 移动气球
        int i;
        // 输出气球的上半部分
        for (i = x - r; i <= x + r; i++) {
            g.setColor(col);
            g.drawLine(i, y - (int) (Math.sqrt(r * r - ((i - x) * (i - x)))),
                    i, y + step
                            - (int) (Math.sqrt(r * r - ((i - x) * (i - x)))));
        }
        // 输出气球的下半部分
        for (i = x - r; i <= x + r; i++) {
            g.setColor(Color.white);
            g.drawLine(i, y + (int) (Math.sqrt(r * r - ((i - x) * (i - x)))),
                    i, y + step
                            + (int) (Math.sqrt(r * r - ((i - x) * (i - x)))));
        }
    }
    public void paint(Graphics g) {
        int i, j, tmp;
        if (bubble < MAXBUBBLES || thisbubble < MAXBUBBLES) {
            record[thisbubble][0] = (int) (Math.random() * 300);
            record[thisbubble][1] = 320;
            record[thisbubble][2] = (int) (Math.random() * 400) / 20;
            record[thisbubble][3] = (int) (Math.random() * 255);
            record[thisbubble][4] = (int) (Math.random() * 255);
            // 输出气球
            draw_bubble(record[thisbubble][0], record[thisbubble][1],
                    record[thisbubble][2], new java.awt.Color(
                            record[thisbubble][3], record[thisbubble][4], 255),
                    g);
            // 如气球数小于最大值，则总气球数自增1，当前气球编号自增1
            if (bubble < MAXBUBBLES) {
                bubble++;
                thisbubble++;
            } else
                // 气球数等于最大值
                thisbubble = MAXBUBBLES;
        }
        for (i = 0; i < bubble; i++) {
            if (i % 5 <= stepper) {
                record[i][1] -= 1;
                // 移动气球
                move_bubble(record[i][0], record[i][1], record[i][2],
                        new java.awt.Color(record[i][3], record[i][4], 255), 1,
                        g);
                for (j = 0; j < i; j++) {
                    tmp = ((record[i][1] - record[j][1])
                            * (record[i][1] - record[j][1]) + (record[i][0] - record[j][0])
                            * (record[i][0] - record[j][0]));
                    if (j != i && Math.sqrt(tmp) < record[i][2] + record[j][2]) {
                        for (tmp = record[i][2]; tmp >= -1; tmp = tmp - 2)
                            draw_bubble(record[i][0], record[i][1],
                                    record[i][2] - tmp, Color.white, g);
                        draw_bubble(record[j][0], record[j][1], record[j][2],
                                new java.awt.Color(record[j][3], record[j][4],
                                        255), g);
                        record[i][1] = -1;
                        record[i][2] = 0;
                    }
                }
            }
            if (record[i][1] + record[i][2] < 0 && bubble >= MAXBUBBLES) {
                thisbubble = i;
            }
            stepper = (int) (Math.random() * 10);
        }
    }
    public void update(Graphics g) {
        paint(g);
    }
    public void start() {
        // 启动applet,创建并启动线程
        if (artist == null) {
            artist = new Thread(this);
            artist.start();
        }
    }
    public void stop() {
        // 结束applet
        artist = null;
    }
    public void run() {
        // 启动线程
        while (artist != null) {
            try {
                Thread.sleep(200);
            } catch (InterruptedException e) {
            }
            repaint();
        }
        artist = null;
    }
}

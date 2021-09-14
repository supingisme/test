import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class ZoomWords extends Applet implements MouseMotionListener {
    Graphics g;// 声明Graphics对象
    Image image;// 声明Image对象
    Image back_Image;// 声明Image对象
    String name;// 声明String对象
    MediaTracker tracker; // 声明媒体跟踪器tracker
    int Glass_X = 0, Glass_Y = 0; // 放大镜初始位置
    int Glass_W = 100, Glass_H = 100; // 放大镜宽度、高度
    int width, height; // 声明背景图片的宽度和高度
    public void init() { // 初始化applet
        // 加载图片
        this.setSize(370, 500);
        g = getGraphics();
        name = "a.png";
        tracker = new MediaTracker(this);
        back_Image = getImage(getDocumentBase(), name);
        image = createImage(250, 100); // 设置放大后的图象的大小
        Graphics offg = image.getGraphics();
        offg.drawImage(back_Image, 0, 0, this);
        addMouseMotionListener(this); // 添加鼠标事件侦听
    }
    public void mouseDragged(MouseEvent e) { // 鼠标拖拽事件处理
    }
    public void mouseMoved(MouseEvent e) { // 处理鼠标移动事件
        reprintGlass(Glass_X, Glass_Y, e.getX(), e.getY()); // 通过鼠标位置设置放大镜的位置
        // 设置放大镜的当前位置
        Glass_X = e.getX();
        Glass_Y = e.getY();
        // 若放大镜溢出applet则进行调整
        if (Glass_X > (width - Glass_W / 2))
            Glass_X = width - Glass_W / 2;
        if (Glass_Y > (height - Glass_H / 2))
            Glass_Y = height - Glass_H / 2;
        printGlass(); // 调用自定义方法—输出放大镜
    }
    void printGlass() {
        Graphics temp = g.create(); // 复制g的一个实例
        temp.clipRect(Glass_X, Glass_Y, Glass_W, Glass_H); // 为temp限制一个矩形区域
        temp.drawImage(back_Image, -Glass_X, -Glass_Y, width * 2, height * 2,
                null); // 输出放大后的图象
        g.setColor(Color.black);// 设置放大镜边框的颜色
        g.drawRect(Glass_X, Glass_Y, Glass_W - 1, Glass_H - 1);// 输出放大镜边框
    }
    void reprintGlass(int X, int Y, int new_X, int new_Y) { // 清除已经画过的矩形框和放大的图象
        Graphics temp = g.create(); // 同上
        if (new_X <= X && new_Y <= Y) {
            temp.clipRect(new_X, new_Y + Glass_H, Glass_W + X - new_X, Y
                    - new_Y);
            temp.drawImage(image, 0, 0, null);
            temp = g.create();
            temp.clipRect(new_X + Glass_W, new_Y, X - new_X, Glass_H + Y
                    - new_Y);
            temp.drawImage(image, 0, 0, null);
        } else if (new_X > X && new_Y <= Y) {
            temp.clipRect(X, new_Y + Glass_H, Glass_W + new_X - X, Y - new_Y);
            temp.drawImage(image, 0, 0, null);
            temp = g.create();
            temp.clipRect(X, new_Y, new_X - X, Glass_H + Y - new_Y);
            temp.drawImage(image, 0, 0, null);
        } else if (new_X > X && new_Y > Y) {
            temp.clipRect(X, Y, Glass_W + new_X - X, new_Y - Y);
            temp.drawImage(image, 0, 0, null);
            temp = g.create();
            temp.clipRect(X, Y, new_X - X, Glass_H + new_Y - Y);
            temp.drawImage(image, 0, 0, null);
        } else {
            temp.clipRect(new_X, Y, Glass_W + X - new_X, new_Y - Y);
            temp.drawImage(image, 0, 0, null);
            temp = g.create();
            temp.clipRect(new_X + Glass_W, Y, X - new_X, Glass_H + new_Y - Y);
            temp.drawImage(image, 0, 0, null);
        }
    }
    public boolean imageUpdate(Image img, int infoflags, int x, int y, int w,
            int h) { // 判断infoflags参数是否已完全加载了图像，是则返回false；否则返回true
        if (infoflags == ALLBITS) { // ALLBITS指示现在已完成了一幅以前绘制的静态图像，并且可以其最终形式再次绘制它。
            width = back_Image.getWidth(this);
            height = back_Image.getHeight(this);
            image = createImage(width + Glass_W / 2, height + Glass_H / 2);
            Graphics offg = image.getGraphics();
            offg.setColor(Color.white);
            offg.fillRect(0, 0, width + Glass_W / 2, height + Glass_H / 2);
            offg.drawImage(back_Image, 0, 0, this);
            repaint();
            return false;
        } else
            return true;
    }
    public void paint(Graphics g) {
        g.drawImage(back_Image, 0, 0, this); // 输出背景图片
        printGlass(); // 画放大镜
    }
}

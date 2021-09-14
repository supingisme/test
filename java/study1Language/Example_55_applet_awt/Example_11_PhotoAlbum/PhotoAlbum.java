import java.applet.Applet;
import java.awt.Choice;
import java.awt.Event;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;

public class PhotoAlbum extends Applet {
    private Choice myChoice;// 声明Choice对象
    private String[] myString1, myString2;// 声明String类型的数组
    private int totalPics;// 声明一个int型变量
    private Image offI;// 声明Image对象
    private Image[] img;// 声明一组Image对象数组
    private Graphics offG;// 声明一个Graphics对象
    private MediaTracker imagetracker;// 声明一个MediaTracker对象
    public void init() {// 对Applet小程序进行初始化
        this.setSize(600, 450);
        this.setLayout(null);
        myChoice = new Choice();
        myChoice.setBounds(10, 10, 290, 20);
        totalPics = 4;
        myString1 = new String[totalPics];
        myString2 = new String[totalPics];
        img = new Image[totalPics];
        for (int i = 0; i < totalPics; i++) {
            myString1[i] = new String("");
            myString2[i] = new String("");
        }
        String s = new String("");
        imagetracker = new MediaTracker(this);// 加载图片
        for (int i = 0; i < totalPics; i++) {
            s = "第 " + (i + 1) + " 张照片";
            myString1[i] = s;
            System.out.println(myString1[i]);
            myChoice.addItem(s);// 向下拉列表中增加选项
            s = (i + 1) + ".png";
            myString2[i] = s;
            img[i] = getImage(getDocumentBase(), s);
            imagetracker.addImage(img[i], 0);
        }
        try {
            imagetracker.waitForID(0);
        } catch (InterruptedException e) {
        }
        add(myChoice);
        offI = createImage(getSize().width, getSize().height - 40);// 创建图象
        offG = offI.getGraphics();
        offI = img[0];
        offG.drawImage(offI, 0, 0, this);
        repaint();
    }
    public void paint(Graphics g) {
        g.drawImage(offI, 10, 40, this);
    }
    // 使用action()方法来获得Java Applet小程序运行时所发生的事件
    public boolean action(Event e, Object o) {
        if (e.target == myChoice) {
            // String s = new String("");
            offG.setColor(this.getBackground());
            offG.fillRect(0, 40, getSize().width, getSize().height - 40);
            offI = img[myChoice.getSelectedIndex()];
            offG.drawImage(offI, 0, 0, this);
            repaint();
        }
        return true;
    }
}

import javax.swing.JFrame;
import javax.swing.JLabel;

class A extends JFrame{
    
    public int a, b, c;
    private int d, e, f;
    private String name;

    private JFrame jf;

    A(String name)
    {
        this.name = name;
    }
    A(String name, int val)
    {
        super(name);
        this.a = val;
        this.b = val;
        this.c = val;
        this.e = val;
        this.f = val;
        this.d = val;
    }

    void Show()
    {
        this.jf = new JFrame(name);
        this.jf.setVisible(true);
        this.jf.setSize(200, 200);
        this.jf.add(new JLabel("Sylincom"));
    }

}


class main{

    static public void main(String[]args)
    {
        System.out.println("Hello World!");

        A a = new A("荣涛");
        a.Show();
    }
}

package jgw;
 
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;
import java.util.ArrayList;
 
 
 
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
 
 
public class Demo_04_calculater extends JFrame{
    private JButton btn0=new JButton("0");
    private JButton btn1=new JButton("1");
    private JButton btn2=new JButton("2");
    private JButton btn3=new JButton("3");
    private JButton btn4=new JButton("4");
    private JButton btn5=new JButton("5");
    private JButton btn6=new JButton("6");
    private JButton btn7=new JButton("7");
    private JButton btn8=new JButton("8");
    private JButton btn9=new JButton("9");
    private JButton btnpoint=new JButton(".");
    private JButton btnsqrt=new JButton("¡Ì");
    private JButton btnadd=new JButton("+");
    private JButton btnsub=new JButton("-");
    private JButton btnmul=new JButton("*");
    private JButton btndiv=new JButton("/");
    private JButton btnback=new JButton("¡û");
    private JButton btnsin=new JButton("sin");
    private JButton btnequ=new JButton("=");
    private JButton btnclear=new JButton("CE");
    private JTextArea input=new JTextArea(2,21);
    private JTextArea show=new JTextArea("Result:\n",2,21);
 
    private String result="";
     
    private ArrayList<Integer> signpos=new ArrayList<Integer>();
    public Demo_04_calculater(String title)
    {
        this();
        setTitle(title);
    }
    private Demo_04_calculater(){
        setLayout(new FlowLayout(FlowLayout.LEADING));
        setSize(250, 250);
        setResizable(false);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);//¾ÓÖÐ
        show.setEditable(false);
        input.setEditable(false);
        add(input);
        add(show);
        add(btn7);
        add(btn8);
        add(btn9);
        add(btndiv);
        add(btnsqrt);
        add(btn4);
        add(btn5);
        add(btn6);
        add(btnmul);
        add(btnback);
        add(btn1);
        add(btn2);
        add(btn3);
        add(btnsub);
        add(btnclear);
        add(btn0);
        add(btnpoint);
        add(btnsin);
        add(btnadd);
        add(btnequ);
         
        btn0.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"0");
            }
        });
        btn1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"1");
            }
        });
        btn2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"2");
            }
        });
        btn3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"3");
            }
        });
        btn4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"4");
            }
        });
        btn5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"5");
            }
        });
        btn6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"6");
            }
        });
        btn7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"7");
            }
        });
        btn8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"8");
            }
        });
        btn9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+"9");
            }
        });
        btnpoint.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText(input.getText()+".");
            }
        });
        btnadd.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                signpos.add(input.getText().length());
                input.setText(input.getText()+"+");
            }
        });
        btnsub.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                signpos.add(input.getText().length());
                input.setText(input.getText()+"-");
            }
        });
        btnmul.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                signpos.add(input.getText().length());
                input.setText(input.getText()+"*");
            }
        });
        btndiv.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                signpos.add(input.getText().length());
                input.setText(input.getText()+"/");
            }
        });
        btnsin.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double  res;
                if(!input.getText().isEmpty())//!input.getText().equals("")
                {//!input.getText()==""  error!!!
                    res=Double.parseDouble(input.getText());
                    show.setText("sin "+input.getText()+" = "+Math.sin(res));
                    input.setText("");
                }
                else if(!result.isEmpty())
                {
                    res=Double.parseDouble(result);
                    show.setText("sin "+result+" = "+Math.sin(res));
                    input.setText("");
                }
            }
        });
        btnequ.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                 
                String in=input.getText();
                if(signpos.size()==0)   return;
                double first;
                String tmp="";
                if(in.charAt(0)=='+'||in.charAt(0)=='-'||in.charAt(0)=='*'||in.charAt(0)=='/')
                {
                    first=Double.parseDouble(result);
                    tmp=result.substring(result.indexOf('=')+1);
                }
                else
                    first=Double.parseDouble(in.substring(0, signpos.get(0)));
                result=String.valueOf(operator(first,0,in));
                show.setText(tmp+in+" = "+result);
                input.setText("");
                signpos.clear();
            }
        });
        btnsqrt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                double  res;
                if(!input.getText().isEmpty())//!input.getText().equals("")
                {//!input.getText()==""  error!!!
                    res=Double.parseDouble(input.getText());
                    show.setText("Sqrt "+input.getText()+" = "+Math.sqrt(res));
                    input.setText("");
                }
                else if(!result.isEmpty())
                {
                    res=Double.parseDouble(result);
                    show.setText("Sqrt "+result+" = "+Math.sqrt(res));
                    input.setText("");
                }
            }
        });
        btnback.addActionListener(new ActionListener() {
             
            @Override
            public void actionPerformed(ActionEvent e) {
                String in=input.getText();
                if(in.isEmpty())    return;
                input.setText(in.substring(0, in.length()-1));
                if(in.endsWith("+")||in.endsWith("-")||in.endsWith("*")||in.endsWith("/"))
                    signpos.remove(signpos.size()-1);
            }
        });
        btnclear.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.setText("");
                signpos.clear();
            }
        });
    }
    private double operator(double operA,int i,String str)
    {
        double operB=i==signpos.size()-1?Double.parseDouble(str.substring(signpos.get(i)+1))
                    :Double.parseDouble(str.substring(signpos.get(i)+1,signpos.get(i+1)));
        switch(str.charAt(signpos.get(i)))
        {
        case '+':
            operA+=operB;
            break;
        case '-':
            operA-=operB;
            break;
        case '*':
            operA*=operB;
            break;
        case '/':
            operA/=operB;
            break;
        }
        if(i==signpos.size()-1)
            return operA;
        else
            return operator(operA,i+1,str);
    }
    public static void main(String[] args) {
        Demo_04_calculater mf=new Demo_04_calculater("°Ö°Ö×öµÄ¼ÆËãÆ÷");
        mf.setVisible(true);
    }
}

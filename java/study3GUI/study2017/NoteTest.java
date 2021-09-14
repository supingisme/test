
import java.awt.*;
import java.io.*;
import java.awt.event.*;
public class NoteTest {
	private Frame f;
	private MenuBar mb;
	private Menu m;
	private MenuItem openItem,closeItem,saveItem;
	private TextArea ta;
	private FileDialog diaOpen,diaSave;
	private File file;
	
	public NoteTest() {
		init();
	}
	private void init() {
		f=new Frame("记事本");
		f.setBounds(400, 300, 600, 500);
		//f.setLayout(new FlowLayout());//使用默认的边界布局管理器 
		
		//设置菜单
		mb=new MenuBar();
		m=new Menu("文件");
		openItem=new MenuItem("打开");
		saveItem=new MenuItem("保存");
		closeItem=new MenuItem("关闭");
		
		m.add(openItem);
		m.add(saveItem);
		m.add(closeItem);
		mb.add(m);
		
		//设置文本区
		ta=new  TextArea();
		
		//建立文件打开和保存的对话框
		diaOpen=new FileDialog(f, "打开", FileDialog.LOAD);
		diaSave=new FileDialog(f, "保存", FileDialog.SAVE);
		
		//将菜单添加到Frame(窗体）中
		f.setMenuBar(mb);
		f.add(ta);
		
		//添加事件
		myEvent();
		//设置窗体显示
		f.setVisible(true);
	}
	private void myEvent() {
		//frame窗体关闭监听
		f.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.exit(0);
			}
		});
		//关闭菜单
		closeItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				System.exit(0);
				
			}
		});
		//保存文件
		saveItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				//先判断文件是否存在？
				  //如果文件不存在则打开文件保存对话框
				if(file==null){
					diaSave.setVisible(true);
					String dirPath=diaSave.getDirectory();
					String fileName=diaSave.getFile();
					//将路径封装成文件对象
					file=new File(dirPath,fileName);
					
					//防止点击取消按钮产生异常，这时直接返回
					if(dirPath==null && fileName==null){
						return;
					}
					//上边的代码保证了文件肯定存在，然后开始保存数据  
					
					try {
						BufferedWriter bufw=new BufferedWriter(new FileWriter(file));
						bufw.write(ta.getText());
						bufw.close();
						
					} catch (Exception e2) {
						throw new RuntimeException("保存失败！");

					}
				}
				
			}
		});
	//打开文件
		openItem.addActionListener(new ActionListener() {
			
			/* (non-Javadoc)
			 * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
			 */
			@Override
			public void actionPerformed(ActionEvent arg0) {
				//启动文件时打开对话框
				diaOpen.setVisible(true);
				//获得所选取文件的目录
				String dirPath=diaOpen.getDirectory();
				//获得选取的文件的文件名字，如果没有选取，则返回null（即点击的是取消按钮），这要处理一下  
				String fileName=diaOpen.getFile();
				if(dirPath==null && fileName==null){
					return;
				}
				//选取有效文件后清空文本区域
				ta.setText("");
				//将选取的文件读到文本区域中
				file=new File(dirPath, fileName);
				//对IO异常进行处理，将文件内容加到文本区域中  
				try {
					BufferedReader bufr=new BufferedReader(new FileReader(file));
					StringBuilder sb=new StringBuilder();
					String line=null;
					while((line=bufr.readLine())!=null){
							sb.append(line+"\r\n");
					}
					ta.append(sb.toString());
					bufr.close();
					
					
				} catch (Exception e) {
					throw new RuntimeException("读取失败"); 
				}
				
				
				
			}
		});
		
	}
	
	public static void main(String[] args) {
		new NoteTest();
	}
	
	
	
}

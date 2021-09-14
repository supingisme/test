
import java.awt.*;
import java.io.*;
import java.awt.event.*;

import javax.swing.*;

class NoteTest {
	private JFrame JFrameTextSave;

	private JMenuBar JMenuBarSave;
	private JMenu JMenuSave;
	private JMenuItem JMenuItemSaveClose,JMenuItemSaveSave;
	private JTextArea JTextAreaSave;
	private FileDialog FileDialogSave;
	private File FileSave;
	
	public NoteTest() {

		JFrameTextSave=new JFrame("New Text");
		JFrameTextSave.setBounds(400, 300, 600, 500);		

		JMenuBarSave=new JMenuBar();
		JMenuSave=new JMenu("File");
		JMenuItemSaveSave=new JMenuItem("Save");
		JMenuItemSaveClose=new JMenuItem("Close");
		
		JMenuSave.add(JMenuItemSaveSave);
		JMenuSave.add(JMenuItemSaveClose);
		JMenuBarSave.add(JMenuSave);
		
		JTextAreaSave=new  JTextArea();
		
		FileDialogSave=new FileDialog(JFrameTextSave, "Save", FileDialog.SAVE);
		

		JFrameTextSave.setJMenuBar(JMenuBarSave);
		JFrameTextSave.add(JTextAreaSave);
		
		JFrameTextSave.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				System.dispose(0);
			}
		});
		JMenuItemSaveClose.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent arg0) {
				System.dispose(0);
				
			}
		});
		JMenuItemSaveSave.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if(FileSave==null){
					FileDialogSave.setVisible(true);
					String dirPath=FileDialogSave.getDirectory();
					String fileName=FileDialogSave.getFile();

					
					if(dirPath==null && fileName==null){
						return;
					}
 
					FileSave=new File(dirPath,fileName);

					try {
						BufferedWriter bufw=new BufferedWriter(new FileWriter(FileSave));
						bufw.write(JTextAreaSave.getText());
						bufw.close();
						
					} catch (Exception e2) {
						throw new RuntimeException("Save Error!");

					}
				}
				
			}
		});

		JFrameTextSave.setVisible(true);
	}


	public static void main(String[] args) {
		new NoteTest();
	}
	
	
	
}

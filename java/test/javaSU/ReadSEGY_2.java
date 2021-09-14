

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseAdapter;
import java.awt.event.WindowAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.Toolkit;
import java.awt.Dimension;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Color;
import java.awt.FileDialog;
import java.awt.Color;
import java.awt.GraphicsEnvironment;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.BasicStroke;
import java.awt.Image;
import java.awt.image.BufferedImage;


import javax.swing.JColorChooser;
import javax.swing.JComponent;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextPane;
import javax.swing.JEditorPane;
import javax.swing.JButton;
import javax.swing.JMenu;
import javax.swing.JPopupMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JProgressBar;
import javax.swing.JToolBar;
import javax.swing.JList;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JDialog;
import javax.swing.JComboBox;
import javax.swing.JCheckBox;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.UIManager;
import javax.swing.BorderFactory;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.Timer;
import javax.swing.JOptionPane;
import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.text.Style;
import javax.swing.text.StyleConstants;
import javax.swing.text.StyledDocument;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.MutableAttributeSet;
import javax.swing.text.AttributeSet;
import javax.swing.border.EmptyBorder;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

import java.text.DateFormat;

import java.util.Calendar;
import java.util.Date;
import java.util.Locale;
import java.util.Scanner;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import java.nio.file.Path;

import javax.imageio.ImageIO;




import java.lang.reflect.Field;
import java.util.ArrayList;


class cjbsegy{
/* reference: cjbsegy.h */

        int tracl, tracr, fldr, tracf, ep, cdp, cdpt;/* int (0-6) */
        short trid, nvs, nhs, duse;/* short (7-10) */
        int offset, gelev, selev, sdepth, gdel, sdel, swdep, gwdep;/* int (11-18) */
        short scalel, scalco;/* short (19-20) */
        int  sx, sy, gx, gy;/* int (21-24) */	
        short counit, wevel, swevel, sut, gut;/* short (25-70) */
        short sstat, gstat, tstat, laga, lagb;	
        short delrt, muts, mute, ns, dt;	
        short gain, igc, igi, corr, sfs;	
        short sfe, slen, styp, stas, stae;	
        short tatyp, afilf, afils, nofilf, nofils;
        short lcf, hcf, lcs, hcs, year;
        short day, hour, minute, sec, timbas;
        short trwf, grnors, grnofr, grnlof, gaps;	
        short otrav;
        float d1, f1, d2, f2, ungpow, unscale;/* float (71-76) */	
        int ntr; /* int (77) */
        short mark, shortpad;/* short (78-79) */
        int  line3d, cdp3d;/* int (80-81) */
        short unass0,unass1,unass2,unass3,unass4 ;
        short unass5,unass6,unass7,unass8,unass9 ;

        String[] segy = {"tracl",   "tracr",   "fldr",    "tracf",   "ep",
                         "cdp",     "cdpt",    "trid",    "nvs",     "nhs",
                         "duse",    "offset",  "gelev",   "selev",   "sdepth",
                         "gdel",    "sdel",    "swdep",   "gwdep",   "scalel",
                         "scalco",  "sx",      "sy",      "gx",      "gy",
                         "counit",  "wevel",   "swevel",  "sut",     "gut",
                         "sstat",   "gstat",   "tstat",   "laga",    "lagb",
                         "delrt",   "muts",    "mute",    "ns",      "dt",
                         "gain",    "igc",     "igi",     "corr",    "sfs",
                         "sfe",     "slen",    "styp",    "stas",    "stae",
                         "tatyp",   "afilf",   "afils",   "nofilf",  "nofils",
                         "lcf",     "hcf",     "lcs",     "hcs",     "year",
                         "day",     "hour",    "minute",  "sec",     "timbas",
                         "trwf",    "grnors",  "grnofr",  "grnlof",  "gaps",
                         "otrav",   "d1",      "f1",      "d2",      "f2",
                         "ungpow",  "unscale", "ntr",     "mark",    "shortpad",
                         "line3d",  "cdp3d",
                         "unass0",  "unass1",  "unass2",  "unass3",  "unass4",
                         "unass5",  "unass6",  "unass7",  "unass8",  "unass9"};

}

class Swap{
        /* float */
        public static float swap (float value){
                int intValue = Float.floatToRawIntBits (value);
                intValue = swap (intValue);
                return Float.intBitsToFloat (intValue);
          }
        /* int */
        public static int swap (int value){
                int b1 = (value >>  0) & 0xff;
                int b2 = (value >>  8) & 0xff;
                int b3 = (value >> 16) & 0xff;
                int b4 = (value >> 24) & 0xff;
                return b1 << 24 | b2 << 16 | b3 << 8 | b4 << 0;
          }
        /* short */
        public static short swap (short value){
                int b1 = value & 0xff;
                int b2 = (value >> 8) & 0xff;
                return (short) (b1 << 8 | b2 << 0);
          }
        /* long */
        public static long swap (long value){
                long b1 = (value >>  0) & 0xff;
                long b2 = (value >>  8) & 0xff;
                long b3 = (value >> 16) & 0xff;
                long b4 = (value >> 24) & 0xff;
                long b5 = (value >> 32) & 0xff;
                long b6 = (value >> 40) & 0xff;
                long b7 = (value >> 48) & 0xff;
                long b8 = (value >> 56) & 0xff;
                return b1 << 56 | b2 << 48 | b3 << 40 | b4 << 32 |
                       b5 << 24 | b6 << 16 | b7 <<  8 | b8 <<  0;
          }
        /* double */
        public static double swap (double value){
                long longValue = Double.doubleToLongBits (value);
                longValue = swap (longValue);
                return Double.longBitsToDouble (longValue);
          }
        /* short array */
        public static void swap (short[] array){
                for (int i = 0; i < array.length; i++)
                        array[i] = swap (array[i]);
          }
        /* int array */
        public static void swap (int[] array){
                for (int i = 0; i < array.length; i++)
                        array[i] = swap (array[i]);
          }
        /* long array */
        public static void swap (long[] array){
                for (int i = 0; i < array.length; i++)
                        array[i] = swap (array[i]);
          }
        /* float array */
        public static void swap (float[] array){
                for (int i = 0; i < array.length; i++)
                        array[i] = swap (array[i]);
          }
        /* double array */
        public static void swap (double[] array){
                for (int i = 0; i < array.length; i++)
                        array[i] = swap (array[i]);
          }
}

class ReadSEGY{

        private static int SEGYNUM = 92;

        public static ArrayList<cjbsegy> readSegy(String filename)
                 throws java.io.IOException,
                        NoSuchFieldException,
                        IllegalAccessException{

                DataInputStream fp = null;
                if(!new File(filename).exists()){  
                        System.out.println("The "+filename +" file dont't exists");
                        return null;  
                    } 
                fp = new DataInputStream(new FileInputStream(new File(filename)));

                cjbsegy hdr = readCjbsegy(fp);
                fp.skip(hdr.ns*4);

                ArrayList<cjbsegy> list = new ArrayList<cjbsegy>();
                list.add(hdr);
                do{   
                        if(fp.available()<=0)break;
                        list.add(readCjbsegy(fp));
                        fp.skip(hdr.ns*4);
                } while(fp.available()>0);

                return list;
        }//read file




        private static cjbsegy readCjbsegy(DataInputStream fp)
                 throws java.io.IOException,
                        NoSuchFieldException,
                        IllegalAccessException{

                cjbsegy hdr = new cjbsegy();

                for(int i = 0; i<SEGYNUM; i++){
                        Field strs = cjbsegy.class.getDeclaredField(hdr.segy[i]);
                        strs.setAccessible(true);

                        if( ( i>=0  && i<=6  ) 
                         || ( i>=11 && i<=18 ) 
                         || ( i>=21 && i<=24 ) 
                         ||   i==77 
                         || ( i>=80 && i<=81 ) )
                                strs.set(hdr,fp.readInt());
                        else if( ( i>=7  && i<=10 ) 
                              || ( i>=19 && i<=20 ) 
                              || ( i>=25 && i<=70 ) 
                              || ( i>=78 && i<=79 )
                              || ( i>=82 && i<=91 )  )
                                strs.set(hdr,fp.readShort());
                        else 
                                strs.set(hdr,fp.readFloat());
                    }
                return hdr;
          }
        public static cjbsegy getMin(ArrayList<cjbsegy> hdrlist)
                 throws java.io.IOException,
                        NoSuchFieldException,
                        IllegalAccessException{

                cjbsegy tmp = hdrlist.get(0);

                for(cjbsegy hdr:hdrlist)
                        for(int i = 0; i<SEGYNUM; i++){
                                Field strlist = cjbsegy.class.getDeclaredField(hdr.segy[i]);
                                Field str     = cjbsegy.class.getDeclaredField(tmp.segy[i]);
                                strlist.setAccessible(true);
                                str    .setAccessible(true);

                                if( ( i>=0  && i<=6  ) 
                                 || ( i>=11 && i<=18 ) 
                                 || ( i>=21 && i<=24 ) 
                                 ||   i==77 
                                 || ( i>=80 && i<=81 ) )
                                        if( (Integer)strlist.get(hdr) < (Integer)str.get(tmp) )
                                               str.set(tmp,(Integer)strlist.get(hdr));
                                else if( ( i>=7  && i<=10 ) 
                                      || ( i>=19 && i<=20 ) 
                                      || ( i>=25 && i<=70 ) 
                                      || ( i>=78 && i<=79 )
                                      || ( i>=82 && i<=91 )  )
                                        if( (Short)strlist.get(hdr) < (Short)str.get(tmp) )
                                               str.set(tmp,(Short)strlist.get(hdr));
                                else 
                                        if( (Float)strlist.get(hdr) < (Float)str.get(tmp) )
                                               str.set(tmp,(Float)strlist.get(hdr));
                             }
                return tmp;
          }

        public static cjbsegy getMax(ArrayList<cjbsegy> hdrlist)
                 throws java.io.IOException,
                        NoSuchFieldException,
                        IllegalAccessException{

                cjbsegy tmp = hdrlist.get(0);

                for(cjbsegy hdr:hdrlist)
                        for(int i = 0; i<SEGYNUM; i++){
                                Field strlist = cjbsegy.class.getDeclaredField(hdr.segy[i]);
                                Field str     = cjbsegy.class.getDeclaredField(tmp.segy[i]);
                                strlist.setAccessible(true);
                                str    .setAccessible(true);

                                if( ( i>=0  && i<=6  ) 
                                 || ( i>=11 && i<=18 ) 
                                 || ( i>=21 && i<=24 ) 
                                 ||   i==77 
                                 || ( i>=80 && i<=81 ) )
                                        if( (Integer)strlist.get(hdr) > (Integer)str.get(tmp) )
                                               str.set(tmp,(Integer)strlist.get(hdr));
                                else if( ( i>=7  && i<=10 ) 
                                      || ( i>=19 && i<=20 ) 
                                      || ( i>=25 && i<=70 ) 
                                      || ( i>=78 && i<=79 )
                                      || ( i>=82 && i<=91 )  )
                                        if( (Short)strlist.get(hdr) > (Short)str.get(tmp) )
                                               str.set(tmp,(Short)strlist.get(hdr));
                                else 
                                        if( (Float)strlist.get(hdr) > (Float)str.get(tmp) )
                                               str.set(tmp,(Float)strlist.get(hdr));
                             }
                return tmp;
          }



        public static void main(String[]args)                 
                throws java.io.IOException,
                        NoSuchFieldException,
                        IllegalAccessException{

                ArrayList<cjbsegy> hdrlist = ReadSEGY.readSegy("v.su");
                //for(cjbsegy hdr:hdrlist)
                //        System.out.println(hdr.cdp);


                cjbsegy minhdr = ReadSEGY.getMin(hdrlist);
                cjbsegy maxhdr = ReadSEGY.getMax(hdrlist);

                System.out.println("min = "+minhdr.sx+", max = "+maxhdr.sx);

          }
}
















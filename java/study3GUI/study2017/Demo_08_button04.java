import java.awt.*;

public class Demo_08_button04 extends Frame {
 Button bNorth,bSouth,bWest,bEast,bCenter;
 public Demo_08_button04(){
  super("边框布局");
  bNorth = new Button("按钮1");
  bSouth = new Button("按钮2");
  bWest = new Button("按钮3");
  bEast = new Button("按钮4");
  bCenter = new Button("按钮5");
  add(bNorth,"North");
  add(bSouth,"South");
  add(bWest,"West");
  add(bEast,"East");
  add(bCenter,"Center");
  setBounds(200,200,300,300);
  setVisible(true);
 }
 public static void main(String[] args){
  new Demo_08_button04();
 }
}

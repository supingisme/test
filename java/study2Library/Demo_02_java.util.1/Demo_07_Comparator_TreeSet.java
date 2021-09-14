/*
2017/6/3
*/

import java.util.*;

class MyComp implements Comparator{

        public int compare(Object a,Object b){

                String aStr, bStr;

                aStr = (String)a;
                bStr = (String)b;

                return bStr.compareTo(aStr);
        }
}

class Demo_07{

        public static void main(String[]args){

                TreeSet ts = new TreeSet(new MyComp());

                ts.add("C");
                ts.add("A");
                ts.add("B");
                ts.add("H");
                ts.add("G");
                ts.add("E");
                ts.add("Z");

                Iterator i = ts.iterator();

                while (i.hasNext()){

                        Object element = i.next();
                        System.out.println(element + "  ");
                }
        }
}

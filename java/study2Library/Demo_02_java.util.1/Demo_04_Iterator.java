/*
2017/6/2
*/
import java.util.*;

class Demo_04{

       public static void main(String[]args){
                
                ArrayList a1 = new ArrayList();
      
                a1.add("C");
                a1.add("A");
                a1.add("E");
                a1.add("B");
                a1.add("D");
                a1.add("F");

                System.out.println("a1 : "+a1);

                Iterator ite = a1.iterator();

                while (ite.hasNext()){
                        
                        Object element = ite.next();
                        System.out.print(element+" ");
                }
        
                System.out.println();

                ListIterator lite = a1.listIterator();

                while(lite.hasNext()){

                        Object element = lite.next();
                        lite.set(element+"+");
                }
                ite = a1.iterator();

                while(ite.hasNext()){

                        Object element = ite.next();
                        System.out.print(element+" ");
                }
                System.out.println();

                while(lite.hasPrevious()){
        
                        Object element = lite.previous();
                        System.out.print(element+" ");
                }
                System.out.println();
                
             

        }
}

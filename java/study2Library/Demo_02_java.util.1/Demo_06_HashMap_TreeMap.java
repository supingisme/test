/*
2017/6/3
*/
import java.util.*;

class Demo_06{

        public static void main(String[]args){

      /*          HashMap hm = new HashMap();

                hm.put("John",new Double(1.1));
                hm.put("Tom",new Double(1.2));
                hm.put("Jane",new Double(1.3));

                Set set = hm.entrySet();

                Iterator i = set.iterator();

                while(i.hasNext()){
        
                        Map.Entry me = (Map.Entry)i.next();
                        System.out.print(me.getKey()+": ");
                        System.out.println(me.getValue());
                }

                double balance = ((Double)hm.get("John")).doubleValue();

                hm.put("John",new Double(balance + 2.));
                
                System.out.println("John's new balance : "+(Double)hm.get("John"));   */

                TreeMap tm = new TreeMap();

                tm.put("John",new Double(1.1));
                tm.put("Tom",new Double(1.2));
                tm.put("Jane",new Double(1.3));

                Set set = tm.entrySet();

                Iterator i = set.iterator();

                while(i.hasNext()){
        
                        Map.Entry me = (Map.Entry)i.next();
                        System.out.print(me.getKey()+": ");
                        System.out.println(me.getValue());
                }

                double balance = ((Double)tm.get("John")).doubleValue();

                tm.put("John",new Double(balance + 2.));
                
                System.out.println("John's new balance : "+(Double)tm.get("John")); 
        }
}

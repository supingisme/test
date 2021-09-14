/*
2017/6/3
*/

import java.util.*;

class Address{

        private String name;
        private String street;
        private String city;
        private String state;
        private String code;

        Address(String n,String s,String c,String st,String cd){

                name = n;
                street = s;
                city = c;
                state = st;
                code = cd;
        }
        
        public String toString(){

                return name + "\n" + street + "\n" + city + "\n" + state + "\n" + code;
        }
}

class Demo_05{

        public static void main(String[]args)
        {
                LinkedList m1 = new LinkedList();

                m1.add(new Address("rong tao","changjiang 66","qingdao","huangdao","4182"));
                m1.add(new Address("peng cheng","changjiang 66","qingdao","huangdao","2222"));

                Iterator itr = m1.iterator();

                while(itr.hasNext()){
                
                        Object element = itr.next();
                        System.out.println(element + "\n");
                }
        }
}

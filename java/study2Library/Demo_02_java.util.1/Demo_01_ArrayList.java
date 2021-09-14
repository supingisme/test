/*
2017/6/1
*/
import java.util.*;

class Demo_01{
	
	public static void main(String[]args){


		/* ArrayList, add, remove */
		ArrayList al = new ArrayList();

		System.out.println("size : "+al.size()+", al : "+al);

		al.add("c");
		al.add("a");
		al.add("b");

		al.add(1,"A2");
		al.add(1,"A3");

		System.out.println("size : "+al.size()+", al : "+al);

		al.remove("a");
		al.remove(2);

		System.out.println("size : "+al.size()+", al : "+al);

		/* ArrayListToArray */
		Object obj[] = al.toArray();

		System.out.println("obj : "+obj[0]);

	}

}

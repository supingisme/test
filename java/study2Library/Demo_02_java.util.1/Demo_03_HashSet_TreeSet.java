/*
2017/6/1
*/
import java.util.*;

class Demo_03{

	public static void main(String[]args){

		HashSet hs = new HashSet();

		hs.add("A");
		hs.add("B");
		hs.add("C");
		hs.add("D");
		hs.add("E");

		System.out.println("hs : "+hs);
		
		TreeSet ts = new TreeSet();

		ts.add("A");
		ts.add("D");
		ts.add("C");
		ts.add("E");
		ts.add("B");

		System.out.println("ts : "+ts);
	}
}

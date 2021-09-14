/*
2017/5/31
*/
class Demo_02 {
	public static void main(String args[]) {

	/*	Double d1 = new Double(3.14159);
		Double d2 = new Double("314159E-5");
		System.out.println(d1 + " = " + d2 + " -> " + d1.equals(d2));  //Double: d1.equals(double d2)	*/

		Double d1 = new Double(1/0.);
		Double d2 = new Double(0/0.);
		System.out.println(d1 + ": " + d1.isInfinite() + ", " + d1.isNaN());
		System.out.println(d2 + ": " + d2.isInfinite() + ", " + d2.isNaN());


	}
}

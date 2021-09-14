// Demonstrate toDegrees() and toRadians().
class Demo_10 {
	public static void main(String args[]) {
		double theta = 120.0;
		System.out.println(theta + " : " +Math.toRadians(theta)+ " : " +(theta/180.0*3.1415926));
		theta = 1.312;
		System.out.println(theta + " : " +Math.toDegrees(theta) + " : " +(theta*180.0/3.1415926));
	}
}

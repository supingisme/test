/*
2017/6/1
*/
class Demo_12{
	public static void main(String[]args){
		Package pkgs[];
		pkgs = Package.getPackages();
		
		for(int i = 0 ; i < pkgs.length ; i ++ ){
			System.out.println(pkgs[i].getName());
			System.out.println(pkgs[i].getImplementationTitle());
			System.out.println(pkgs[i].getImplementationVendor());
			System.out.println(pkgs[i].getImplementationVersion());
		}
	}
}	

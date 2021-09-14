// Demonstrate exec().
class Demo_04 {
	public static void main(String args[]) {

	/*	Runtime r = Runtime.getRuntime();
		Process p = null;
		try {
			p = r.exec("ximage");
		} catch (Exception e) {
			System.out.println(e);
		}	*/

/*
exec( )方法有几个形式可用，而在本例子中展示的是最常用的一种。在新程序开始运
行之后，由exec( )方法返回的Process对象可以被Process方法使用。可以使用destroy( )方法
杀死子进程。waitFor( )方法暂停你的程序直至子进程结束。当子进程结束后，exitValue( )
方法返回子进程返回的值。如果没有问题发生，它通常返回0。下面是前面关于exec( )方法
例子的改进版本。例子被修改为等待直至正在运行的进程退出：
*/
		Runtime r = Runtime.getRuntime();
		Process p = null;
		try {
			p = r.exec("suximage");
			p.waitFor();
		} catch (Exception e) {
			System.out.println("Error executing notepad.");
		}
		System.out.println("Notepad returned " + p.exitValue());

	}
}

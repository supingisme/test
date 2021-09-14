/*
2017/5/11
*/
import java.util.Random;

interface ShareConstants{
	int NO=0;
	int YES=1;
	int MAYBE=2;
	int LATER=3;
	int SOON=4;
	int NEVER=5;
}

class Question implements ShareConstants{
	Random rand=new Random();
	int ask(){
		int prob=(int)(100*rand.nextDouble());
		if(prob<20)return NO;
		else if(prob<40) return YES;
		else if(prob<60) return LATER;
		else if(prob<80) return SOON;
		else if(prob<90) return MAYBE;
		else return NEVER;
	}
}
class Demo implements ShareConstants{
	
	static void answer(int result){
		switch(result){
			case YES:System.out.println("Yes");
				break;
			case NO:System.out.println("No");
				break;
			case MAYBE:System.out.println("Maybe");
				break;
			case SOON:System.out.println("Soon");
				break;
			case LATER:System.out.println("Later");
				break;
			case NEVER:System.out.println("Never");
				break;
			default:System.out.println("Fuck");
		}
	}

	public static void main(String[] args)throws java.io.IOException{

		Question q=new Question();

		for(int i=0;i<10;i++)answer(q.ask());
	}

}

int main(void)
{
	 int x=10,y=20,res;
	  
	switch(x)
	{
		case 2:
		y=10;  
		break;    
		case 4:
		y=33;
		break;
		case 6:
		y=44;
		break;
		case 8:
		y=55;
		break;
		defualt:
		y=100;	
		break;
		default:
		y=9999;
		break;
	} 
	printf("y=%d\n",y);
	   
	   return 0;
}

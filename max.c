#include<stdio.h>
int main(){
	int n1,n2,n3,max;
	printf("enter the three number: \n");
	scanf("%d%d%d",&n1,&n2,&n3);
	if(n1>n2 && n1>n3){
		max=n1;
	}
	else if(n2>n1 && n2>n3){
		max=n2;
	}
	else
	{
		max = n3;
	}
	printf("max num is : %d",max);
	return 0;
}

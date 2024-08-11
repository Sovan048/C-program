#include<stdio.h>
#include<math.h>
int main(){
	int num;
	int root;
	printf("Enter the number: ");
	scanf("%d",&num);
	root=sqrt(num);

	if(root*root==num){
		printf("%d is a perfect square number",num);
	}
	else
	{
		printf("%d is not a perfect square number",num);
	}
	return 0;
}

#include<stdio.h>


int main(){

	int *a;//array -> 5 int values
	int i;

	a = (int*)calloc(5,sizeof(int));//10byte

	if(a == NULL)
		printf("SMW -- TA");
	else{
		for(i=0;i<5;i++){
			printf("\nEnter value");
			scanf("%d",a+i); // &a[i]
		}
		printf("\nArray Elements\n");
		for(i=0;i<5;i++){
			printf("  %d", *(a+i) );
		}
	}

	//a => 200


	return 0;
}

#include<stdio.h>
#define SIZE 5

int main(){
    int a[SIZE]= {10,2,3,4,1};
    int i,j,tmp,x,count=1,min;


    //print
    printf("\nArray Before Sorting\n");
    for(i=0;i<SIZE;i++){
        printf("  %d",a[i]);
    }

    for(i=0;i<SIZE;i++){
        min = i;
        for(j=i+1;j<SIZE;j++){
            if( a[j] < a[min] ){
                min = j ;
            }
        }
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
        printf("\nPass : %d  \n",i+1);
        for(x=0;x<SIZE;x++){
            printf("  %d",a[x]);
        }
    }

    printf("\nArray After Sorting\n");
    for(i=0;i<SIZE;i++){
        printf("  %d",a[i]);
    }


  return 0;
}

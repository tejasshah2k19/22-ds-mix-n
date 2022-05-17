#include<stdio.h>
#define N 7

int main(){

    int a[] = {10,2,3,19,7,6,4};
    int i,x,j,sort;

    printf("\nArray Before Sorting");
    for(x=0;x<N;x++){
        printf(" %d",a[x]);
    }
    //sorting
    for(i=1;i<N;i++){
        sort = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j] > sort ){
                a[j+1]=a[j];
            }else{
                break;
            }
        }
        a[j+1]=sort;
    }

    printf("\nArray after Sorting");
    for(x=0;x<N;x++){
        printf(" %d",a[x]);
    }

    return 0;

}

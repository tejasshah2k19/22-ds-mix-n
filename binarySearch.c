#include<stdio.h>
#define SIZE 10


int main(){

    int a[] = {10,20,30,40,50,60,70,80,90,100};

    int min=0,mid,max=SIZE-1,search,flag=0;

    printf("\nEnter Search Number");
    scanf("%d",&search);

    while(min<=max){

        mid = (min+max)/2 ;

        if(a[mid] == search){
            flag = 1;
            printf("\n%d Found",search);
            break;
        }else if(a[mid] > search ){
            max = mid - 1 ;
        }else{
            min = mid + 1;
        }
    }
    if(flag == 0){
        printf("\n%d Not Found",search);
    }

    return 0;
}


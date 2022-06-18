#include<stdio.h>
#define SIZE 5
void print();
void shiftRight(int count);//3 5

int a[] = {1,2,3,4,5};

int main(){

    print();
    shiftRight(3);
    print();

    return 0;

}

void print(){
    int i;
    printf("\nElements -> ");
    for(i=0;i<SIZE;i++){
        printf(" %d",a[i]);
    }
}

void shiftRight(int count){//0
    int i,tmp;
    if(count !=0 ){//2 , 1 ,0
        tmp = a[SIZE-1]; // 4 5 1 2 3
        for(i=SIZE-1;i>0;i--){
            a[i] = a[i-1];
        }
        a[0] = tmp;
        count--;//0
        shiftRight(count);//0
    }
}





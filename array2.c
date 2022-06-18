#include<stdio.h>
#define SIZE 5
void print();
void distrib();

int a[] = {-1,-2,3,5,-6};
//3 5 -1 -2 -6
int main(){

    print();
    distrib();
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

void distrib(){
   int pos[SIZE],neg[SIZE],p,n,i,j;

   //main array -1 -2 3 5 -6
   //            i
   p=0;
   n=0;
   for(i=0;i<SIZE;i++){
        if(a[i]>0){
            pos[p]=a[i];//
            p++;
        }else{
            neg[n]=a[i];//-1
            n++;
        }
   }

    //merge
    //a -> post + neg
    i=0;
    for(j=0;j<p;j++){
        a[i] = pos[j];
        i++;
    }

    for(j=0;j<n;j++){
        a[i] = neg[j];
        i++;
    }

}





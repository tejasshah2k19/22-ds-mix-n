#include<stdio.h>
#define SIZE 5

int main(){
    int a[SIZE]= {5,4,3,2,1};
    int i,j,tmp,x,count=1;

    //scan
   /* for(i=0;i<SIZE;i++){
        printf("\nEnter number");
        scanf("%d",&a[i]);
    }
    */

    //print
    printf("\nArray Before Sorting\n");
    for(i=0;i<SIZE;i++){
        printf("  %d",a[i]);
    }

    //bubble sort
    for(i=0;i<SIZE-1 && count == 1;i++){

       printf("\nPass %d : \n",i+1);
       count=0;
      for(j=0;j<SIZE-1-i;j++){
        printf("\nComparing %d  and %d\n",a[j],a[j+1]);
        if( a[j] > a[j+1] ){
            tmp = a[j];
            a[j] = a[j+1];
            a[j+1] = tmp;
            count = 1;
            //
        }
      }
      //
        for(x=0;x<SIZE;x++){
            printf("  %d",a[x]);
        }
        //if(count == 0)
          //  break;

    }


    printf("\nArray After Sorting\n");
    for(i=0;i<SIZE;i++){
        printf("  %d",a[i]);
    }


  return 0;
}

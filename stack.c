#include<stdio.h>
#define SIZE 5

int stack[SIZE];
int top=-1;


//insert
void push(){
    int num;

    if(top == SIZE -1 ){
           printf("\nStack OverFlow");
    }else{
        printf("\nEnter Number");
        scanf("%d",&num);
        top++; //0
        stack[top] = num;
    }
}
//delete
void pop(){
    int num;
    if(top == -1){
        printf("\nStackUnderFlow");
    }else{
        num = stack[top];
        top--;
        printf("\n%d pop",num);
    }
}

//print
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("\n%d",stack[i]);
    }
}

void peep(){
    //location 1st

}

int main(){

    int choice;

    while(-1){
        printf("\n0 for Exit\n1 For PUSH\n2 For POP\n3 For Display\nPlease Enter Your Choice");
        scanf("%d",&choice);

        switch(choice){
            case 0:
                exit(0);
            case 1:
                    push();break;
            case 2:
                    pop();break;
            case 2+1:
                    display();break;
            default:
                    printf("\nInvalid Choice");
        }//switch
    }//while
    return 0;
}

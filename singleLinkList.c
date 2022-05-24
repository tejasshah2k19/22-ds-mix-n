#include<stdio.h>

void insertData();
void displayData();


//10 -> 20 -> 30 -> 40
struct node {
    //
    int data;//number
    struct node *next;

}*head=NULL;


int main(){

    int ch;

    while(1){
        printf("\n0 For exit\n1 For Add\n2 For Display");
        printf("\nEnter your choice!!");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                insertData();
                break;
            case 2:
                displayData();
                break;
            case 0:
                exit(0);

        }
    }

    return 0;
}


void insertData(){
    struct node *tmp,*p;
    int num;

    printf("\nEnter number");
    scanf("%d",&num);//100 200 300

    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = num;
        head->next = NULL;
    }else{
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = NULL;

        //we need to search last node
        p=head;
        while(p->next != NULL )
                p = p->next; //p++

        p->next = tmp;

    }

}

void displayData(){

}


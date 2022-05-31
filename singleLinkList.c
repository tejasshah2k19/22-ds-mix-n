#include<stdio.h>

void insertData();
void displayData();
void deleteNode();

//10 -> 20 -> 30 -> 40
struct node {
    //
    int data;//number
    struct node *next;

}*head=NULL;


int main(){

    int ch;

    while(1){
        printf("\n0 For exit\n1 For Add\n2 For Display\n3 for delete");
        printf("\nEnter your choice!!");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                insertData();
                break;
            case 2:
                displayData();
                break;
            case 3:
                deleteNode();
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

    struct node *p ;
        p=head;

        while(p != NULL ){
                printf("%d->",p->data);
                p = p->next; //p++
        }



}

void deleteNode(){

    //last node delete
    struct node *p,*q;
    p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    q = head;
    while(q->next   != p )
    {
        q=q->next;
    }
    printf("\n%d removed ",p->data);
    free(p);
    q->next = NULL;

}

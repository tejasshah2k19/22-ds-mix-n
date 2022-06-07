#include<stdio.h>

void insertData();//insertATLast
void displayData();
void deleteNode();//deleteLast
void search();
void insertAtBeg();//
void deleteNodeBeg();//deletebeg
void insertAtAnyAfter();//after
void insertAtAnyBefore();//before
void deleteSelectedNode();//deleteAny

//10 -> 20 -> 30 -> 40
struct node {
    //
    int data;//number
    struct node *next;

}*head=NULL;


int main(){

    int ch;

    while(1){
        printf("\n0 For exit\n1 For Add\n2 For Display\n3 for delete\n4 for Search");
        printf("\n5 for InsertAtBeg\n6 for deleteBeg");
        printf("\n7 For InsertAnyAfter\n8 for insertAtAnyBefore\n9 for DeleteSelectedNode\n");
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
            case 4:
                search();
                break;
            case 5:
                insertAtBeg();
                break;
            case 6:
                deleteNodeBeg();
                break;
            case 7:
                insertAtAnyAfter();
                break;
            case 8:
                insertAtAnyBefore();
                break;
            case 9:
                deleteSelectedNode();
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


void search(){
    struct node *p;
    int num,isFound = 0 ;//0 nt
    printf("\nEnter number");
    scanf("%d",&num);


    p = head;
    while(p!=NULL){
        if(p->data == num){
            isFound=1;
            break;
        }
        p=p->next;
    }
    if(isFound == 0 )
        printf("\n%d Not Present In LinkedList",num);
    else
        printf("\n%d Present In LinkedList",num);

}


void insertAtBeg(){

    int num;
    struct node *tmp;

    if(head!=NULL){
        printf("\nEnter number");
        scanf("%d",&num);

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = num;
        tmp->next = head;
        head = tmp;

    }else{
        printf("\n create at least 1 node ");
    }


}

void deleteNodeBeg(){
    struct node *p;
    if(head == NULL)
        printf("\nList is Empty");
    else{
        p = head;
        head = head->next;
        printf("\n%d removed ",p->data);
        free(p);
    }

}


void insertAtAnyAfter(){
    int search,isFound = 0;//0 => not found
    int num;
    struct node *p,*tmp;

    printf("\nEnter node data after you want to create new data");
    scanf("%d",&search);

    p = head;

    while(p!=NULL){
        if(p->data == search){
            isFound = 1;//found
            break;
        }
        p = p->next;
    }

    if(isFound == 1){
        printf("\nEnter new Num");
        scanf("%d",&num);

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data=num;
        tmp->next = p->next;
        p->next = tmp;

    }else{
        printf("\nSource Data Invalid");
    }


}


void insertAtAnyBefore(){
    int search,isFound=0,num;
    struct node *p,*tmp,*q;

    printf("\nEnter node data before you want to create new data");
    scanf("%d",&search);

    p=head;
    q=head;
    while(p!=NULL){
        if(p->data == search){
            isFound = 1;
            break;
        }
        q=p;
        p = p->next;
    }

    if(isFound == 0){
        printf("\nSource Not found ");
    }else if(p == head ){
        printf("\nInvalid Source data\nCant add in Beginning");

        //insertAtBeg
    }
    else if(isFound == 1 )
    {
        printf("\nEnter new number");
        scanf("%d",&num);

        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data=num;
        q->next = tmp;
        tmp->next=p;
    }else{
            printf("\nSMW PTA");
    }
}

void deleteSelectedNode(){
    int search,isFound = 0;
    struct node *p,*q;

    printf("\nEnter number - delete");
    scanf("%d",&search);

    p = head;

    while(p!=NULL){

        if(p->data == search){
            isFound =1;
            break;
        }
        q=p;
        p=p->next;
    }

    if(isFound == 1){
            printf("\n%d Removed",search);
            q->next= p->next;
            free(p);
    }else{
        printf("\nNode Not Found");
    }
}





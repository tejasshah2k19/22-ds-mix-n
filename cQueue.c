#define SIZE 5

int q[SIZE];
int f=-1;
int r=-1;

void insert(){
    int num;
    if(r == SIZE - 1  && f == 0){
        printf("\nQueue is Full");
    }else if(r == f - 1){
        printf("\nQueue is Full");
    }else{
        printf("\nEnter num");
        scanf("%d",&num);

        if( r== SIZE -1 )
            r = 0 ;
        else
            r++;//0

        q[r] = num;

        if(f == -1 )
            f++;
    }
}

//add cQ delete logic[s]
void deleteQ(){

    if(f == - 1){
        printf("\nQueue is empty..");
    }else{
        printf("\n%d deleted",q[f]);
        if(f == r){
            f=-1;r=-1;
        }else{
            f++;
        }
    }


}
void display(){

    int i;
    printf("\nContent Of The Queue...\n");

    if(r < f ){
        //c queue display
        for(i=f;i<SIZE;i++){
            printf("  %d",q[i]);
        }
        for(i=0;i<=r;i++){
            printf("  %d",q[i]);
        }
    }else{

        for(i=f;i<=r;i++){
            printf("  %d",q[i]);
        }
    }
}

void search(){

    int searchNum,i,counter=0,isFound=0;
    printf("\nEnter number that you want to search:");
    scanf("%d",&searchNum);

    for(i=f;i<=r;i++){
        counter++;
        if(q[i] == searchNum){
            isFound = 1;
            printf("\n%d Found at %d location ",searchNum,counter);
            break;
        }
    }
    if(isFound == 0 ){ // if(!isFound)
        printf("\n%d NOT FOUND",searchNum);
    }

}



void search2(){

    int searchNum,i,j,counter=0,isFound=0;
    printf("\nEnter number that you want to search:");
    scanf("%d",&searchNum);

    for(i=f,j=r;i<=r/2;i++,j--){
        counter++;
        if(q[i] == searchNum || q[j] == searchNum){
            isFound = 1;
            printf("\n%d Found",searchNum);
            break;
        }
    }
    if(isFound == 0 ){ // if(!isFound)
        printf("\n%d NOT FOUND",searchNum);
    }

}
void trimQ(){
    int i,j;
    for(i=f;i<=r;i++){
        if(q[i] != 0)
            break;
    }
    for(j=f;i<=r;j++,i++){
        q[j] = q[i];
    }
    r = j-1;

}
int main(){
        int choice;

        while(1){
            printf("\n0 For Exit\n1 For Insert\n2 For Delete\n3 For Display\n4 For Search\nEnter choice..");
            scanf("%d",&choice);

            switch(choice){
                case 0:
                    exit(0);
                case 1:
                    insert();break;
                case 2:
                    deleteQ();break;
                case 3:
                    display();break;
                case 4:
                    search();break;

            }//switch
        }//while


}



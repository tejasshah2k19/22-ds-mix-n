#include<stdio.h>

struct node {
    int data;
   struct node* left;
   struct node* right;
}*root=NULL;

//create node - num - data assign
struct node* createNode(int num){//10
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

void insertNode(int data){// 5

    if(root == NULL ){
        root = createNode(data);
    }else{
        if(root->data < data ){//10
            //right
            root->right = createNode(data);
        }else{
            //left
            root->left = createNode(data);
        }

    }
}

int main(){
    /*10 20 30

        10
     5      20

  */
  insertNode(10);
  insertNode(20);
  insertNode(5);



    return 0;
}

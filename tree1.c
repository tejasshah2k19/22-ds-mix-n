#include<stdio.h>

struct node {
    int data;
   struct node* left;
   struct node* right;
}*root=NULL;


struct node* createNode(int num){//10
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = num;
    tmp->left = NULL;
    tmp->right = NULL;

    return tmp;
}

int main(){
    /*10 20 30

        10
    20      30

  */
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);

    return 0;
}

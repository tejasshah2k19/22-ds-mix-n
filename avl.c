#include<stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;

    int height; // ??
}*root=NULL;


struct node* createNode(int data){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data ;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->height = 1;
    return tmp;
}

int calculateHeight(struct node* node){//10

    int lh=0;
    int rh=0;
    if(node->left == NULL){
        lh = 0;
    }else{
        lh = node->left->height;
    }
    if(node->right == NULL){
        rh = 0;
    }else{
        rh = node->right->height;//2
    }

    if(lh >= rh ){
        return 1+lh;
    }else{
        return 1+rh;//1+2 =>  3
    }
}
struct node* insertNode(struct node *node,int data){// (10,30) => (20,30) =>  (NULL,30)
    if(node == NULL){
        return createNode(data);
    }
    if(data < node->data ){
        node->left = insertNode(node->left,data);
    }else {
        node->right = insertNode(node->right,data);//10,30 =>
        //10->right = insertNode(20,30);
        //20->right =30;
    }
    node->height = calculateHeight(node); //10
    return node;
}

int main(){

    root = insertNode(root,10);
           insertNode(root,20);
           insertNode(root,30);//(10,30)


    return 0;
}

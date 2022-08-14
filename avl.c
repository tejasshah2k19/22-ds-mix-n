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

int calculateBalanceFactor(struct node *root){
        int lh =0,rh=0;
        if(root == NULL){
            return 0;
        }
        if(root->left != NULL){
            lh = root->left->height;
        }
        if(root->right != NULL){
            rh = root->right->height;
        }

        return lh - rh;
}
struct node* rightRotate(struct node *node){
    struct node *nodeleft,*nodeleftright;
    nodeleft = node->left;
    nodeleftright = node->left->right;

    nodeleft->right = node;
    node->left = nodeleftright;
    return nodeleft;
}


struct node* leftRotate(struct node *node){
    struct node *noderight,*noderightleft;
    noderight = node->right;
    noderightleft = node->right->left;

    noderight->left = node;
    node->right = noderightleft;
    return noderight;
}



struct node* insertNode(struct node *node,int data){// (10,30) => (20,30) =>  (NULL,30)
    int bf;
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
    bf = calculateBalanceFactor(node);
    printf(" %d(%d) ",node->data,bf);
    if( !(bf >-2 && bf < 2) ){
        printf("***Rotation**** %d",node->data);
        if(bf < 0 && node->right->data < data ){
            printf(" RR ");

        }else if(bf < 0 && node->right->data > data){
            printf(" RL ");
        }else if(bf > 0 && node->left->data > data){
            printf(" LL ");
        }else if(bf > 0 && node->left->data < data){
            printf(" LR ");
        }
    }


    return node;
}

void inOrder(struct node *root){
    if(root==NULL)
        return;
    inOrder(root->left);
    printf(" %d(%d) ",root->data,root->height);
    inOrder(root->right);
}

int main(){
           printf ("\nInserting 100");
    root = insertNode(root,100);

         // printf ("\nInserting 150");
          // insertNode(root,150);


            //printf ("\nInserting 300");
           //insertNode(root,300);

           printf ("\nInserting 50");
          insertNode(root,50);//(10,30)

           //printf ("\nInserting 30");
           //insertNode(root,30);//

            //printf ("\nInserting 20");
           //insertNode(root,20);//

         //  printf ("\nInserting 125");
         //  insertNode(root,125);

            printf ("\nInserting 90");
            insertNode(root,90);

            printf("\nTREE\n");
           inOrder(root);

    return 0;
}

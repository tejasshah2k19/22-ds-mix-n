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
    //printf("\nReCalculate Height %d",node->data);
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

    node->height = calculateHeight(node);
    nodeleft->height = calculateHeight(nodeleft);
    return nodeleft;
}


struct node* leftRotate(struct node *node){ //100
    struct node *noderight,*noderightleft;
    noderight = node->right; // 150
    noderightleft = node->right->left;//null

    noderight->left = node;// 100<-150->300
    node->right = noderightleft;

    node->height = calculateHeight(node);
    noderight->height = calculateHeight(noderight);

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

    if( !(bf >-2 && bf < 2) ){
        printf("\n***Rotation**** %d",node->data);
        if(bf < 0 && node->right->data < data ){
            printf(" RR ");
            return leftRotate(node);//20

        }else if(bf < 0 && node->right->data > data){
            printf(" RL ");
            node->right = rightRotate(node->right);
            return leftRotate(node);

        }else if(bf > 0 && node->left->data > data){
            printf(" LL ");
            return rightRotate(node);

        }else if(bf > 0 && node->left->data < data){
            printf(" LR ");
            node->left = leftRotate(node->left);
            return rightRotate(node);
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
struct node* inorderSuccessor(struct node *root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}
struct node* deleteNode(struct node *root,int key){
        int bf=0;
        struct node *tmp;
        if(root==NULL)
            return root;
        printf("\nroot is %d",root->data);
        if(root->data == key ){
            //delete
                if(root->left == NULL && root->right == NULL){
                    free(root); //deallocate
                    return NULL;
                }else if(root->left != NULL && root->right == NULL){
                        //delete -> left -> data
                        tmp = root->left;
                        free(root);
                        return tmp;//parent
                }else if(root->right != NULL && root->left == NULL){
                    tmp = root->right;
                    free(root);
                    return tmp;
                }else {
                    //two child
                    tmp = inorderSuccessor(root->right);
                    root->data = tmp->data;
                    root->right = deleteNode(root->right,tmp->data);
                }

        }else if(key > root->data){
                //right
                root->right = deleteNode(root->right,key);
        }else if(key < root->data){
            //left
            root->left= deleteNode(root->left,key);
        }

        //deletion done
        if(root == NULL)
            return root;


        //height
        //bf
            root->height = calculateHeight(root); //10
    /*
            bf = calculateBalanceFactor(root);
            printf(" %d(%d) ",root->data,bf);
            if( !(bf >-2 && bf < 2) ){
                printf("\n***Rotation**** %d",root->data);
                if(bf < 0 && root->right->data < key ){
                    printf(" RR ");
                    return leftRotate(root);//20

                }else if(bf < 0 && root->right->data > key){
                    printf(" RL ");
                    root->right = rightRotate(root->right);
                    return leftRotate(root);

                }else if(bf > 0 && root->left->data > key){
                    printf(" LL ");
                    return rightRotate(root);

                }else if(bf > 0 && root->left->data < key){
                    printf(" LR ");
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }
    */
        return root;
};

int main(){
          /* printf ("\nInserting 100");
           root = insertNode(root,100);

           printf ("\nInserting 50");
          root  = insertNode(root,50);


        printf ("\nInserting 30");
          root=  insertNode(root,30);// root 150
*/
           //printf ("\nInserting 50");
          //insertNode(root,50);//(10,30)

           //printf ("\nInserting 30");
           //insertNode(root,30);//

            //printf ("\nInserting 20");
           //insertNode(root,20);//

         //  printf ("\nInserting 125");
         //  insertNode(root,125);

           // printf ("\nInserting 90");
            //insertNode(root,90);

            printf("\ninserting 1");
            root= insertNode(root,1);
            printf("\ninsertion done 1");
            inOrder(root);


            printf("\ninserting 2");
            root= insertNode(root,2);
            printf("\ninsertion done 2");
            inOrder(root);


            printf("\ninserting 3");
            root= insertNode(root,3);
            printf("\ninsertion done 3");
            printf("\n====\n");
            inOrder(root);


            printf("\ninserting 4");
            root= insertNode(root,4);
            printf("\ninsertion done 4");
            inOrder(root);



            printf("\ninserting 5");
            root= insertNode(root,5);
            printf("\ninsertion done 5");


            printf("\ninserting 6");
            root= insertNode(root,6);
            printf("\ninsertion done 6");


            printf("\ninserting 7");
            root= insertNode(root,7);
            printf("\ninsertion done 7");


            printf("\n ROOT => %d",root->data);
            printf("\nTREE\n");
            inOrder(root);

            printf("\n---Deletion---");
            root = deleteNode(root,4);
            printf("\nTREE\n");
            inOrder(root);


    return 0;
}

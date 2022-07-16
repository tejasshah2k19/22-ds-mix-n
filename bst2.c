#include<stdio.h>

struct node {
    int data;
    struct node *left,*right;
}*root=NULL;

//BST ->
//    parent --> small -> left
                //big --> right
struct node* createNode(int num){
    struct node *tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = num ;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;

}
struct node* addNode(struct node *root,int num){//[10],30  [20],30

    if(root == NULL){
        root = createNode(num);
    }else{
        if(root->data < num){
            //right
           root->right = addNode(root->right,num);//[NULL],30
        }else{
            //left
           root->left = addNode(root->left,num);//NULL,5
        }
    }
    return root;
}

void preOrder(struct node *root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}


void postOrder(struct node *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    inOrder(root->right);
    printf("%d ",root->data);
}
int main(){
        int num;
    //root =  addNode(root,10);
       //     addNode(root,20);
        //    addNode(root,5);
          //  addNode(root,30);
           // addNode(root,2);

           //preOrder(root);
           // inOrder(root);
            scanf("%d",&num)
            root = addNode(root,num);

            while(1){
                printf("\nEnter number and -1 for exit");
                scanf("%d",&num);
                if(num == -1){
                    break;
                }
                addNode(root,num);
            }

            printf("\nInOrder\n");
            inOrder(root);
            printf("\nPreOrder\n");
            preOrder(root);
            printf("\nPostOrder\n");
            postOrder(root);
    return 0;

}
	/*	root - left - right  [ PRE order  ]
		left - root - right  [ In order   ]
		left - right - root  [ POST order ]

 		IN   30 40 50 70 80 90
		PRE  50 40 30 80 70 90
		POST 30 40 70 90 80 50
	 */

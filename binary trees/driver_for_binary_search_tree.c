#include "binary_tree.c"
int main(){
    struct Node *root = NULL;

    struct Node *newNode = NULL;

    int i = 0;
    int arr[] = {30, 25, 17, 27, 40, 35, 45};

    for(i=0; i<=6; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->left = newNode->right = newNode->insuc = NULL;
        insertNode(&root, newNode);
    }

    inOrder(root);
    printf("\n");
    struct Node* suc=successor(root,17);
    if(!suc){printf("No successor\n");}
    else{printf("%d is the successor\n",suc->data);}
    struct Node* pre=predecessor(root,45);
    if(!pre){printf("No predecessor\n");}
    else{printf("%d is the predecessor\n",pre->data);}
    struct Node* par=findParent(root, 100);
    if(!par){printf("No parent\n");}
    else{printf("%d is the parent\n",par->data);}
    addsucc(root,root);
    printf("Inorder succ of root is %d\n",root->insuc->data);
    struct Node* parent=NULL;
    struct Node* reqNode=NULL;
    int flag;
    printf("\n%d\n",searchNode(root,40,&parent,&reqNode,&flag));
    printf("%d\n",(reqNode)->data);
    preOrder(root);



    printf("\n");
    postOrder(root);
    printf("\n");
    bft(root);
    printf("\n");
    printf("%d\n",getMax(root,&parent,&newNode));
    printf("%d\n",newNode->data);
    printPathInOrder(root, 27);
    printf("\n");
    path(root, 40,17);
    printf("\n");

    deleteNode(&root, 17);

    inOrder(root);

    printf("\n");

    deleteNode(&root, 25);

    inOrder(root);

    printf("\n");
    deleteNode(&root, 30);

    inOrder(root);

    printf("\n");
    printf("-----\n");

    destroy(&root);
    printf("-----\n");

    inOrder(root);

    printf("\n");
    return 0;

}

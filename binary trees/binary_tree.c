#include "binary_tree.h"
struct Node{
    int data;
    struct Node *left, *right, *insuc;
};
int enqueue(struct queues1* q, struct Node* node){
    struct Node1* newNode=(struct Node1*)malloc(sizeof(struct Node1));
    if(!newNode){
        return 0;
    }
    newNode->nodePtr=node;
    newNode->next=NULL;
    if (!(q->head)){
        q->head=newNode;
        q->tail=newNode;
        return 1;
    }
    q->tail->next=newNode;
    q->tail=newNode;
    return 1;
}
int dequeue(struct queues1* qPtr, struct Node** node){
    if(!(qPtr)->head){
        return 0;
    }
    struct Node1 *iter=qPtr->head;
    qPtr->head=qPtr->head->next;
    *node=iter->nodePtr;
    free(iter);
    if(qPtr->head==NULL){
        qPtr->tail=NULL;
    }
    return 1;
}
int insertNode(struct Node** root, struct Node* newNode){
    if(!(*root)){
        *root=newNode;
        return 1;
    }
    if((*root)->data>newNode->data){
        return insertNode(&(*root)->left,newNode);
    }
    else{
        return insertNode(&(*root)->right,newNode);
    }
}
int searchNode(struct Node* root, int key, struct Node** parent, struct Node** reqNode, int* flag){
    if (!root){
        *reqNode=NULL;
        *parent=NULL;
        return 0;
    }
    *reqNode=root;
    printf("\n%d\n",(*reqNode)->data);
    if(root->data>key){
        *parent=root;
        *flag=0;
        searchNode(root->left,key,parent,reqNode,flag);
    }
    else if (root->data<key){
        *parent=root;
        *flag=1;
        searchNode(root->right,key,parent,reqNode,flag);
    }
    else{
        return 1;
    }
    printf("\n%d\n",(*reqNode)->data);
    return 1;
}
int getMax(struct Node* root, struct Node ** parent, struct Node** maxNode){
    if(!root){
        return 0;
    }
    *maxNode=root;
    if(!root->right){
        return 1;
    }
    *parent=root;
    return getMax(root->right, parent, maxNode);
}
int inOrder(struct Node *rootPtr){
    if(!rootPtr){
        return 0;
    }
    inOrder(rootPtr->left);
    printf("%d ",rootPtr->data);
    inOrder(rootPtr->right);
    return 1;
}

struct Node* predecessor(struct Node* root, int key){
    if(!root){return NULL;}
    struct Node* pre;
    if(root->data>key){
        pre=predecessor(root->left,key);
    }
    else if(root->data<key){
        pre=predecessor(root->right,key);
    }
    else{
        struct Node* iter=root->left;
        while(iter && iter->right){
            iter=iter->right;
        }
        return iter;
    }
    if(pre==NULL){
        if(root->data<key){
            return root;
        }
        else{
            return NULL;
        }
    }
    else{
        return pre;
    }

}

struct Node* successor(struct Node* root, int key){
    if(!root){
        return NULL;
    }
    struct Node* suc;
    if(root->data<key){
        suc=successor(root->right,key);
    }
    else if(root->data>key){
        suc=successor(root->left,key);
    }
    else{
        struct Node* iter=root->right;
        while(iter && iter->left){
            iter=iter->left;
        }
        return iter;
    }
    if(suc==NULL){
        if(root->data>key){
            return root;
        }
        else{
            return NULL;
        }
    }
    else{
        return suc;
    }
}

int preOrder(struct Node *rootPtr){
    if(!rootPtr){
        return 0;
    }
    printf("%d ",rootPtr->data);
    preOrder(rootPtr->left);
    preOrder(rootPtr->right);
    return 1;
}

int postOrder(struct Node *rootPtr){
    if(!rootPtr){
        return 0;
    }
    postOrder(rootPtr->left);
    postOrder(rootPtr->right);
    printf("%d ",rootPtr->data);
    return 1;
}
int bft(struct Node* root){
    if(!root){
        return 0;
    }
    struct Node* node=NULL;
    struct queues1* q=(struct queues1*)malloc(sizeof(struct queues1));
    q->head=NULL;
    q->tail=NULL;
    enqueue(q,root);
    while(q->head){
        dequeue(q,&node);
        printf("%d ",(node)->data);
        if((node)->left){
            enqueue(q,(node)->left);
        }
        if((node)->right){
            enqueue(q,(node)->right);
        }
    }
    return 1;
}

int deleteNode(struct Node** root, int key){
    if(!root){
        return 0;
    }
    struct Node *parent=NULL, *reqNode=NULL;
    int flag;
    searchNode(*root,key,&parent,&reqNode,&flag);
    if(!(parent)){
        parent=reqNode;
    }
    if(!(reqNode)->left && !(reqNode)->right){
        if(flag){
            (parent)->right=NULL;
        }
        else{
            (parent)->left=NULL;
        }free(reqNode);
    }
    else if(!(reqNode)->left){
        if(flag){
            (parent)->right=reqNode->right;
        }
        else{
            (parent)->left=reqNode->right;
        }free(reqNode);
    }
    else if(!(reqNode)->right){
        if(flag){
            (parent)->right=reqNode->left;
        }
        else{
            (parent)->left=reqNode->left;
        }free(reqNode);
    }
    else{
        struct Node* maxNode=NULL;
        getMax(*root,&parent,&maxNode);
        if(parent->left==maxNode){
            parent->left=NULL;
        }
        else{
            parent->right=NULL;
        }
        reqNode->data=maxNode->data;
        free(maxNode);
    }
    return 1;
}
int destroy(struct Node** root){
    if(*root){
        destroy(&(*root)->left);
        destroy(&(*root)->right);
        deleteNode(root,(*root)->data);
        *root=NULL;
    }
    return 1;
}
int printPathInOrder(struct Node* root, int key){
    if(!root){
        return 0;
    }
    if (root->data>key){
        printPathInOrder(root->left, key);
    }
    else if (root->data<key){
        printPathInOrder(root->right, key);
    }
    printf("%d->",root->data);
    return 1;
}
int path(struct Node* root, int key1, int key2){
    if (!root){
        return 0;
    }
    int max, min;
    struct Node* iter=root;
    if(key1>key2){
        max=key1;
        min=key2;
    }else{
        min=key1;
        max=key2;
    }
    while(iter && !(iter->data<=max && iter->data>=min)){
        if(iter->data>max){
            iter=iter->left;
        }
        else{
            iter=iter->right;
        }
    }
    if(!iter){
        return 0;
    }
    printPathInOrder(iter,min);
    printPathInOrder(iter->right,max);
    return 1;
}

struct Node* findParent(struct Node* root, int key){
    if(!root){return NULL;}
    struct Node* par;
    if(root->data>key){
        par=findParent(root->left,key);
    }
    else if(root->data<key){
        par=findParent(root->right,key);
    }
    else{
        return root;
    }
    if(par==NULL){
        return NULL;
    }
    else if(par->data==key){
        return root;
    }
    else{
        return par;
    }
}

int addsucc(struct Node* root, struct Node* subroot){
    if(!root || !subroot){return 0;}
    addsucc(root, subroot->left);
    addsucc(root, subroot->right);
    struct Node* suc=successor(root,subroot->data);
    subroot->insuc=suc;
    return 1;
}

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
struct Node;
struct Node1{
    struct Node* nodePtr;
    struct Node1* next;
};
struct queues1{
    struct Node1 *head, *tail;
};
int enqueue(struct queues1*, struct Node*);
int dequeue(struct queues1*, struct Node**);
int insertNode(struct Node**, struct Node*);
int searchNode(struct Node*,int, struct Node**, struct Node**, int*);
struct Node* findParent(struct Node*, int);
int getMax(struct Node*, struct Node**, struct Node**);
int deleteNode(struct Node**, int);
int printPathInOrder(struct Node*, int);
int path(struct Node*, int, int);
int inOrder(struct Node*);
struct Node* successor(struct Node*, int);
struct Node* predecessor(struct Node*, int);
int addsucc(struct Node*, struct Node*);
int preOrder(struct Node*);
int postOrder(struct Node*);
int bft(struct Node* root);
int destroy(struct Node**);

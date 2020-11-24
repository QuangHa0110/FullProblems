#include<stdio.h>
typedef struct Node
{
    int value;
    Node *next;
}Node;

Node * makeNode(int data){
    Node*p = new Node();
    p->value=data;
    p->next=NULL;
    return p;
}

int main(){
    return 0;
}
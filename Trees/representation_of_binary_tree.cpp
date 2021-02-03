#include<iostream>
using namespace std;



struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};



struct bt *createNode(int data)
{
    struct bt *node=(struct bt*)malloc(sizeof(struct bt));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

int main()
{
    
    struct bt *root=createNode(1);
    struct bt *n2=createNode(3);
    struct bt *n1=createNode(2);

    
    root->left=n1;
    root->right=n2;
    return 0;
}
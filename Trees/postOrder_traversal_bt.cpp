#include<iostream>
using namespace std;

struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};

struct bt *newNode(int data)
{
    struct bt *node=(struct bt*)malloc(sizeof(struct bt));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
    
}

// function for postOrder traversal
void postOrder(struct bt* root)
{
    if(root!=NULL)
    {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
    }
}

int main()
{
    // root node
    struct bt *root=newNode(1);
    struct bt *p1=newNode(2);
    struct bt *p2=newNode(3);
    struct bt *p3=newNode(4);
    struct bt *p4=newNode(5);
    struct bt *p5=newNode(6);
    struct bt *p6=newNode(7);

    //linking all the nodes
    root->left=p1;
    root->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->left=p5;
    p2->right=p6;

    // calling preorder traversal function
    postOrder(root);
    return 0;
}
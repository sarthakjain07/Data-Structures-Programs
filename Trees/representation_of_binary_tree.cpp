#include<iostream>
using namespace std;

// structure of binary trees
struct bt{
    int data;
    struct bt *left;
    struct bt *right;
};

// function to create all the nodes of binary trees
struct bt *createNode(int data)
{
    struct bt *node=(struct bt*)malloc(sizeof(struct bt));
    node->data=data;//assigning data to the node
    // assigning the left and right pointers value NULL initially
    node->left=NULL;
    node->right=NULL;
    return node;
}

int main()
{
    // creating root node along with the nodes n1 and n2
    struct bt *root=createNode(1);
    struct bt *n2=createNode(3);
    struct bt *n1=createNode(2);

    // linking the nodes n1 and n2 with the root nodes   
    root->left=n1;
    root->right=n2;
    return 0;
}
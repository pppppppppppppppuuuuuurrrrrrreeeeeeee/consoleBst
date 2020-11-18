#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ul;


struct Node {
    pair<string, ul> data;
    struct Node *left, *right;
};


Node* newNode(pair<string, ul> newData)
{
    Node* temp = new Node;

    temp->data.first = newData.first;
    temp->data.second = newData.second;


    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* insert(Node* root, pair<string, ul> newData)
{
    Node* newnode = newNode(newData);
    Node* x = root;
    Node* y = NULL;

    while (x != NULL) {
        y = x;
        if (newData.second < x->data.second)
            x = x->left;
        else
            x = x->right;
    }
    if (y == NULL)
        y = newnode;

    else if (newData.second < y->data.second)
        y->left = newnode;

    else
        y->right = newnode;

    return y;
}

void Inorder(Node* root)
{   
    if (root == NULL)
        return;
    else {
        Inorder(root->left);
        cout << "pid: " << root->data.first << "  |    plate value : " << root->data.second << "\n";
        Inorder(root->right);
    }
}

bool search(struct Node *r, pair<string, ul> p)
{
    while (r != NULL)
    {
        if (p.second > r->data.second)
            r = r->right;
 
        else if (p.second < r->data.second)
            r = r->left;
        else
            return true;
    }
    return false;
}


Node* root = NULL;
int main()
{


    pair<string, ul> p0;
    p0.first = "0";
    p0.second = 0;
    root = insert(root, p0);

    
    pair<string, ul> p;
    p.first = "1";
    p.second = 123456789;
    insert(root, p);
    
    p.first = "2";
    p.second = 222222222;
    insert(root, p);

    Inorder(root);

    p.first = "2";
    p.second = 222222223;
    if(search(root, p)) cout << "YEs\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    TreeNode *root;
    bool searchNode(int data, TreeNode *root)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        if (root->data < data)
            return searchNode(data, root->right);
        else
            return searchNode(data, root->left);
    }
    TreeNode *smallestInRight(TreeNode *root)
    {
        if (root->left == NULL)
            return root;
        else
            return smallestInRight(root->left);
    }
    TreeNode *insertNode(int data, TreeNode *root)
    {
        if (root == NULL)
        {
            TreeNode *temp = new TreeNode(data);
            // cout << temp->data << endl;
            return temp;
        }
        if (root->data > data)
        {
            root->left = insertNode(data, root->left);
        }
        else
        {
            root->right = insertNode(data, root->right);
        }
        return root;
    }
    TreeNode *deleteNode(int data, TreeNode *root)
    {
        if (root->data == data)
        {
            if (!root->left || !root->right)
            {
                if (root->left)
                    return root->left;
                else if (root->right)
                    return root->right;
                else
                {
                    delete root;
                    return NULL;
                }
            }
            else
            {
                TreeNode *t = smallestInRight(root->right);
                root->data = t->data;
                root->right = deleteNode(t->data, root->right);
                return root;
            }
            return NULL;
        }
        if (root->data > data)
            root->left = deleteNode(data, root->left);
        else
            root->right = deleteNode(data, root->right);
        return root;
    }
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        preorder(root->left);
        cout << root->data << " ";
        preorder(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    bool search(int data)
    {
        return searchNode(data, root);
    }
    void insert(int data)
    {
        root = insertNode(data, root);
    }
    void deleteN(int data)
    {
        root = deleteNode(data, root);
    }
    void traverse()
    {
        preorder(root);
        cout << endl;
        return;
    }
};

int main()
{
    BST b;
    b.insert(4);
    // b.traverse();
    b.insert(6);
    b.insert(5);
    b.insert(7);
    b.insert(2);
    b.insert(3);
    b.insert(1);
    b.traverse();
    b.deleteN(6);
    b.traverse();
    b.deleteN(4);
    b.traverse();
    b.deleteN(3);
    b.traverse();

    return 0;
}
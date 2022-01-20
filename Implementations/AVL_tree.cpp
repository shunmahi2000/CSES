#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    int height;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        height = 1;
        data = d;
        left = NULL;
        right = NULL;
    }
};

class AVL
{
    TreeNode *root;
    TreeNode *leftRotation(TreeNode *r)
    {
        TreeNode *x = r->right;
        TreeNode *y = x->left;
        x->left = r;
        r->right = y;
        r->height = 1 + max(height(r->left), height(r->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    TreeNode *rightRotation(TreeNode *r)
    {
        TreeNode *x = r->left;
        TreeNode *y = x->right;
        x->right = r;
        r->left = y;
        r->height = 1 + max(height(r->left), height(r->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }
    int height(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        else
            return r->height;
    }
    int getBalanceFactor(TreeNode *r)
    {
        if (r == NULL)
            return 0;
        else
            return height(r->left) - height(r->right);
    }
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
    TreeNode *insertNode(int data, TreeNode *r)
    {
        if (r == NULL)
        {
            TreeNode *temp = new TreeNode(data);
            // cout << temp->data << endl;
            return temp;
        }
        if (r->data > data)
        {
            r->left = insertNode(data, r->left);
        }
        else
        {
            r->right = insertNode(data, r->right);
        }

        r->height = 1 + max(height(r->left), height(r->right));
        int bf = getBalanceFactor(r);

        // left left
        if (bf > 1 && data < r->left->data)
        {
            return rightRotation(r);
        }
        if (bf < -1 && data > r->right->data)
        {
            return leftRotation(r);
        }

        if (bf > 1 && data > r->left->data)
        {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }
        if (bf < -1 && data < r->right->data)
        {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }
        return r;
    }
    TreeNode *deleteNode(int data, TreeNode *r)
    {
        // cout << r->data << " " << r->height << endl;
        if (r->data == data)
        {
            if (!r->left || !r->right)
            {
                if (r->left)
                {
                    return r->left;
                }
                else if (r->right)
                {
                    return r->right;
                }
                else
                {
                    delete r;
                    return NULL;
                }
            }
            else
            {
                TreeNode *t = smallestInRight(r->right);
                r->data = t->data;
                r->right = deleteNode(t->data, r->right);
                // cout << "YES" << endl;
                // return r;
            }
          
        }
        if (r->data > data)
            r->left = deleteNode(data, r->left);
        else
            r->right = deleteNode(data, r->right);

        r->height = 1 + max(height(r->left), height(r->right));
        // cout << r->data << " " << r->height << endl;
        int bf = getBalanceFactor(r);
        // cout << bf << endl;
        //  left left
        if (bf > 1 && getBalanceFactor(r->left) >= 0)
        {
            return rightRotation(r);
        }
        if (bf < -1 && getBalanceFactor(r->right) <= 0)
        {
            return leftRotation(r);
        }

        if (bf > 1 && getBalanceFactor(r->left) < 0)
        {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }
        if (bf < -1 && getBalanceFactor(r->right) > 0)
        {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }
        return r;
    }
    void preorder(TreeNode *root)
    {
        if (root == NULL)
            return;
        preorder(root->left);
        cout << "{" << root->data << "," << root->height << "} ";
        preorder(root->right);
    }

public:
    AVL()
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
    AVL b;
    b.insert(4);
    // b.traverse();
    b.insert(6);
    b.traverse();
    b.insert(5);
    b.traverse();
    b.insert(7);
    b.traverse();
    b.insert(2);
    b.traverse();
    b.insert(3);
    b.traverse();
    b.insert(1);
    b.traverse();
    b.deleteN(6);
    b.traverse();
    // b.traverse();

    return 0;
}

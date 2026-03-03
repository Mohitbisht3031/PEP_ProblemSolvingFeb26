#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
    public:
    int val;
    BST *left;
    BST *right;

    BST(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* LCA(TreeNode *root,int p,int q){
    if(!root)return root;
    if(root->val == p || root->val == q)return root;

    TreeNode *lans = LCA(root->left,p,q);
    TreeNode *rans = LCA(root->right,p,q);

    if(lans != NULL && rans == NULL)return lans;
    else if(rans != NULL && lans == NULL)return rans;
    else if(lans != NULL && rans != NULL)return root;

    return NULL;
}

BST* LCA(BST *root,int p,int q){
    if(!root)return root;

    if((root->val >= p && root->val < q) || (root->val < p && root->val >= q))return root;

    if(root->val > p && root->val > q)return LCA(root->left,p,q);
    else if(root->val < p && root->val < q) return LCA(root->right,p,q);

    return NULL;
}
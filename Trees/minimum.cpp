#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *createNode(int val){
    TreeNode *newNode = new TreeNode;
    newNode->val=val;
    newNode->left=nullptr;
    newNode->right=nullptr;
    return newNode;
}
TreeNode *InsertNode(TreeNode*root, int val){
    if(root==nullptr){
        return createNode(val);
    }
    if(root->val < val){
        root->right=InsertNode(root->right,val);
    }else{
        root->left=InsertNode(root->left,val);
    }
    return root;
}
// Boiler Code

int minimum(TreeNode *root){
    if(root==NULL) return -1;
    while(root->left){
        root = root->left;
    }
    return root->val;
}

int main(){
    TreeNode *root = NULL;
    int values[] = {5,3,7,2,4,6,8};
    for(auto val : values){
        root = InsertNode(root,val);
    }
    int ans = minimum(root);
    cout << ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};
TreeNode*createNode(int val){
    TreeNode *newnode = new TreeNode;
    newnode->val=val;
    newnode->right=NULL;
    newnode->right=NULL;
    return newnode;
}
TreeNode*insertNode(TreeNode*root, int data){
    if(root==nullptr) return createNode(data);
    if(root->val<data) root->right=insertNode(root->right,data);
    if(root->val>data) root->left=insertNode(root->left,data);
    return root;
}
bool univalTree(TreeNode*root){
    if(root==NULL) return true;
    if(root->left && root->left->val != root->val) return false;
    if(root->right && root->right->val != root->val) return false;
    return univalTree(root->left) && univalTree(root->right);
}
int main(){
    TreeNode *root = NULL;
    int values[] = {1,1,1,1,1,1,1};
    for(auto val : values){
        root = insertNode(root,val);
    }
    if(univalTree(root)) cout << "The tree is unival tree";
    else cout << "The tree is not a unival tree";
    return 0;
}
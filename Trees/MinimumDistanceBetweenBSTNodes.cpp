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

void inorder(TreeNode*root, vector<int>&result){
    if(root==NULL) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right,result);
}

vector<int>inorderTraversal(TreeNode*root){
    vector<int>result;
    inorder(root,result);
    return result;
}
int minDiffInBST(TreeNode* root) {
    vector<int>result = inorderTraversal(root);
    int mini=1e9;
    for(int i=1; i<result.size(); i++){
        mini = min(mini, result[i]-result[i-1]);
    }
    return mini;
}
int main(){
    TreeNode *root = NULL;
    int values[] = {5,3,7,2,4,6,8};
    for(auto val : values){
        root = InsertNode(root,val);
    }
    cout << minDiffInBST(root);
    return 0;
}
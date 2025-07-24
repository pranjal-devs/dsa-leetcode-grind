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

int maximumDepth(TreeNode*root){
    if(root==NULL) return 0;
    int leftHeight = maximumDepth(root->left);
    int rightHeight = maximumDepth(root->right);
    return 1+max(leftHeight,rightHeight);
}

int main(){
    TreeNode *root = NULL;
    int values[] = {7,5,12,8,11};
    for(auto val : values){
        root = InsertNode(root,val);
    }
    int ans = maximumDepth(root);
    cout << ans;
    return 0;
}
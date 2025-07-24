#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
};

TreeNode*createNode(int val){
    TreeNode*newnode = new TreeNode;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->val = val;
    return newnode;
}

TreeNode*insertNode(TreeNode *root, int val){
    if(root==NULL) return createNode(val);
    if(val>root->val) root->right = insertNode(root->right, val);
    else root->left = insertNode(root->left, val);
    return root;
}

bool getPath(TreeNode*root, vector<int>&arr, int x){
    if(root==NULL) return false;
    arr.push_back(root->val);
    if(root->val==x) return true;
    if(getPath(root->left,arr,x)||getPath(root->right,arr,x)) return true;
    arr.pop_back();
    return false;
}

vector<int>RootToNodeSum(TreeNode*root, int x){
    vector<int>arr;
    if(root==NULL) return arr;
    getPath(root,arr,x);
    return arr;
}

int main(){
    vector<int>values = {4,2,6,1,3,5,7};
    TreeNode *root = NULL;
    for(auto val : values){
        root = insertNode(root,val);
    }
    vector<int>ans=RootToNodeSum(root,5);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}


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

void postorder(TreeNode *root, vector<int>&result){
    if(root==NULL){
        return;
    }
    postorder(root->left,result);
    postorder(root->right,result);
    result.push_back(root->val);
}

vector<int>postorderTraversal(TreeNode *root){
    vector<int>result;
    postorder(root,result);
    return result;
}

int main(){
    TreeNode *root = NULL;
    int values[] = {5,3,7,2,4,6,8};
    for(auto val : values){
        root = InsertNode(root,val);
    }
    vector<int>result=postorderTraversal(root);
    for(auto it : result){
        cout << it << " ";
    }
    return 0;
}
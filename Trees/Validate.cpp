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

void inorder(TreeNode *root, vector<int>&result){
        if(root==NULL){
            return;
        }
        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }

    vector<int>inorderTraversal(TreeNode *root){
        vector<int>result;
        inorder(root,result);
        return result;
    }

    bool isValidBST(TreeNode* root) {
        vector<int>ans = inorderTraversal(root);
        bool flag = true;
        for(int i=0; i<ans.size(); i++){
            if((i+1)<ans.size() && ans[i]>=ans[i+1]){
                flag = false;
            }
        }
        return flag;
    }


int main(){
    TreeNode *root = NULL;
    int values[] = {5,3,7,2,4,6,8};
    if(isValidBST(root)) cout << "Yes it's valid";
    else cout << "No it's invalid";
    return 0;
}
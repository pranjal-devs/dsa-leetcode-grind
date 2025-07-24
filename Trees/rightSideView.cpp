#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode *createNode(int val){
    TreeNode *newnode = new TreeNode;
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
TreeNode *insertNode(TreeNode*root, int val){
    if(root==NULL) return createNode(val);
    if(root->val>val) root->left = insertNode(root->left,val);
    else root->right = insertNode(root->right,val);
    return root;
}
vector<vector<int>>levelOrder(TreeNode *root){
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        vector<int>level;
        int size = q.size();
        for(int i=0; i<size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
    }
    return ans;
}
vector<int>rightSideView(TreeNode *root){
    vector<vector<int>>level = levelOrder(root);
    vector<int>ans;
    for(auto it : level){
        if(!it.empty()){
            ans.push_back(it.back());
        }
    }
    return ans;
}

int main(){
    int values[] = {5,3,7,2,4,6,8};
    TreeNode *root = NULL;
    for(auto it : values){
        root = insertNode(root,it);
    }
    vector<int>right=rightSideView(root);
    for(auto it : right){
        cout << it << " ";
    }
    return 0;
}
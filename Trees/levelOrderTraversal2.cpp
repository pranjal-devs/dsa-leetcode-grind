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
vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>>level = levelOrder(root);
    reverse(level.begin(),level.end());
    return level;
}
int main(){
    TreeNode *root = NULL;
    int values[] = {3,9,20,15,7};
    for(auto val : values){
        root = InsertNode(root,val);
    }
    vector<vector<int>>ans = levelOrderBottom(root);
    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
    }
}
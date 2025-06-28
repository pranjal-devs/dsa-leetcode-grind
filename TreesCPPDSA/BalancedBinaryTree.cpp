#include <iostream>
#include <cstdlib>
using namespace std;
/*
int flag=1;
int checkifBSTisbalanced(tree*root){
    if(root==NULL) return 0;
    int leftheight=checkifBSTisbalanced(root->left);
    int rightheight=checkifBSTisbalanced(root->right);
    if(abs(leftheight-rightheight)>1){
        flag=0;
    }
    return 1+(leftheight>rightheight?leftheight:rightheight);
}
int isbalanced(tree*root){
    flag=1;
    checkifBSTisbalanced(root);
    return flag==1;
}
*/
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createNode(int val) {
    return new TreeNode(val);
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int flag=1;
        checkTree(root,flag);
        return flag==1;
    }
    int checkTree(TreeNode*root,int &flag){
        if(root==nullptr){
            return 0;
        }
        int leftheight=checkTree(root->left,flag);
        int rightheight=checkTree(root->right,flag);
        if(abs(leftheight-rightheight)>1){
            flag=0;
        }
        return 1+max(leftheight,rightheight);
    }
};

int main() {
    // Creating the tree nodes
    TreeNode* p = createNode(8);
    TreeNode* p1 = createNode(3);
    TreeNode* p2 = createNode(10);
    TreeNode* p3 = createNode(1);
    TreeNode* p4 = createNode(6);
    TreeNode* p5 = createNode(9);
    TreeNode* p6 = createNode(14);
    TreeNode* p7 = createNode(13);
    TreeNode* p8 = createNode(15);

    // Constructing the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p6->left = p7;
    p7->right=p8;

//       8
//     /   \
//    3     10
//   / \   /  \
//  1   6 9    14
//            /
//           13
    
    Solution solution;
    if(solution.isBalanced(p)){
        cout <<"The BST is balanced" << endl;
    }
    else{
        cout <<"The BST is not balanced" << endl;
    }
    return 0;
}

#include <iostream>
#include <cstdlib>
#include<climits>
using namespace std;
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
    bool isValidBSTHelper(TreeNode*root,long min, long max){
        if(root==nullptr){
            return true;
        }
        if(root->val<=min||root->val>=max){
            return false;
        }
        return isValidBSTHelper(root->left,min,root->val) && isValidBSTHelper(root->right,root->val,max);
    }
    bool isValidBST(TreeNode*root){
        return isValidBSTHelper(root,LONG_MIN,LONG_MAX);
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

    // Constructing the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p6->left = p7;

//       8
//     /   \
//    3     10
//   / \   /  \
//  1   6 9    14
//            /
//           13
    
    Solution solution;
    if(solution.isValidBST(p)){
        cout<< "true";
    }
    else{
        cout<< "false";
    }
    return 0;
}

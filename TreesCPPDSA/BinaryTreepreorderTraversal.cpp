#include <iostream>
#include <cstdlib>
#include<vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root,result);
        return result;
    }
    void preorder(TreeNode*root,vector<int>&result){
        if(root==nullptr){
            return;
        }
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
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
    vector<int> result = solution.preorderTraversal(p);

    // Print the result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}

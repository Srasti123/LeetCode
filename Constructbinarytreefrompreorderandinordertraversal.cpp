#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, int> inorder_map;  // To store the index of each value in inorder array
    int preorder_index = 0;  // To keep track of the current root node in preorder array
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map each value to its index in the inorder array for fast lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, inorder.size() - 1);
    }
    
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right) {
        // If there are no elements to construct the tree
        if (left > right) return nullptr;

        // Select the preorder_index element as the root and increment it
        int root_value = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_value);

        // Recursively build left and right subtrees
        root->left = arrayToTree(preorder, left, inorder_map[root_value] - 1);
        root->right = arrayToTree(preorder, inorder_map[root_value] + 1, right);

        return root;
    }
};

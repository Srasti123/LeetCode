#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int postorderIndex;  // To track the current root in the postorder array
    unordered_map<int, int> inorderMap;  // Store index of each value in the inorder array
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorderIndex = postorder.size() - 1;  // Start from the last element in postorder
        
        // Map each value in inorder array to its index
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        // Build the tree starting from the full range of inorder array
        return buildSubtree(inorder, postorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildSubtree(vector<int>& inorder, vector<int>& postorder, int left, int right) {
        // If there are no elements to process, return null
        if (left > right) return nullptr;

        // Get the root value from postorder array and decrement the index
        int rootValue = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);

        // Find the index of this root in inorder array
        int inorderIndex = inorderMap[rootValue];

        // Recursively build right and left subtrees
        // Note: Build right subtree first, then left subtree, because we are moving backwards in postorder
        root->right = buildSubtree(inorder, postorder, inorderIndex + 1, right);
        root->left = buildSubtree(inorder, postorder, left, inorderIndex - 1);

        return root;
    }
};

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // If root is NULL, return NULL
    if (!root) {
        return NULL;
    }

    // If either p or q is found, return the root
    if (root == p || root == q) {
        return root;
    }

    // Check if p and q are on different sides of the root
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both left and right are not NULL, the root is the LCA
    if (left && right) {
        return root;
    }

    // Otherwise, return the non-NULL node
    return left ? left : right;
}
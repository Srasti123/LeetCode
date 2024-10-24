#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;  // Base case: if the root is null, no path exists

    // If it's a leaf node, check if the path sum equals targetSum
    if (!root->left && !root->right) return root->val == targetSum;

    // Recur on left and right subtrees with the remaining targetSum
    targetSum -= root->val;
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// Example tree construction for testing
int main() {
    // Example 1: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->right->right->right = new TreeNode(1);

    cout << "Has path sum: " << (hasPathSum(root1, 22) ? "true" : "false") << endl;  // Output: true

    // Example 2: root = [1,2,3], targetSum = 5
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    cout << "Has path sum: " << (hasPathSum(root2, 5) ? "true" : "false") << endl;  // Output: false

    return 0;
}

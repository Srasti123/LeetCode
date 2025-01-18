#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
    if (inorder.empty() || preorder.empty()) {
        return nullptr;
    }

    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);

    int inorderIndex = findIndex(inorder, rootVal);

    // Build left subtree
    root->left = buildTree(std::vector<int>(inorder.begin(), inorder.begin() + inorderIndex),
                          std::vector<int>(preorder.begin() + 1, preorder.begin() + inorderIndex + 1));

    // Build right subtree
    root->right = buildTree(std::vector<int>(inorder.begin() + inorderIndex + 1, inorder.end()),
                           std::vector<int>(preorder.begin() + inorderIndex + 1, preorder.end()));

    return root;
}

int findIndex(vector<int>& inorder, int val) {
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return -1;
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    TreeNode* root = buildTree(inorder, preorder);

    cout << "Inorder traversal of the constructed tree: ";
    inorderTraversal(root);

    return 0;
}
#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int diameter = 0; 
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0; 
        }
        
        
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        
        diameter = std::max(diameter, leftDepth + rightDepth);
        
        return std::max(leftDepth, rightDepth) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root); 
        return diameter; 
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    std::cout << "Diameter: " << sol.diameterOfBinaryTree(root) << std::endl; 

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    std::cout << "Diameter: " << sol.diameterOfBinaryTree(root2) << std::endl; 

    

    return 0;
}


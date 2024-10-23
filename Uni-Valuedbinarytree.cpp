#include <iostream>
using namespace std;

struct TreeNode {
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};


bool isUnivalTree(TreeNode* root) {

    if (!root) return true;
    if (root->left && root->left->val != root->val) return false;
    if (root->right && root->right->val != root->val) return false;
    
    
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);
    
    if (isUnivalTree(root)) {
        cout << "The tree is uni-valued." << endl;
    } else {
        cout << "The tree is not uni-valued." << endl;
    }
    
    return 0;
}

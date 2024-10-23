#include <iostream>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    // If both nodes are NULL, they are the same
    if (!p && !q) return true;
    // If one of the nodes is NULL and the other is not, they are not the same
    if (!p || !q) return false;
    // Check if the current nodes are the same and recursively check the left and right subtrees
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    std::cout << (isSameTree(p1, q1) ? "True" : "False") << std::endl;

    
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

   
    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    
    std::cout << (isSameTree(p2, q2) ? "True" : "False") << std::endl;

    return 0;
}

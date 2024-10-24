#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxLevelSum(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level = 1, maxSum = root->val, resultLevel = 1;

    while (!q.empty()) {
        int levelSize = q.size();
        int levelSum = 0;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            levelSum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (levelSum > maxSum) {
            maxSum = levelSum;
            resultLevel = level;
        }
        level++;
    }

    return resultLevel;
}

int main() {
    // Example 1: root = [1,7,0,7,-8,null,null]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(7);
    root1->right = new TreeNode(0);
    root1->left->left = new TreeNode(7);
    root1->left->right = new TreeNode(-8);

    cout << "Max level sum is at level: " << maxLevelSum(root1) << endl;  

    // Example 2: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    TreeNode* root2 = new TreeNode(989);
    root2->right = new TreeNode(10250);
    root2->right->left = new TreeNode(98693);
    root2->right->right = new TreeNode(-89388);
    root2->right->right->right = new TreeNode(-32127);

    cout << "Max level sum is at level: " << maxLevelSum(root2) << endl;  

    return 0;
}


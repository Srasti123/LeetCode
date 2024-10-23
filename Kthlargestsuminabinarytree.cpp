


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;
        
        queue<TreeNode*> q;
        vector<int> levelSums;
        q.push(root);
        
        // Perform BFS to calculate level sums
        while (!q.empty()) {
            int levelSum = 0;
            int levelSize = q.size();  // Get the number of nodes at the current level
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                
                // Add left and right children to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            levelSums.push_back(levelSum);
        }
        
        // Sort level sums in descending order
        sort(levelSums.rbegin(), levelSums.rend());
        
        // Check if there are at least k levels
        if (k > levelSums.size()) return -1;
        
        // Return the k-th largest level sum
        return levelSums[k - 1];
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(8);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(6);

    Solution sol;
    int k = 2;
    cout << sol.kthLargestLevelSum(root, k) << endl;  // Output: 13

    return 0;
}

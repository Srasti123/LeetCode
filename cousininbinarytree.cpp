#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;  // Handle empty tree case.

        queue<TreeNode*> q;  // Queue for level-order traversal.
        unordered_map<TreeNode*, TreeNode*> parentMap;  // To track parent of each node.

        q.push(root);
        parentMap[root] = nullptr;  // Root has no parent.

        // BFS traversal to compute and replace values level by level.
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level.
            long long levelSum = 0;    // Sum of all node values at the current level.

            // Store nodes and their parent info for this level.
            vector<pair<TreeNode*, TreeNode*>> nodes;  

            // First, calculate the sum of all nodes at the current level.
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelSum += node->val;
                nodes.push_back({node, parentMap[node]});  // Store node and its parent.

                // Add children to the queue and record their parent.
                if (node->left) {
                    q.push(node->left);
                    parentMap[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    parentMap[node->right] = node;
                }
            }

            // Second, calculate the cousin sum for each node.
            for (auto& [node, parent] : nodes) {
                long long siblingSum = 0;

                // Calculate the sum of the node's siblings.
                if (parent) {
                    if (parent->left && parent->left != node) {
                        siblingSum += parent->left->val;
                    }
                    if (parent->right && parent->right != node) {
                        siblingSum += parent->right->val;
                    }
                }

                // Cousin sum = level sum - node's value - sibling sum.
                node->val = levelSum - node->val - siblingSum;
            }
        }

        return root;  // Return the modified tree.
    }
};

// Function to print the tree in level-order (for testing purposes)
void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}

int main() {
    // Example 1
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(9);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(10);
    root1->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* modifiedRoot1 = sol.replaceValueInTree(root1);
    printTree(modifiedRoot1);  // Expected Output: [0, 0, 0, 7, 7, null, 11]

    // Example 2
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    TreeNode* modifiedRoot2 = sol.replaceValueInTree(root2);
    printTree(modifiedRoot2);  // Expected Output: [0, 0, 0]

    return 0;
}

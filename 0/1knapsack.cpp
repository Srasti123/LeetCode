#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int maxWeight, vector<int>& weights, vector<int>& values, int n) {
    // DP table where dp[i][w] stores the maximum value for first i items with weight w
    vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (weights[i - 1] <= w) {
                // If the item can be included, take the maximum of:
                // 1. excluding the item (dp[i-1][w])
                // 2. including the item (values[i-1] + dp[i-1][w - weights[i-1]])
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the item can't be included, just exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The last cell of the DP table will hold the answer
    return dp[n][maxWeight];
}

int main() {
    int maxWeight = 7;
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int n = weights.size();

    int result = knapsack(maxWeight, weights, values, n);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}

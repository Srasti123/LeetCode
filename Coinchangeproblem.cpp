#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // DP array initialization
    vector<int> dp(amount + 1, INT_MAX);  // Create DP array with size 'amount + 1'
    dp[0] = 0;  // Base case: 0 coins needed to form amount 0

    // Loop through all amounts from 1 to 'amount'
    for (int i = 1; i <= amount; i++) {
        // Check each coin denomination
        for (int coin : coins) {
            if (i >= coin) {  // If coin can be used to form amount i
                dp[i] = min(dp[i], dp[i - coin] + 1);  // Update dp[i] with the minimum coins needed
            }
        }
    }

    // If dp[amount] is still INT_MAX, return -1 (amount can't be formed)
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};  
    int amount = 11;  
    int result = coinChange(coins, amount);
    cout << "Minimum coins needed: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string X, string Y) {
        int m = X.length();
        int n = Y.length();

        // Create a 2D DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match, add 1 to the previous diagonal value
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Otherwise, take the max of left or top value
                }
            }
        }

        // The bottom-right cell will contain the length of LCS
        return dp[m][n];
    }
};

int main() {
    string X = "ABCBDAB";
    string Y = "BDCABB";

    Solution obj;
    int lcsLength = obj.longestCommonSubsequence(X, Y);

    cout << "The length of the Longest Common Subsequence is: " << lcsLength << endl;

    return 0;
}

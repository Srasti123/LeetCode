#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lcs(string s1, int i, string s2, int j, vector<vector<int>>& dp){
  if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + lcs(s1, i-1, s2, j-1, dp);
    else
        dp[i][j] = max(lcs(s1, i-1, s2, j, dp), lcs(s1, i, s2, j-1, dp));
    return dp[i][j];
}
int main() {
    string s1 = "abcde";
    string s2 = "ace";
    int i = s1.size();
    int j = s2.size();
    vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
    int n = lcs(s1, i, s2, j, dp);
    cout << "Length of LCS: " <<n<< endl;

    return 0;
}



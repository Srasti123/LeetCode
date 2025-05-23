#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charCount;
        int left = 0, maxCount = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++;  // Expand window
            maxCount = max(maxCount, charCount[s[right]]); // Track most frequent character count

            // If more than k characters need to be replaced, shrink the window
            if ((right - left + 1) - maxCount > k) {
                charCount[s[left]]--; // Reduce count of leftmost character
                left++; // Move left pointer
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << "Longest substring length: " << sol.characterReplacement(s, k) << endl;
    return 0;
}

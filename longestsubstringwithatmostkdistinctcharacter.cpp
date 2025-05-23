#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> charCount; // Stores character frequency in the window
        int left = 0, maxLength = 0;
        for (int right = 0; right < s.length(); right++) {
            charCount[s[right]]++; // Add new character to the map

            // Shrink window if we have more than k distinct characters
            while (charCount.size() > k) {
                charCount[s[left]]--; // Reduce frequency of leftmost character
                if (charCount[s[left]] == 0) {
                    charCount.erase(s[left]); // Remove character if frequency is zero
                }
                left++; // Move left pointer
            }

            // Update the maximum window length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string s = "eceba";
    int k = 2;
    cout << "Longest substring length: " << sol.lengthOfLongestSubstringKDistinct(s, k) << endl;
    return 0;
}

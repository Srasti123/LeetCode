#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        vector<string> result;
        
        // Combine both sentences into one string
        string combined = s1 + " " + s2;
        
        // Split the combined string into words
        stringstream ss(combined);
        string word;
        
        // Count the occurrences of each word
        while (ss >> word) {
            wordCount[word]++;
        }
        
        // Find and store words that appear exactly once
        for (auto& entry : wordCount) {
            if (entry.second == 1) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};

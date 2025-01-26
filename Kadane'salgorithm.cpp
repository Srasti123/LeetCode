#include <iostream>
#include <vector>
#include <climits> 

using namespace std;

// Function to find the maximum subarray sum
int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0]; // Maximum sum found so far
    int currentSum = nums[0]; // Current sum of the subarray ending at the current index

    for (int i = 1; i < nums.size(); i++) {
        // Either continue the current subarray or start a new subarray
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update the global maximum sum
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(nums) << endl;
    return 0;
}

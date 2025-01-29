#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int activitySelection(vector<pair<int, int>>& activities) {
    sort(activities.begin(), activities.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second; 
    });
    int count = 1; 
    int lastEndTime = activities[0].second; 

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].first >= lastEndTime) {
            count++; 
            lastEndTime = activities[i].second; 
        }
    }

    return count; 
}

int main() {
    vector<pair<int, int>> activities = {
        {1, 3}, {2, 5}, {4, 6}, {6, 7}, {5, 8}, {8, 9}
    };

    int result = activitySelection(activities);
    cout << "Maximum number of activities: " << result << endl;

    return 0;
}

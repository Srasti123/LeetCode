#include <iostream>
#include <string>

using namespace std;

bool queryString(string s, int n) {
    for (int i = 1; i <= n; ++i) {
        string binary = to_string(i);
        if (s.find(binary) == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "0110";
    int n = 3;

    bool result = queryString(s, n);

    if (result) {
        cout << "All numbers from 1 to " << n << " can be represented as substrings of " << s << endl;
    } else {
        cout << "Not all numbers from 1 to " << n << " can be represented as substrings of " << s << endl;
    }

    return 0;
}



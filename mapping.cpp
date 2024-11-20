#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;
    myMap[0] = "(0,1)";
    myMap[1] = "(0,2)";
    myMap[2] = "(1,0)";

    
    if (myMap.find(3) == myMap.end()) {
        myMap[3] = "(1,1)"; 
        cout << "Key 3 added with value (1,1)" << endl;
    } else {
        cout << "Key 3 already exists" << endl;
    }
    for (auto& pair : myMap) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}

































































































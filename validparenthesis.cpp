class Solution {
public:
    bool isValid(string s) {
        stack<char> k;

        for(int i = 0 ; i < s.length() ; i++) {
            if(s[i] == '(') {
                k.push(')');
            }
            else if(s[i] == '{') {
                k.push('}');
            }
            else if(s[i] == '[') {
                k.push(']');
            }
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(k.empty() || k.top() != s[i]) {
                    return false;
                }
                k.pop();
            }
        }
        if(k.empty()) {
            return true;
        }

        return false;
        
    }
};
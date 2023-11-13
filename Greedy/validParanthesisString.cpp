// first approach fails on below testcase
//  s = "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"

class Solution {
public:
    bool checkValidString(string s) {
        int noOfStar = 0;

        stack<char> st;

        for (int i=0; i<s.length(); i++) {
            if (s[i] == '*') {
                noOfStar++;
            }
            else if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if(st.empty() == false && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(s[i]);
                }
            }
        }
        
        if (st.empty() == true) return true;

        return noOfStar >= st.size();
    }
};


//---------------------------------------------------------------------------------------------------------------------------------------------------------
// 2nd approach based on counting the open bracket, close brackets and number of stars
class Solution {
public:
    bool checkValidString(string s) {
        int o = 0, c = 0, st = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                o++;
            } else if (s[i] == ')') {
                c++;
            } else if (s[i] == '*') {
                st++;
            }
            
            if (c > o + st) {
                return false;
            }
        }
        
        o = 0;
        c = 0;
        st = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                o++;
            } else if (s[i] == ')') {
                c++;
            } else if (s[i] == '*') {
                st++;
            }
            
            if (o > c + st) {
                return false;
            }
        }
        
        return true;
    }
};

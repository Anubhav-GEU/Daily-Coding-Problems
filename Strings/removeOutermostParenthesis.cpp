class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<string> store;

        string ans = "";
        stack<char> st;
        st.push(s[0]);

        int n = s.length();
        int start = 0;
        int i;
        bool popped = false;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                popped = false;
            } 
            else{
                st.pop();
                popped = true;
            }
            if (st.empty() == true && popped) {
                string str = s.substr(start + 1, i-start-1);
                ans += str;
                start = i+1;
            }
        }
        return ans;
    }
};

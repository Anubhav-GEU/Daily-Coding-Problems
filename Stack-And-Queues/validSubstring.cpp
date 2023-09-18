class Solution {
  public:
    int findMaxLen(string s) {
// ----------------------------------------stack based App TC-O(N) SC-O(N)------------------------------------------------------
        int count = 0;
        
        int res = 0;
        
        stack<char> st;
        map<char,char> mp;
        mp[')'] = '(';
        for (int i=0; i<s.length(); ){
            int count = 0;
            while (s[i] == '(' && i<s.length()){
                st.push(s[i]);
                i++;
            }
            while(!st.empty() && mp[s[i]] == st.top() && i<s.length()){
                st.pop();
                i++;
                count+=2;
            }
            if (st.empty() == true){
                res += count;
            }
            else{
                res = max(res,count);
            }
        }
        return res;
    }
};
//--------------------------------------Approach - 2 ------ Iterative Method-------------TC-O(N) SC-O(1)-------------------------------
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
      
        int open = 0;
        int close = 0;
        int maxlen = 0;
        int n = s.length();
        for (int i=0; i<n; i++){
            if (s[i] == '('){
                open++;
            }
            else{
                close++;
            }
            if (open == close) {
                maxlen = max(maxlen,2*open);
            }
            else if (close > open){
                close = 0;
                open = 0;
            }
        }
        open = 0;
        close = 0;
        for (int i=n-1; i>=0; i--){
            if (s[i] == '('){
                open++;
            }
            else{
                close++;
            }
            if (open == close) {
                maxlen = max(maxlen,2*open);
            }
            else if (open > close){
                close = 0;
                open = 0;
            }
        }
        return maxlen;
    }
};

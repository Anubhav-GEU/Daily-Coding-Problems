class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int n=num.length();
        bool added = false;
        for (int i=n-1;i>=0; i--){
            int ch = stoi(to_string(num[i]));
            if (ch%2 != 0 && added == false){
                ans += num[i];
                added = true;
            }
            else if (added == true){
                ans += num[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

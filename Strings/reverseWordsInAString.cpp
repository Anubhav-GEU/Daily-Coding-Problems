class Solution {
public:
    string trim(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') s.erase(i,i);
            else break;
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' ') s.erase(i,i);
            else break;
        }
        return s;
    }
    string reverseWords(string s) {
        vector<string> v;
        string ans="";
        s=trim(s);
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(ans.size()==0) continue;
                v.push_back(ans);
                ans="";
                continue;
            }
            ans+=s[i];
        }
        v.push_back(ans);
        reverse(v.begin(),v.end());
        ans="";
        for(int i=0;i<v.size();i++){
            ans+=v[i];
            ans+=" ";
        }
        ans=trim(ans);
        return ans;
    }
};

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
    
        int n = string_list.size();
    

        for (int i = 0; i < n; i++) {
            string temp = string_list[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(string_list[i]);
        }
    
        for (const auto& pair : mp) {
            ans.push_back(pair.second);
        }
    
        return ans;
    }
};

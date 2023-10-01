class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        
        // first find number of distinct character in the string;
        set<char> st;
        unordered_map<char,int> mp;
        
        int n = str.length();
        for (int i=0; i<n; i++){
            st.insert(str[i]);
        }
        int distinct = st.size();
        int left = 0;
        int ans = n;
        for (int right=0; right<n; right++){
            mp[str[right]]++;
            if (mp.size() == distinct){
                while (mp[str[left]]>1) {
                    mp[str[left]]--;
                    left++;
                }
                
                ans = min(ans,right-left+1);
            }
            right++;
        }
        return ans;
    }
};



//----------------------------------------------------------------Approach 2-----------------------------------------------------------------------

class Solution{
    public:
    const int MAX_CHARS = 256;
  
    int findSubString(string str)
    {
        // Your code goes here   
        
        // first find number of distinct character in the string;
        int n = str.length();
        if (n <= 1)
            return str.length();
        int dist_count = 0;
        bool visited[MAX_CHARS] = { false };
        for (int i = 0; i < n; i++) {
            if (visited[str[i]] == false) {
                visited[str[i]] = true;
                dist_count++;
            }
        }
      
        int start = 0, start_index = -1, min_len = INT_MAX;
      
        int count = 0;
        int curr_count[MAX_CHARS] = { 0 };
        for (int j = 0; j < n; j++) {
            curr_count[str[j]]++;
      
            if (curr_count[str[j]] == 1)
                count++;
      
            if (count == dist_count) {
                while (curr_count[str[start]] > 1) {
                    if (curr_count[str[start]] > 1)
                        curr_count[str[start]]--;
                    start++;
                }
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        string ans = str.substr(start_index, min_len);
        return ans.length();
    }
};

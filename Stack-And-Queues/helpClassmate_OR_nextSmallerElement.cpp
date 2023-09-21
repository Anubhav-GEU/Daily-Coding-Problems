class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> st;
        vector<int> ans(n,0);
        ans[n-1] = -1;
        st.push(arr[n-1]);
        
        for (int i = n-2; i>=0; i--){
            while (st.empty() == false && st.top() >= arr[i]){
                st.pop();
            }
            
            ans[i] = (st.empty() == true) ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    } 
};

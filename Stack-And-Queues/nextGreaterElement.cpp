class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans(n,0);
        ans[n-1] = -1;
        
        stack<long long> st;
        st.push(arr[n-1]);
        
        for (int i=n-2; i>=0; i--){
            while (st.empty() == false && st.top() <= arr[i]){
                st.pop();
            }
            ans[i] = (st.empty() == true) ? -1 : st.top();
            st.push(arr[i]);
        }
        
        return ans;
    }
};

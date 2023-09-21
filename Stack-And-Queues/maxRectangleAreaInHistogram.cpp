class Solution{
  public:
    int getMaxArea(int arr[], int n) {
        int res = 0;
        stack<int> st;
    
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int top = st.top();
                st.pop();
    
                int curr = arr[top] * (st.empty() ? i : (i - st.top() - 1));
                res = max(res, curr);
            }
            st.push(i);
        }
    
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int curr = arr[top] * (st.empty() ? n : (n - st.top() - 1));
            res = max(res, curr);
        }
    
        return res;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int res = getMaxArea(M[0],m);
        
        for (int i=1; i<n; i++){
            for (int j=0; j<m; j++){
                if (M[i][j] == 1){
                    M[i][j] += M[i-1][j];
                }
            }
            
            res = max(res,getMaxArea(M[i],m));
        }
        
        return res;
    }
};


class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    bool isKnown(vector<vector<int>>& matrix, int i, int j){
        return matrix[i][j];
    }
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        for (int i=0; i<n; i++){
            st.push(i);
        }
        
        while (st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if (isKnown(M,a,b)){
                st.push(b);
            }
            else{
                st.push(a);
            }
        }
        
        int candidate = st.top();
        st.pop();
        
        for (int i = 0; i < n; i++) {
            if ((i != candidate) && (isKnown(M,candidate, i) || !isKnown(M,i, candidate)))
                return -1;
        }
        return candidate;
    }
};

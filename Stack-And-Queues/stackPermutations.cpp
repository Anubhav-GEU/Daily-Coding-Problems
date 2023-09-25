class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        
        int i=0;
        int j=0;
        for (;i<N;i++){
            s.push(A[i]);
            
            while (s.empty() == false && s.top() == B[j]){
                j++;
                s.pop();
            }
        }
        return (s.empty() && (j==N)) ? 1:0;
    }
};

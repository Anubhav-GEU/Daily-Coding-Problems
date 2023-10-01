class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	if (A==B) return 0;
    	int n = A.length();
    	int m = B.length();
    	
    	if (n != m) return -1;
    	
    	int ans = 0;
    	
    	unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]--;
        }
        
        for(auto i:mp)if(i.second)return -1;
    	
    	 for(int i=n-1 , j=n-1;i>=0;i--,j--)
            while(i>=0 && A[i]!=B[j])i--,ans++;
        return ans;
    }
};

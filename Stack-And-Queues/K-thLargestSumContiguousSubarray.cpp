class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int> pq;
        
        for (int i=0; i<N; i++){
            int sum = 0;
            for (int j=i; j<N; j++){
                sum += Arr[j];
                pq.push(sum);
            }
        }
        int ans = 0;
        for (int i=1; i<=K; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

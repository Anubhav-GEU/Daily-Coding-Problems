class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        int n = q.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = q.front();
            q.pop();
        }
    
        int i = 0;
        int j = n / 2;
        int k = 0;
        

        while (k < n) {
            if (k % 2 == 0)
                q.push(temp[i++]);
            else
                q.push(temp[j++]);
            k++;
        }
    
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
    
        return ans;
    }
};

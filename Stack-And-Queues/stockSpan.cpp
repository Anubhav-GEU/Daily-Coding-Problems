class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int> span(n,0);
       
       span[0] = 1;
       stack<int> st;
       st.push(0);
       int spCount = 0;
       for (int i=1; i<n; i++){
           while (st.empty() == false && price[st.top()] <= price[i]){
               st.pop();
           }
           
           spCount = (st.empty() == true) ? i+1 : i-st.top();
           span[i] = spCount;
           st.push(i);
       }
       
       return span;
    }
};

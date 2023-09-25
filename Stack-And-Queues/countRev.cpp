int countRev (string s)
{
    // your code here
    int n = s.length();
    if (n%2 != 0) return -1;
    
    int lb = 0;
    int rb = 0;
    
    for (int i=0; i<n; i++){
        if (s[i] == '{'){
            lb++;
        }
        else{
            if (lb == 0){
                rb++;
            }
            else{
                lb--;
            }
        }
    }
    
    return ceil(lb / 2.0) + ceil(rb / 2.0);
}

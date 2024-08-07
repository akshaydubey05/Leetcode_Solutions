class Solution {
public:
    int n,w;
    vector<vector<int>> a;
    vector<int> dp;
    int ans=INT_MAX;
    int f(int i)
    {
        if (i>=n)
         return 0;
        if(dp[i]!=INT_MAX)
         return dp[i];
       // int a=INT_MAX;
        int cw=0,ch=0;
        for(int j=i;j<n;j++)
        {
           if(cw+a[j][0]<=w)
            {
                dp[i]=min(dp[i],max(ch,a[j][1])+f(j+1));
                ch=max(ch,a[j][1]);
                cw+=a[j][0];
            }
            else
             break;
           
        }
        return dp[i];

    }
    int minHeightShelves(vector<vector<int>>& books, int w) {
        
        
        this->n=books.size();
        this->a=books;
        this->w=w;
        dp.resize(n,INT_MAX);
        return f(0);
        
    }
};
class Solution {
public:
   //buy=1     it means you havnot purchesd
   //..buy==0   purchased now sell
    int solve(int i,vector<int>& pr, vector<vector<vector<int>>>&dp,int buy,int cnt)
    {
        if(cnt==0)return 0;
         if(i>=pr.size())
         {return 0;}
         if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];
          int profit=0;
          if(buy==1)profit=max(-pr[i]+solve(i+1,pr,dp,0,cnt),0+solve(i+1,pr,dp,1,cnt));
          if(buy==0)profit=max(pr[i]+solve(i+1,pr,dp,1,cnt-1),0+solve(i+1,pr,dp,0,cnt));
          return dp[i][buy][cnt]=profit;
       
    }
    int maxProfit(vector<int>& pr) {
        // vector<vector<vector<int>>>dp(prices.size()+5,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve(0,prices,dp,1,2);
        int n=pr.size();

        //tabulation
         vector<vector<vector<int>>>dp(pr.size()+5,vector<vector<int>>(3,vector<int>(3,0)));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int cnt=1;cnt<=2;cnt++)
               {
                  
          if(buy==1)dp[i][buy][cnt]=max(-pr[i]+dp[i+1][0][cnt],0+dp[i+1][1][cnt]);
          if(buy==0)dp[i][buy][cnt]=max(pr[i]+dp[i+1][1][cnt-1],0+dp[i+1][0][cnt]);
          
          }
            }
        }
        return dp[0][1][2];



        

    }
};
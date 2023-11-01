class Solution {
public:
    //buy=1     not buy
   //..buy==0   buy now sell
    int solve(int i,vector<int>& pr, vector<vector<int>>&dp,int buy)
    {
         if(i>=pr.size())return 0;
         if(dp[i][buy]!=-1)return dp[i][buy];
          int profit=0;
          if(buy==1)profit=max(-pr[i]+solve(i+1,pr,dp,0),0+solve(i+1,pr,dp,1));
          if(buy==0)profit=max(pr[i]+solve(i+1,pr,dp,1),0+solve(i+1,pr,dp,0));
          return dp[i][buy]=profit;
       
    }
    int maxProfit(vector<int>& pr) {
        // vector<vector<int>>dp(prices.size()+5,vector<int>(2,-1));
        // return solve(0,prices,dp,1);

        //tabulation 
        int n=pr.size();
        vector<vector<int>>dp(pr.size()+5,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
          if(buy==1)profit=max(-pr[i]+dp[i+1][0],0+dp[i+1][1]);
          if(buy==0)profit=max(pr[i]+dp[i+1][1],0+dp[i+1][0]);
          dp[i][buy]=profit; 
            }
        }
        //  return dp[0][1];

         //space optimization 
        vector<int>ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
          if(buy==1)profit=max(-pr[i]+ahead[0],0+ahead[1]);
          if(buy==0)profit=max(pr[i]+ahead[1],0+ahead[0]);
          curr[buy]=profit; 
            }
            ahead=curr;
        }
        //  return ahead[1];


         //only using variable
          
        ahead[0]=ahead[1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
          if(buy==1)profit=max(-pr[i]+ahead[0],0+ahead[1]);
          if(buy==0)profit=max(pr[i]+ahead[1],0+ahead[0]);
          curr[buy]=profit; 
            }
            ahead=curr;
        }
         return ahead[1];

    }
};
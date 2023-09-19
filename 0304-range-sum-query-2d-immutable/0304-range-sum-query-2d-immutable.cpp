class NumMatrix {
public:
  vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+nums[i-1][j-1]-dp[i-1][j-1];
            }
        }
         
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
               cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }



    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       return dp[row2+1][col2+1]-dp[row1+1-1][col2+1]-dp[row2+1][col1+1-1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
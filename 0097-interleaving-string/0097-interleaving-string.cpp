class Solution {
public:
  bool solve(string &s1, string &s2, string &s3 , int i,int j,int k,vector<vector<bool>>&dp)
  {
    // if(i>=0&&j>=0 && dp[i][j]!=-1)return dp[i][j];
       if(i<0&&j<0&&k<0)
        {
            return true;
        }
      
      // bool ans=false;
      if(i>=0&&j>=0&&k>=0&&s2[j]==s3[k] && s1[i]==s3[k])
      {
         return  (solve(s1,s2,s3,i-1,j,k-1,dp)||solve(s1,s2,s3,i,j-1,k-1,dp));
      }
      else if(j>=0 &&s2[j]==s3[k])
      {
         return solve(s1,s2,s3,i,j-1,k-1,dp);
      }
      else if(i>=0 &&s1[i]==s3[k])
      {
         return solve(s1,s2,s3,i-1,j,k-1,dp);
      }
     
      return false;
  }
    bool isInterleave(string s1, string s2, string s3) {
      if(s3.size()!=s1.size()+s2.size())return false;
        vector<vector<bool>>dp(s1.size()+5,vector<bool>(s2.size()+5,-1));
    return solve(s1,s2,s3,s1.size()-1,s2.size()-1,s3.size()-1,dp);
    }
};
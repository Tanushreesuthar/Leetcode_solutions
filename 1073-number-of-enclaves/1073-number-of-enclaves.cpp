class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& bor,vector<vector<int>>&vis )
   {
       int n=bor.size();
        int m=bor[0].size();
        
       if(i>=n||j>=m||i<0||j<0||bor[i][j]==0||vis[i][j]==1)return;
       vis[i][j]=1;
       dfs(i+1,j,bor,vis);
        dfs(i,j+1,bor,vis);
         dfs(i-1,j,bor,vis);
          dfs(i,j-1,bor,vis);

   }
    int numEnclaves(vector<vector<int>>& bor) {
        int n=bor.size();
        int m=bor[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<bor[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
              dfs(i,j,bor,vis);
            }
        }
        int cnt=0;
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && bor[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
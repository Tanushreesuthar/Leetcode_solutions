class Solution {
public:
    int check(int i, int j ,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        if((i-1>=0 &&  grid[i-1][j]==0)||i-1<0)
        {
            ans++;
        }
        if((j-1>=0 &&grid[i][j-1]==0)||j-1<0)
        {
          ans++;
        }
        if((i+1<n &&grid[i+1][j]==0)||i+1>=n)
        {
          ans++;
        }
        if((j+1<m &&grid[i][j+1]==0)||j+1>=m)
        {
          ans++;
        }
        return ans;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int x=check(i,j,grid);
                    ans+=x;
                }
            }
        }
        return ans;
         
    }
};
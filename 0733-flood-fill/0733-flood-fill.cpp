class Solution {
public:
    typedef pair<int,pair<int,int>> pi;
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
         priority_queue<pi,vector<pi>,greater<pi>>pq;
         int prevcol=grid[sr][sc];
         if(grid[sr][sc]!=color)
         {
             grid[sr][sc]=color;
             pq.push({color,{sr,sc}});
         }
        
        int delr[4]={-1,1,0,0};
        int delc[4]={0,0,1,-1};
        while(!pq.empty())
    {
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        int col=pq.top().first;
        pq.pop();
        
        for(int a=0;a<4;a++)
        {
            int newr=i+delr[a];
            int newc=j+delc[a];
            if(newr>=0&&newr<n&&newc>=0&&newc<m&& grid[newr][newc]==prevcol)
            {
                grid[newr][newc]=col;
                pq.push({col,{newr,newc}});
                
            }
        }
    }
return grid;
    }
};
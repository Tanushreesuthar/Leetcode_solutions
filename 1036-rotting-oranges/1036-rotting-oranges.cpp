class Solution {
public:
  typedef pair<int,pair<int,int>> pi;
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<int>adj[];
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                pq.push({0,{i,j}});  
            }
        }
    int delr[4]={-1,1,0,0};
    int delc[4]={0,0,1,-1};
    int ans=0;
    while(!pq.empty())
    {
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        int time=pq.top().first;
        pq.pop();
        ans=max(ans,time);
        for(int a=0;a<4;a++)
        {
            int newr=i+delr[a];
            int newc=j+delc[a];
            if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]==1)
            {
                grid[newr][newc]=2;
                pq.push({time+1,{newr,newc}});
                
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // cout<<grid[i][j]<<" ";
            if(grid[i][j]==1)return -1;
        }
        // cout<<endl;
    }
    return ans;
    }
};
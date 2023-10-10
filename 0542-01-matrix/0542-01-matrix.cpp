class Solution {
public:
    bool isvalid(int newr,int newc , int n , int m)
    {
       if(newr>=0&&newr<n&&newc>=0 && newc<m)return true;
       return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<m;j++)
             {
                 if(mat[i][j]==0)
                {
                    dis[i][j]=0;
                    q.push({0,{i,j}});
                }
             }
        }
        int delr[4]={-1,1,0,0};
        int delc[4]={0,0,-1,1};
        while(!q.empty())
        {
            int d=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int a=0;a<4;a++)
            {
             int newr=i+delr[a];
             int newc=j+delc[a];
             if(newr>=0 && newr<n && newc>=0 && newc<m && mat[newr][newc]==1)
             {
                 if(dis[newr][newc]>d+1)
                 {
                     dis[newr][newc]=d+1;
                   q.push({d+1,{newr,newc}});
                 }
             }
            }
        }
        return dis;

    }
};
class Solution {
#define ll long long int
public:

   void dfs(vector<int>adj[] ,vector<int>&vis,int node,int&cnt)
   {
       if(vis[node]==1)return ;
       vis[node]=1;
       cnt++;
       for(auto it:adj[node])
       {
           dfs(adj,vis,it,cnt);
       }
       
   }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        // int m=bombs[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
               ll x=bombs[i][0];
                ll y=bombs[i][1];
                ll r=bombs[i][2];
            for(int j=0;j<n;j++)
            {
                
                if(i!=j)
                {
                    ll x1=abs(x-bombs[j][0]);
                    ll y1=abs(y-bombs[j][1]);
                    ll r1=bombs[j][2];
                    if(x1*x1+y1*y1<=r*r)
                    adj[i].push_back(j);
                }
                
            }
           
        }
        int ans=0;
       
        for(int i=0;i<n;i++)
        {
            
                int cnt=0;
                 vector<int>vis(n,0);
                 dfs(adj,vis,i,cnt);
                 ans=max(ans,cnt);
            
        }
        return ans;
    }
};
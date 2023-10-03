class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int v=edges[i][0];
            int u=edges[i][1];
            mp[u]++;
            mp[v]++;
            if(mp[u]==n-1)
            {
                return u;
            }
            if(mp[v]==n-1)
            {
                return v;
            }
            
        }
        return -1;
    }
};
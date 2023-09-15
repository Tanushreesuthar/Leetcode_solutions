class Solution {
public:
    int beautySum(string s) {
        // unordered_map<char,int>mp;
        int n=s.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
           
            for(int j=i;j<n;j++)
            {
              mp[s[j]]++;
              int maxi=0;
        int  mini=1e9;
              for(auto it:mp)
              {
                      maxi=max(it.second,maxi);
                      mini=min(it.second,mini);
              }
            ans+=maxi-mini;
            }
            
        }
        return ans;
    }
};
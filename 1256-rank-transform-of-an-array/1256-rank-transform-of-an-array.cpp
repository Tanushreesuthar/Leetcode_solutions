class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        int cnt=1;
        while(!pq.empty())
        {
            int num=pq.top();
            pq.pop();
            if(mp.find(num)==mp.end())
            {
                mp[num]=cnt;
                cnt++;
            }

        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
         ans.push_back(mp[arr[i]]);
        }
       return ans;
    }
};
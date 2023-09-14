class Solution {
public:
    typedef pair<int,char> p;
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        priority_queue<p>pq;
       for(auto it:mp)
       {
           pq.push({it.second,it.first});
       }
       string temp="";
       while(!pq.empty())
       {
           auto it=pq.top();
           int num=it.first;
           char ch=it.second;
           pq.pop();
           for(int i=0;i<num;i++)
           {
               temp+=ch;
           }
       }
       return temp;

    }
};
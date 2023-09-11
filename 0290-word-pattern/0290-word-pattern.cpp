class Solution {
public:
    bool wordPattern(string t, string s) {
        int i=0;
        vector<string>hehe;
        while(i<s.size())
        {
            string temp="";
          while(i<s.size()&&s[i]!=' ')
          {
             temp+=s[i];
             i++;
          }
          while(i<s.size()&&s[i]==' ')
          i++;
          hehe.push_back(temp);
        }

        for(int i=0;i<hehe.size();i++)
        {
            cout<<hehe[i]<<" ";
        }

        if(hehe.size()>t.size()||hehe.size()<t.size())return false;
        unordered_map<char,string>mp;
        unordered_map<string ,char>mp2;
        for(int i=0;i<t.size();i++)
        {
            if(mp.find(t[i])!=mp.end()&& mp[t[i]]!=hehe[i])return false;
            if(mp2[hehe[i]] && mp2[hehe[i]]!=t[i])return false;
            mp[t[i]]=hehe[i];
            mp2[hehe[i]]=t[i];
        }
        return true;
    }
};
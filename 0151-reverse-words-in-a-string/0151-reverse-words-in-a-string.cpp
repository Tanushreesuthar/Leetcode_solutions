class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans;
        int i=0;
        while(i<n)
        {
            while(i<n&&s[i]==' ')
            {
                i++;
            }
            // cout<<"i->"<<i<<endl;
            string temp="";
            while(i<n&&s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            // cout<<"i->"<<i<<endl;
            // cout<<temp<<endl;
            if(temp.size()>0)
            ans=temp+' '+ans;
        }
        ans.pop_back();
        return ans;
    }
};
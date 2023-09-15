class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
        int pos=0;
        int stringsize=1;
        for(int i=0;i<n;i++){
            //even
           //i,i+1;
          int l=i;
           int r=i+1;
            while(l>=0&&r<n && s[l]==s[r])
            {
               if(r-l+1>stringsize)
               {
                 pos=l;
                 stringsize=r-l+1;
               }
               
                r++;
                l--;
            }

            //odd
             r=i;
           l=i;
            while(l>=0&&r<n && s[l]==s[r])
            {
               if(r-l+1>stringsize)
               {
                 pos=l;
                 stringsize=r-l+1;
               }
               
                r++;
                l--;
            }
        }
        return s.substr(pos,stringsize);
    }
};
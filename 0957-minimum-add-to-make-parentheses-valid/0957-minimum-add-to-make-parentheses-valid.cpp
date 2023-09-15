class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int>st;
        int cnt;
        for(auto it:s)
        {
            if(it=='(' || st.empty())
            {
                st.push(it);
            }
            else {
                if(!st.empty() &&st.top()=='(')
                {
                    st.pop();
                }
                else cnt++;
            }
        }
        return st.size()+cnt;
    }
};
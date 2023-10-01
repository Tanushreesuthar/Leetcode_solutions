class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=0;
        int ans=1e9;
        long long  sum=0 ,temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=nums[i];
        }
        int k=(target/temp);
        k=k+2;
        if(temp>target)
        {
            k=2;
        }
        cout<<"temp->"<<temp<<endl;
        while(j<k*n && i<k*n)
        {
            if(sum<=target)
            {
              sum+=nums[j%n];
            }
             while(sum>target)
                {
                    sum-=nums[i%n];
                    i++;
                } 

            if(sum==target)
            {
                
                ans=min(ans,(max(i,j)-min(i,j)+1));
            }
            j++;
         
        }
        if(ans==1e9)return -1;
        return ans;
    }
};
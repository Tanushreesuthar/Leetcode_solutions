class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int>prefmax(n) , suffmax(n);
        int temp=nums[0];
         for(int i=0;i<n;i++)
         {
            prefmax[i]=max(temp,nums[i]);
            temp=prefmax[i];
         }
         temp=nums[n-1];
         for(int i=n-1;i>=0;i--)
         {
            suffmax[i]=max(temp,nums[i]);
            temp=suffmax[i];
         }
         for(int j=1;j<n-1;j++)
         {
   ans=max(ans,(prefmax[j-1]-nums[j])*1ll*suffmax[j+1]);
         }
         return ans;
    }
};
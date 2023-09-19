class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int n=nums.size();
        if(n==0)return {-1,-1};
      
        int maxi=-1e9;
        int mini=1e9;
        int s=0;
        int e=n-1;
        //max index
        while(s<=e)
        {
            int mid=s+(e-s)/2;
          if(nums[mid]==target)
          {
            maxi=max(maxi,mid);
           s=mid+1;
          }
          else if(nums[mid]>target)
          {
            e=mid-1;
          }
          else 
          s=mid+1;
        }
         //min index
          s=0;
          e=n-1;
          
        while(s<=e)
        {
          
            int mid=s+(e-s)/2;
            
          if(nums[mid]==target)
          {
            mini=min(mini,mid);
          
           e=mid-1;
          }
          else if(nums[mid]>target)
          {
            e=mid-1;
          }
          else 
          s=mid+1;
        }
        if(mini==1e9&& maxi==-1e9)return {-1,-1};
       if(mini==1e9&& maxi!=-1e9)return {-1,maxi};
       if(mini==-1e9 && maxi==1e9)return {mini,-1};
       return {mini,maxi};
    
    }
};
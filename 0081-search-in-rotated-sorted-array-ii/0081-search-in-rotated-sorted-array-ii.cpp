class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]==nums[e] && nums[e]==nums[s])
            {
                s++;
                e--;
                continue;
            }
            else if(nums[mid]>=nums[s])
            {
              if(nums[mid]>=target && nums[s]<=target)
              {
                e=mid-1;
              }
              else {
                  s=mid+1;
              }

            }
            else if(nums[mid]<=nums[e])
            {
              if(nums[mid]<=target && nums[e]>=target)
              {
                   s=mid+1;
                
              }
              else {
                 e=mid-1;
              }

            }
        }
       return false;
    }
};
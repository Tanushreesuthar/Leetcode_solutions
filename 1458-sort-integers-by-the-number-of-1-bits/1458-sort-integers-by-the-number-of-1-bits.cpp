class Solution {
public:
  int bitcnt(int a)
  {
      int cnt=0;
    for(int i=0;i<32;i++)
   {
     if(a>>i & 1)
     {
         cnt++;
     }
   }
   return cnt;
  }
//      bool static cmp(int &a, int &b) {
//     return (bitcnt(a) < bitcnt(b));
// }
// bool cmp(int &a, int &b) {
//     Solution s; // Create an instance of the Solution class
//     return (s.bitcnt(a) < s.bitcnt(b));
// }
    vector<int> sortByBits(vector<int>& arr) {
       
          sort(arr.begin(), arr.end(), [this](int a, int b) {
            return bitcnt(a) == bitcnt(b) ? a < b : bitcnt(a) < bitcnt(b);
        });
        return arr;
       
    }
};
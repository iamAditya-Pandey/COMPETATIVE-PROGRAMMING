class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n =nums.size();
        deque<long long > mn,mx;
        long long ans=0;
        long long l=0;

        for(int r=0;r<nums.size();r++){
            while(!mn.empty() && nums[mn.back()]>=nums[r])
                mn.pop_back();
            mn.push_back(r);

            while(!mx.empty() && nums[mx.back()]<=nums[r])
                mx.pop_back();
            mx.push_back(r);

          while(l<=r){
              long long max =nums[mx.front()];
              long long min =nums[mn.front()];
              long long val=(r-l+1);

              if((max-min)*val<=k){
                  break;
              }

              if(mn.front()==l) mn.pop_front();
              if(mx.front()==l) mx.pop_front();
              l++;
          }
            ans+=(r-l+1);
        }
        return ans;
    }
};

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n =nums.size();
        int ans=0;

        for(int i=0;i<n-1;i++){
            double sm=0;
            int cnt=0;

            for(int j=i+1;j<n;j++){
                sm+=nums[j];
                cnt++;
            }
            if(nums[i]>sm/cnt)ans++;
        }
        return ans;
    }
};

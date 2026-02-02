class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        multiset<long long> small, big;
        long long ssum = 0;
        int need = k-1;
        for (int i = 1; i <= dist + 1; i++) {
            big.insert(nums[i]);
        }
        while (small.size() < need) {
            auto it = big.begin();
            ssum += *it;
            small.insert(*it);
            big.erase(it);
        }
         long long ans = ssum;
        for (int i = dist + 2; i < nums.size(); i++) {
            int add = nums[i];
            int rem = nums[i - (dist + 1)];
            auto it = small.find(rem);
            if (it != small.end()) {
                ssum -= rem;
                small.erase(it);
            } else {
                big.erase(big.find(rem));
            }
            if (!small.empty() && add < *small.rbegin()) {
                small.insert(add);
                ssum += add;
            } else {
                big.insert(add);
            }
            while (small.size() < need) {
                auto it2 = big.begin();
                ssum += *it2;
                small.insert(*it2);
                big.erase(it2);
            }
            while (small.size() > need) {
                auto it2 = prev(small.end());
                ssum -= *it2;
                big.insert(*it2);
                small.erase(it2);
            }
            ans = min(ans, ssum);
        }
        return ans + nums[0];
    }
};

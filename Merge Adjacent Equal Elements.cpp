class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n =nums.size();
        vector<long long> st;

        for(int x:nums){
                st.push_back(x);
            while(st.size()>=2 && st[st.size()-1]==st[st.size()-2]){
            long long v=st.back();
                st.pop_back();
                st.back()+=v;
            }
        }
        return st;
    }
};

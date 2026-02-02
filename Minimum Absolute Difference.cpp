class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mindif=arr[n-1]-arr[n-2];
        for(int i=1;i<n;i++){
            mindif=min(mindif,arr[i]-arr[i-1]);
        }
        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1] == mindif){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};

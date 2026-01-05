class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum =0;
        int mn = INT_MAX;

        int cntn =0;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                mn = min(mn,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    sum-=matrix[i][j];
                    cntn++;
                }
                else{
                    sum+= matrix[i][j];
                }
            }
        }
        return (cntn%2==1)?sum-2*mn:sum;
    }
};

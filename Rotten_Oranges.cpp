class Solution {
private:
    vector<int> delRow = {-1,0,1,0};
    vector<int> delCol = {0,1,0,-1};

    bool isValid(int &i, int &j, 
                 int &n, int &m){
        if(i<0 || i>=n) return false;
        if(j<0 || j>=m) return false;
        return true;
    }
    
public:
    int orangesRotting(vector<vector<int>> &grid){

        int n = grid.size();
        int m = grid[0].size();
        int tm= 0;
        int total=0;

        int cnt=0;

        queue<pair<int,int>> q;
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j]!=0) total++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int k =q.size();
            cnt += k;

            while(k--){
                
                auto cell = q.front();
                q.pop();
                int row = cell.first;
                int col = cell.second;
              
                for(int i=0;i<4;i++){
                    int nRow = row + delRow[i]; 
                    int nCol = col + delCol[i]; 
                    if(isValid(nRow,nCol,n,m) && 
                       grid[nRow][nCol]==1){
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    }
                }
            }
            if(!q.empty()) tm++;
        }
        if(total == cnt) return tm;
        return -1;
    }
};

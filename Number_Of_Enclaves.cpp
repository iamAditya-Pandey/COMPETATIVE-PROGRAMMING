class Solution{
public:

 vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    bool isValid(int &i, int &j, 
                 int &n, int &m) {
        
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;
        
        return true;
    }
   
    void bfs(vector<vector<int>> &grid,
             queue<pair<int,int>> &q,
             vector<vector<bool>> &vis) {
    
        int n = grid.size();
        int m = grid[0].size(); 
        while(!q.empty()) {

            auto cell = q.front();
            q.pop();
  
            int row = cell.first;
            int col = cell.second;
  
            for(int i=0; i < 4; i++) {

                int nRow = row + delRow[i]; 
                int nCol = col + delCol[i]; 
 
                if(isValid(nRow, nCol, n, m) && 
                   grid[nRow][nCol] == 1 
                   && vis[nRow][nCol] == false) {
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        vector<vector<bool>>  vis(n,vector<bool>(m,false));
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if( (i==0 || i==n-1 || j==0 || j==m-1)&&grid[i][j]==1){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }

        bfs(grid,q,vis);

        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};

class Solution{

    private :

    void dfs(int node,vector<int> adjl[], int vis[]){

        vis[node]=1;

        for(auto it:adjl[node]){
            if(!vis[it]){
                dfs(it,adjl,vis);
            }
        }
    }
public:
    int numProvinces(vector<vector<int>> adj) {
       
       int n = adj.size();

       vector<int> adjl[n];

       for(int i =0;i<n;i++){

        for(int j=0;j<n;j++){

            if(adj[i][j]==1){

                adjl[i].push_back(j);
                adjl[j].push_back(i);
            }
        }
       }

       int vis[n]={0};
       int cnt=0;

       for(int i=0;i<n;i++){

        if(!vis[i]){
            cnt++;
            dfs(i,adjl,vis);
        }
       }
       return cnt;
    }
};

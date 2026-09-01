class Solution {
public:

    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

    void bfs(int row,int col,vector<vector<char>> &grid,vector<vector<bool>> &visited ){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col] = true;
        while(!q.empty()){
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            visited[curr_row][curr_col] = true;

            for(vector<int> &vec : dir){
                int new_row = vec[0] + curr_row;
                int new_col = vec[1] + curr_col;
                if(new_row < n && new_row >=0 && new_col < m && new_col >=0 && grid[new_row][new_col] == '1' && !visited[new_row][new_col]){
                    q.push({new_row,new_col});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

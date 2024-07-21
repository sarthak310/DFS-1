// time: O(mxn)
// space: O(mxn)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // right, left, down, up
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push(make_pair(i,j));
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            for(int j = 0; j < sz; j++) {
                pair<int,int> curr = q.front();
                q.pop();
                for(int i = 0; i < dirs.size(); i++) {
                    int x = curr.first + dirs[i][0];
                    int y = curr.second + dirs[i][1];
                    // right, left, down, up
                    if(x >= 0 && y >= 0 && x < m && y < n) {
                        if(mat[x][y] == -1) {
                            mat[x][y] = level; // we can directly do curr val + 1, so no need of level var
                            q.push(make_pair(x,y));
                        }
                        else if(mat[x][y] == 0) {
                            continue;
                        }
                        else { // probably dont need this, bcoz dist 2 will not appear when we are processing lvl 1
                            mat[x][y] = min(mat[x][y], level);
                        }
                    }
                }
            }
        }
        return mat;
    }
};
// time: O(mxn)
// space: O(mxn)

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) {
            return image;
        }
        int prevColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        // down, right, up, left
        image[sr][sc] = color;
        q.push(make_pair(sr,sc));
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                pair<int,int> curr = q.front();
                q.pop();
                //image[curr.first][curr.second] = color;
                for(int j = 0; j < dirs.size(); j++) {
                    int x = curr.first + dirs[j][0];
                    int y = curr.second + dirs[j][1];
                    if(x >= 0 && y >= 0 && x < m && y < n && image[x][y] == prevColor) {
                        image[x][y] = color;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
        return image;
    }
};
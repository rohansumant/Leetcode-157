class Solution {
public:
    vector<vector<int>> a,vis;
    int r,c;
    
    void go(int x,int y,int &sum,int &mx) {
        if(x < 0 || y < 0 || x == r ||
           y == c || !a[x][y] || vis[x][y]) {
            mx = max(mx,sum);
            return;
        }
        vis[x][y] = 1;
        sum += a[x][y];
        static int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny = y+dy[i];
            go(nx,ny,sum,mx);
        }
        sum -= a[x][y];
        vis[x][y] = 0;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        a = grid;
        r = a.size(); c = a[0].size();
        vis = vector<vector<int>>(r,vector<int>(c,0));
        int ans = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(a[i][j]) {
                    int sum = 0, mx = 0;
                    go(i,j,sum,mx);
                    ans = max(ans,mx);
                }
            }
        }
        return ans;
    }
};

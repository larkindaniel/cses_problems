#include <bits/stdc++.h>
using namespace std;

int INF = 1 << 30; 

int dir[4][2] = {
    {0,1},
    {0,-1},
    {1,0},
    {-1,0}
};

void multi_bfs(vector<string>&grid, vector<int>&starting, vector<vector<int>>&visiting, vector<string>&path){
    queue<int>q; 
    int ROWS = visiting.size(), COLS = visiting[0].size();
    

    for (auto s: starting){
        int r = s/COLS, c = s%COLS; 
        visiting[r][c] = 0;
        q.push(s);
    }

    while (!q.empty()){
        int cord = q.front(); 
        q.pop(); 
        int r = cord/COLS, c = cord%COLS;
        for (auto [dr,dc]: dir){
            int nr = dr+r, nc=dc+c;
            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS) continue; 
            if (grid[nr][nc] == '#' || visiting[nr][nc] <= visiting[r][c] + 1) continue; 
            visiting[nr][nc] = visiting[r][c] + 1;
            int nCord = nr*COLS + nc; 
            q.push(nCord);
            
            if (dr == -1) path[nr][nc] = 'U';
            else if (dr == 1) path[nr][nc] = 'D';
            else if (dc == -1) path[nr][nc] = 'L';
            else if (dc == 1) path[nr][nc] = 'R';
        }
    }
}

void solve(int ROWS, int COLS, vector<string>&grid){
    vector<int>start;
    vector<int>monsters;
    for (int r = 0; r < ROWS; ++r){
        for (int c = 0; c < COLS; ++c){
            int cord = r*COLS + c;
            if (grid[r][c] == 'A')
                start.push_back(cord);
            else if (grid[r][c] == 'M')
                monsters.push_back(cord);
        }
    }
    

    vector<vector<int>>mVisiting(ROWS, vector<int>(COLS, INF));
    vector<vector<int>>sVisiting(ROWS, vector<int>(COLS, INF));

    vector<string>mPath(ROWS, string(COLS, '#'));
    vector<string>sPath(ROWS, string(COLS, '#'));

    multi_bfs(grid, monsters, mVisiting, mPath);
    multi_bfs(grid, start, sVisiting, sPath);

    for (int r = 0; r < ROWS; ++r){
        for (int c = 0; c < COLS; ++c){
            if (!(r == 0 || r == ROWS-1 || c == 0 || c == COLS-1)) continue; 
            if (sVisiting[r][c] >= mVisiting[r][c]) continue; 

            cout << "YES\n" << sVisiting[r][c] << '\n';
      
            string res;
            int nr = r, nc = c;  
            for (int i = 0; i < sVisiting[r][c]; ++i){
                char dir = sPath[nr][nc]; 
                res.push_back(dir); 
                if (dir == 'D') nr--;
                else if (dir == 'U') nr++;
                else if (dir == 'L') nc++;
                else if (dir == 'R') nc--;
            } 
            reverse(res.begin(), res.end());
            cout << res << '\n';
            return; 
        }
    }
    cout << "NO\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ROWS, COLS; 
    cin >> ROWS >> COLS; 

    vector<string>grid(ROWS);
    for (int i = 0; i < ROWS; ++i){
        cin >> grid[i]; 
    }

    solve(ROWS, COLS, grid);
}
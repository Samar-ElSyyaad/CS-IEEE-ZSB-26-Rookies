#include <bits/stdc++.h>
using namespace std;
#define summora ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define foor for (ll i = 0; i < n; i++)

class CountingRooms {
    public:

int n,m;
vector <vector <int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
CountingRooms(int r, int c): n(r), m(c) {}
int solve (vector <string>&grid){
    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j]=='.'){ ans++;
            dfs(i,j, grid);
        }
    }
    }
return ans;
}

void dfs (int i, int j, vector <string> &grid){
    grid[i][j] = '#';
    for (auto dir : directions){
        int r = i + dir[0];
        int c = j + dir[1];
        if (r < 0 || c < 0 || r>= n || c >= m || grid[r][c]=='#')continue;
        dfs(r,c,grid); 
    }
}
};

int32_t main()
{summora;
int n,m;
cin >> n >> m;
vector <string> grid (n);

foor cin >> grid[i];

CountingRooms toSolve (n,m);
cout << toSolve.solve(grid);
return 0;
}


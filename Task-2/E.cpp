#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define summora ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 2005;
int n, m;

bool vis[N][N];
ll distArr[N][N];  
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool valid(int newX, int newY) {
    return newX >= 1 && newX <= n && newY >= 1 && newY <= m && !vis[newX][newY];
}

void BFS(vector<pair<int, int>> &burningTrees) {
    queue<pair<int, int>> q;

    for (auto &it : burningTrees) {
        vis[it.first][it.second] = 1;
        distArr[it.first][it.second] = 0;
        q.push({it.first, it.second});
    }

    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if (valid(newX, newY)) {
                vis[newX][newY] = 1;
                distArr[newX][newY] = distArr[currentX][currentY] + 1;
                q.push({newX, newY});
            }
        }
    }
}

void solve(int t) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            distArr[i][j] = -1;

    cin >> n >> m;
    int k;
    cin >> k;

    vector<pair<int, int>> burningTrees;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        burningTrees.push_back({x, y});
    }

    BFS(burningTrees);

    ll currentDist = -1;
    int ansX = 0, ansY = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] && distArr[i][j] > currentDist) {
                currentDist = distArr[i][j];
                ansX = i;
                ansY = j;
            }
        }
    }
    cout << ansX << " " << ansY << "\n";
}

int main() {
    summora;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    while (t--) {
        solve(t);
    }
    return 0;
}

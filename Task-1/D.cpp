#include <bits/stdc++.h>
using namespace std;
#define summora ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int N = 1e3 + 5;
int n, m, k;
char arr[N][N];
bool vis[N][N],leaves[N][N];
 
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };
 
bool valid(int x, int y) {
	return x < n && x >= 0 && y < m && y >= 0 && arr[x][y] == '.';
}
 
bool isLeaf(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny)) {
			if (!leaves[nx][ny]) {
				if (!vis[nx][ny]) {
					return 0;
				}
			}
		}
	}
	return 1;
}
 
void dfs(int x,int y) {
	vis[x][y]=1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (valid(nx, ny)) {
			if (!vis[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
	if (isLeaf(x, y)) {
		leaves[x][y] = 1;
		if (k) {
			arr[x][y] = 'X';
			k--;
		}
	}
}

int32_t main()
{summora;

   cin >> n >> m>>k;
	bool flag = 0;
	pair<int ,int> index;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (!flag) {
				if (arr[i][j] == '.') {
					index.first = i;
					index.second = j;
					flag = 1;
				}
			}
		}
	}
    
    cout << endl;
	dfs(index.first, index.second);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define summora                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define yn           \
    cout << "YES\n"; \
    else cout << "NO\n"

vector<int> adj[10005];
int vis[10005];

void dfs(int i)
{
    vis[i] = 1;
    for (auto x : adj[i])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}

int32_t main()

{
    summora;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    if (m != n - 1)
    {
        cout << "NO";
        return 0;
    }

    int cc = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cc++;
            dfs(i);
        }
    }

    if (cc == 1)
        yn;

    return 0;
}


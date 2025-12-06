#include <bits/stdc++.h>
using namespace std;
#define summora                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int32_t main()
{
    summora;
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << mp[i] << endl;
    }
    return 0;
}

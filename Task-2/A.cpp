#include <bits/stdc++.h>
using namespace std;
#define summora                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
 
class MessageRoute {
public:
    MessageRoute() {
        readInput();
        computeMinimumPathWithBFS();
        printResult();
    }
    int n, m;
    vector<vector<int>> adj;
    void readInput(){
        cin >> n >> m;
        adj = vector<vector<int>>(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
 
    vector<int> parents;
    void computeMinimumPathWithBFS() {
        parents = vector<int>(n + 1);
        deque<int> deq;
        deq.push_back(1);
        parents[1] = -1;
        while (!deq.empty()) {
            int node = deq.front();
            deq.pop_front();
            for (auto child: adj[node]) {
                if (parents[child] != 0) continue;
                parents[child] = node;
                deq.push_back(child);
            }
        }
    }
 
    void printResult(){
        if (parents[n] == 0) {
            cout << "IMPOSSIBLE";
            return;
        }
        vector<int> path;
        int node = n;
        while (node != -1) {
            path.push_back(node);
            node = parents[node];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (auto item: path) cout << item << " ";
    }
};
 
int main() {
summora;
    MessageRoute solver;
    return 0;
}

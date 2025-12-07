#include <bits/stdc++.h>
using namespace std;
#define summora ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define vec(i) vector<i>

vector<int>adj[100005];
vector<int>vis(100005,0);
 
void dfs(int v){
  vis[v] = 1; 
  for(auto it: adj[v]){
    if(vis[it] == 0){
      dfs(it);
    }
  }
}

int32_t main()
{summora;

     int n , m ;cin>>n>>m;
 for(int i = 0 ;i<m;i++){
  int a, b;  cin>>a>>b;
  adj[a].pb(b);
  adj[b].pb(a);
 }
 vec(int) arr; 
 for(int i = 1;i<=n;i++){
     if(vis[i] == 0 ){
      arr.pb(i);
      dfs(i);
     }
 }
 if(arr.size() == 1){
   cout<<0<<endl; 
 }
 else{
  cout<<arr.size()-1<<endl;
  for(int i = 1;i<arr.size(); i++){
    cout<<arr[i-1]<<" "<<arr[i]<<endl; 
  }
 }

return 0;
}

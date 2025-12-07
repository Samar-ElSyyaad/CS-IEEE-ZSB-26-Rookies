#include <bits/stdc++.h>
using namespace std;
#define summora ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int32_t main()
{summora;
int sz,k;
    cin>>sz>>k;
    int nodes[1001]={0};
    for (int i=0; i<k; i++) {
        int t,p;
        cin>>t>>p;
        nodes[t]++;
        nodes[p]++;
    }
    for (int i=1; i<=sz; i++) {
        if (nodes[i]==0) {
            cout<<sz-1<<endl;
            for (int j=1; j<=sz; j++) {
                if (i!=j) {
                    cout<<j<<" "<<i<<endl;
                }
            }
            return 0;
        }
    }
    return 0;
return 0;
}


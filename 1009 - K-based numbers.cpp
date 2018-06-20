#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll b, ll p) {
    ll res = 1, x = b;
    while(p) {
        if(p & 1) res = res * x;
        x = x*x, p >>= 1;
    }
    return res;
}

bool arr[20];
ll n, k;
ll invalid(int pos, bool v)
{
    if(pos == n+1) {
        if(v == 0) {
            ll cnt = 0;
            for(int i = 1; i <= n; i++)
                if(arr[i]) cnt++;
            ll ans = power(k-1, cnt);
            return ans;
        }
        return 0;
    }

    ll ret1, ret2;

    arr[pos] = 1;
    ret1 = invalid(pos+1, v);

    arr[pos] = 0;
    ret2 = invalid(pos+1, v*arr[pos-1]);

   return ret1+ret2;
}

int main()
{
    n, k;
    scanf("%d %d", &n, &k);

    printf("%lld", power(k, n)-invalid(1, 1));
}

/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}


    
const int MAXN = 2e9;

ll expo (ll a, ll b) {
    ll ans = 1;
    while (b) {
        if(b & 1) {
            ans = (ans * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;


    auto MAX = [&] (ll x) {
        ll y = x;
        int p = 0;
        while (y * x <= MAXN)
            y *= x, ++p;

        return p;
    };
    
    ll ans = count(all(a), 1) * n;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) continue;
        for (int j = 0; j <= min(n - 1, MAX(a[i])); ++j) {
            if (expo(a[i], j + 1) <= a[j]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!

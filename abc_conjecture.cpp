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



void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> bpos;
    vector<vector<int>> prefix(n, vector<int>(3, 0));

    for (int i = 0; i < n; ++i) {
        
        prefix[i][s[i] - 'a'] += 1;

        if (s[i] == 'b') {
            bpos.push_back(i);
        }
        if (i > 0) {
            prefix[i][0] += prefix[i - 1][0];
            prefix[i][1] += prefix[i - 1][1];
            prefix[i][2] += prefix[i - 1][2];
        }
    }   

    if (bpos.empty()) {
        cout << "0\n";
        return;
    }

    if (bpos.size() == 1) {
        cout << min(prefix[bpos[0]][0], prefix[n - 1][2] - prefix[bpos[0]][2]) << endl;
        return;
    }

    int ans = n;
    for (int i = 0; i < (int) bpos.size() - 1; ++i) {
        auto l = bpos[i];
        auto r = bpos[i + 1];
        ans = min(ans, prefix[l][0] + prefix[n - 1][2] - prefix[r][2]);
    }

    ans = min(ans, prefix[n - 1][2] - prefix[bpos[0]][2]);
    ans = min(ans, prefix[bpos.back()][0]);

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

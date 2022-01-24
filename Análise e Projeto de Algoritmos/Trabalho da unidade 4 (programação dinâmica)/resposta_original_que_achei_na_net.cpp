#include <bits/stdc++.h>
using namespace std;

string a, b;
int cache[1010][1010];
int k;

int dpSol(int i, int j)
{
    if(i == a.size() || j == b.size())
        return 0;
    if(cache[i][j] != -1)
        return cache[i][j];
    int ans = 0;
    for(int l = k; i + l - 1 < a.size() and j + l - 1 < b.size(); l++){
        if(a.substr(i, l) == b.substr(j, l))
            ans = max(dpSol(i + l, j + l) + l, ans);
        else
            ans = max({dpSol(i + 1, j), dpSol(i, j + 1), ans});
    }
    return cache[i][j] = ans;
}

int main(){

    while(cin >> k && k)
    {
        cin >> a;
        cin >> b;
        memset(cache, -1, sizeof(cache));
        cout << dpSol(0, 0) << endl;
    }

    return 0;
}

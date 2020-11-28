#include <iostream>
using namespace std;
typedef long long ll;

#define M_MOD 1000000007

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    ll value;
    cin >> value;

    ll res = 1;

    while (value > 0) {
        res *= 2;
        res = res % M_MOD;
        value--;
    }

    cout << res % M_MOD << endl;
}

#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    int len;
    cin >> len;

    for (int i = 0; i < len; i++) {
        ll x;
        ll y;
        cin >> y >> x;
        ll res;

        if (x >= y) {
            if (x % 2 != 0) {
                res = x * x - (y - 1);
            }
            else {
                res = (x - 1) * (x - 1) + y;
            }
        }
        else {
            if (y % 2 != 0) {
                res = (y - 1) * (y - 1) + x;
            }
            else {
                res = y * y - (x - 1);
            }
        }

        cout << res << " ";
    }

    cout << endl;
}

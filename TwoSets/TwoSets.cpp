#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    ll value;
    cin >> value;

    ll sum = (value * (value + 1)) / 2;
    string res = "NO";

    if (sum % 2 == 0) {
        res = "";
        ll goal = sum / 2;
        string res1 = "";
        string res2 = "";
        int size1 = 0;
        int size2 = 0;
        ll border = value;

        while (goal > 0) {
            if (goal < border) {
                for (ll i = border; i > goal; i--) {
                    res2 += to_string(i) + " ";
                    size2++;
                }
                border = goal;
            }
            goal -= border;
            res1 += to_string(border) + " ";
            size1++;
            border--;
        }
        while (border > 0) {
            res2 += to_string(border) + " ";
            size2++;
            border--;
        }

        res = "YES\n" + to_string(size1) + "\n" + res1 + "\n" + to_string(size2) + "\n" + res2;
    }

    cout << res << endl;
}

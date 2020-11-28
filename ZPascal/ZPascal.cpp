#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    int value;
    cin >> value;
    int ld = 1;
    int res = -1;

    do {
        ld++;
        if (ld * ld > value) {
            res = value - 1;
            break;
        }
    } while (value % ld != 0);

    if (res == -1) {
        res = value - value / ld;
    }

    cout << res << endl;
}

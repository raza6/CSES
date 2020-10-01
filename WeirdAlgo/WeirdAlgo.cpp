#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int startNumber;
    cin >> startNumber;
    cout << startNumber;

    ll currNumber = startNumber;
    while (currNumber != 1) {
        if (currNumber % 2 == 0) {
            currNumber = currNumber / 2;
        }
        else {
            currNumber = (currNumber * 3) + 1;
        }
        cout << " " << currNumber;
    }
}

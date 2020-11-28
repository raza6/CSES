#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

#define M_MOD 1000000007

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    int arrSize;
    cin >> arrSize;

    set<int> values;

    for (int i = 0; i < arrSize; i++) {
        int val;
        cin >> val;
        values.insert(val);
    }

    cout << values.size() << endl;
}

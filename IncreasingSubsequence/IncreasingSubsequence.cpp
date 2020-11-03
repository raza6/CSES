#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int arrSize;
    cin >> arrSize;

    //vector<int> values(arrSize);
    vector<int> lis(arrSize, 0); //1 for dumb impl, 0 for log

    int best = 0;
    for (int i = 0; i < arrSize; i++) {
        int currValue;
        cin >> currValue;
        int idx = lower_bound(lis.begin(), lis.begin() + best, currValue) - lis.begin();
        lis[idx] = currValue;
        best = max(best, idx + 1);
    }

    /*
    int best = 1;
    for (int i = 1; i < arrSize; i++) {
        for (int j = 0; j < i; j++) {
            if (values[j] < values[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        best = max(best, lis[i]);
    }
    */

    cout << best << endl;
}


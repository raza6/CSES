#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int arrSize;
    cin >> arrSize;

    //vector<int> values(arrSize);
    vector<int> lis(arrSize, 0); //1 for dumb impl, 0 for log
    vector<int> indices(arrSize, -1);

    int len = 0;
    for (int i = 0; i < arrSize; i++) {
        int currValue;
        cin >> currValue;
        int idx = lower_bound(lis.begin(), lis.begin() + len, currValue) - lis.begin();
        lis[idx] = currValue;
        len = max(len, idx + 1);
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

    cout << len << endl;
}


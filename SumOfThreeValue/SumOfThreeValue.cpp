#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    int arraySize;
    cin >> arraySize;

    int targetSum;
    cin >> targetSum;

    vector<int> values(arraySize);
    vector<int> unsorted(arraySize);
    bool found = false;
    int res1, res2, res3;

    for (int i = 0; i < arraySize; i++) {
        cin >> values[i];
        unsorted[i] = values[i];
    }

    sort(values.begin(), values.end());

    //2 pointers algorithm
    for (int i = 0; i < arraySize; i++) {
        int currValue = values[i];

        int lower = i + 1;
        int higher = arraySize - 1;

        while (lower < higher) {
            int currSum = values[lower] + values[higher] + currValue;
            if (currSum == targetSum) {
                found = true;
                res1 = values[i];
                res2 = values[lower];
                res3 = values[higher];
                break;
            }
            else if (currSum > targetSum) {
                higher--;
            }
            else {
                lower++;
            }
        }

        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        //find position
        int p1 = distance(unsorted.begin(), find(unsorted.begin(), unsorted.end(), res1)) + 1;
        unsorted[p1 - 1] = -1;
        int p2 = distance(unsorted.begin(), find(unsorted.begin(), unsorted.end(), res2)) + 1;
        unsorted[p2 - 1] = -1;
        int p3 = distance(unsorted.begin(), find(unsorted.begin(), unsorted.end(), res3)) + 1;
        cout << p1 << " " << p2 << " " << p3 << endl;
    }
}

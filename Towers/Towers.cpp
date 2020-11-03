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

    int arraySize;
    cin >> arraySize;

    //vector<int> values(arraySize);
    vector<int> towers(arraySize, INT32_MAX);
    int towerNb = 0;

    for (int i = 0; i < arraySize; i++) {
        int currValue;
        cin >> currValue;
        // Dichotomic
        int lower = 0;
        int higher = towerNb;

        while (lower < higher) {
            int mid = (lower + higher) / 2;
            if (towers[mid] > currValue) { //Looking downward
                higher = mid;
            }
            else {//Looking upward
                lower = mid + 1;
            }
        }
        if (lower == towerNb) {
            towers[towerNb] = currValue;
            towerNb++;
        }
        else {
            towers[lower] = currValue;
        }

        /*
        for (int j = 0; j <= towerNb; j++) {
            if (j == towerNb) {
                towerNb++;
                towers[j] = currValue;
                break;
            }
            else {
                if (currValue < towers[j]) {
                    towers[j] = currValue;
                    break;
                }
            }
        }
        */
    }

    cout << towerNb << endl;
}

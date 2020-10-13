#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Return ordered vector of all possible sums
    auto all_subsets_sum = [](const vector<int>& v) {
        int arraySize = v.size();
        vector<ll> allSum(1 << arraySize);
        int vectorIter = 0;
        for (int i = 0; i < (1 << arraySize); i++) {
            ll sum = 0;
            for (int j = 0; j < arraySize; j++) {
                if (i & (1 << j)) {
                    sum += v[j];
                    //cout << values[j] << " ";
                }
            }
            //cout << "sum : " << sum << endl;
            allSum[vectorIter] = sum;
            vectorIter++;
        }

        sort(allSum.begin(), allSum.end());
        return allSum;
    };

    //Read inputs

    int arraySize;
    cin >> arraySize;

    int desiredSum;
    cin >> desiredSum;

    vector<int> values(arraySize);

    for (int i = 0; i < arraySize; i++) {
        cin >> values[i];
    }

    //MITM solving

    auto left = all_subsets_sum({ begin(values), begin(values) + arraySize / 2 });
    auto right = all_subsets_sum({ begin(values) + arraySize / 2, end(values) });

    //cout << "done";

    ll validSum = 0;
    for (ll sum : left) {
        ll lookingFor = desiredSum - sum;
        auto le = lower_bound(right.begin(), right.end(), lookingFor);
        auto ri = upper_bound(right.begin(), right.end(), lookingFor);
        validSum += ri - le;
    }

    cout << validSum << endl;
}

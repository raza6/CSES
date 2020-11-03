#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;

#define MAXSUM 1000000

int computeSum(int currentSum, int desiredSum, const vector<int> &coins) {
    int sumFound = 0;
    for (int c : coins) {
        int sum = currentSum + c;
        if (sum == desiredSum) {
            sumFound++;
        }
        else if (sum > desiredSum) {
            return sumFound;
        }
        else {
            //recursive call
            int res = computeSum(sum, desiredSum, coins);
            sumFound += res;
        }
    }

    return sumFound;
}

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    int coinsLength, desiredSum;
    cin >> coinsLength >> desiredSum;

    vector<int> coins(coinsLength);
    vector<int> possibleSum(desiredSum + 1, 0);
    possibleSum[0] = 1;

    for (int i = 0; i < coinsLength; i++) {
        cin >> coins[i];
    }

    //int res = computeSum(0, desiredSum, coins);

    for (int i = 1; i <= desiredSum; i++) {
        for (int j = 0; j < coinsLength; j++) {
            if (i >= coins[j]) {
                possibleSum[i] += possibleSum[i - coins[j]];
                possibleSum[i] = possibleSum[i] % 1000000007;
            }
        }
        /*
        for (int c : possibleSum) {
            cout << c << " ";
        }
        cout << endl;
        */
    }

    cout << possibleSum[desiredSum] << endl;
}

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
typedef long long ll;

#define INT_MAX 2147483647

void build(vector<int> &values, vector<int> &segTreeMin, int curridx, int blow, int bhigh) {
    if (blow == bhigh) {
        segTreeMin[curridx] = values[blow];
    }
    else {
        int bmid = (blow + bhigh) / 2;
        build(values, segTreeMin, curridx * 2, blow, bmid);
        build(values, segTreeMin, curridx * 2 + 1, bmid + 1, bhigh);
        segTreeMin[curridx] = min(segTreeMin[curridx * 2], segTreeMin[curridx * 2 + 1]);
    }
}

void update(int curridx, vector<int> &segTreeMin, int blow, int bhigh, int pos, int nval) {
    if (blow == bhigh) {
        segTreeMin[curridx] = nval;
    }
    else {
        int bmid = (blow + bhigh) / 2;
        if (pos <= bmid) {
            update(curridx * 2, segTreeMin, blow, bmid, pos, nval);
        }
        else {
            update(curridx * 2 + 1, segTreeMin, bmid + 1, bhigh, pos, nval);
        }
        segTreeMin[curridx] = min(segTreeMin[curridx * 2], segTreeMin[curridx * 2 + 1]);
    }
}

int segmin(int curridx, vector<int>& segTreeMin, int blow, int bhigh, int qlow, int qhigh) {
    if (qlow > qhigh) {
        return INT_MAX;
    }
    if (qlow == blow && qhigh == bhigh) {
        return segTreeMin[curridx];
    }
    int bmid = (blow + bhigh) / 2;
    return min(
        segmin(curridx * 2, segTreeMin, blow, bmid, qlow, min(qhigh, bmid)),
        segmin(curridx * 2 + 1, segTreeMin, bmid + 1, bhigh, max(qlow, bmid + 1), qhigh));
}

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    int nbValues, nbQueries;
    cin >> nbValues >> nbQueries;

    vector<int> values(nbValues);

    for (int i = 0; i < nbValues; i++) {
        cin >> values[i];
    }

    vector<int> segTreeMin(4 * nbValues);
    vector<int> res;

    build(values, segTreeMin, 1, 0, nbValues - 1);

    for (int i = 0; i < nbQueries; i++) {
        int queryType, op1, op2;
        cin >> queryType >> op1 >> op2;
        if (queryType == 1) {
            update(1, segTreeMin, 0, nbValues - 1, op1-1, op2);
        }
        else {
            res.push_back(segmin(1, segTreeMin, 0, nbValues - 1, op1-1, op2-1));
        }
    }

    for (auto const& c : res) {
        cout << c << ' ';
    }
    cout << endl;
}

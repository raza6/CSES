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

    int len;
    int weight;
    cin >> len >> weight;
    
    //check limits
    string res = "";
    bool imp = false;
    char alphabet[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    if ((float)weight / 26.0f > (float)len) {
        res = "impossible";
        imp = true;
    }
    else if (len > weight) {
        res = "impossible";
        imp = true;
    }

    if (!imp) {
        int remWeight = weight;
        int remLen = len;
        while (remWeight >= 26 && remWeight-26 > remLen) {
            res += "z";
            remWeight -= 26;
            remLen--;
        }
        while (remLen > 1) {
            res += "a";
            remWeight -= 1;
            remLen--;
        }

        res += alphabet[remWeight-1];
    }


    cout << res << endl;
}

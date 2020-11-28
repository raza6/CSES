#include <iostream>
#include <string> 
using namespace std;
typedef long long ll;

int main()
{
    // HACKERMAN
    ios::sync_with_stdio(false);
    cin.tie(0);

    //Read inputs

    int value;
    cin >> value;

    string res = "NO SOLUTION";

    if (value > 3) {
        res = "";
        for (int i = 2; i <= value; i += 2) {
            res += to_string(i) + " ";
        }
        for (int i = 1; i <= value; i += 2) {
            res += to_string(i) + " ";
        }
    }
    else if (value == 1) {
        res = "1";
    }
    
    cout << res << endl;
}

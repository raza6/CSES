#include <iostream>
using namespace std;

int main()
{
    int fact;
    cin >> fact;

    int fivePowers[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};

    int totalZeroes = 0;
    for (int fivep : fivePowers) {
        if (fact < fivep) {
            break;
        }
        totalZeroes += fact / fivep;
    }
    cout << totalZeroes << endl;
}



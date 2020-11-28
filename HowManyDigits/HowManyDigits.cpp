#include <iostream>
#include <math.h>
#include <string>
using namespace std;

# define M_PI 3.14159265358979323846

int main()
{

    int fact;
    while (cin >> fact) {
        if (fact > 1) {
            //double res = (fact * log10(fact / exp(1)) + log10(2 * M_PI * fact)) / 2.0;
            double res = ((fact + 0.5) * log(fact) - fact + 0.5 * log(2 * M_PI)) / log(10);
            string ans = to_string((int)floor(res) + 1);
            cout << ans << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
}

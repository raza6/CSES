#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int lengthNb;
    cin >> lengthNb;

	ll previousNb = 0;
	ll turnsNb = 0;
	for (int i = 0; i < lengthNb; i++) {
		ll currNb;
		cin >> currNb;
		if (currNb < previousNb) {
			turnsNb += previousNb - currNb;
		}
		else {
			previousNb = currNb;
		}
	}

	cout << turnsNb << endl;
}

/*Array version*/

#include <iostream>
using namespace std;

#define MAXN 200000

int main()
{
	int lengthNb;
	cin >> lengthNb;

	int numbers[MAXN];
	fill_n(numbers, MAXN, 0);

	for (int i = 0; i < lengthNb-1; i++) {
		int currNb;
		cin >> currNb;
		numbers[currNb-1] = 1;
	}
	for (int i = 0; i < MAXN; i++) {
		if (numbers[i] == 0) {
			cout << i + 1 << endl;
			break;
		}
	}
}

/*Sum version*/

//#include <iostream>
//using namespace std;
//
//typedef long long ll;
//
//int main()
//{
//    ll lengthNb;
//    cin >> lengthNb;
//
//    ll currTotal = 0;
//
//    for (int i = 0; i < lengthNb-1; i++) {
//        int currNb;
//        cin >> currNb;
//        currTotal += currNb;
//    }
//
//    ll totalExpected = (lengthNb*(lengthNb+1))/2;
//    cout << totalExpected - currTotal << endl;
//}

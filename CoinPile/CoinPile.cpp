#include <iostream>
#include <vector>
#include <stdlib.h> 
using namespace std;

#define MAXN 200000

bool testSame(int left, int right) {
	return left == right && left % 3 == 0 && right % 3 == 0;
}

int main()
{
	int pileNb;
	cin >> pileNb;

	vector<string> res;
	for (int i = 0; i < pileNb; i++) {
		int left, right;
		cin >> left >> right;
		if (testSame(left, right)) {
			res.push_back("YES");
		}
		else {
			int diff = abs(left - right);
			if (left - diff < 0 || right - diff < 0) {
				res.push_back("NO");
			}
			else {
				if (left < right) {
					left = left - diff;
					right = right - 2 * diff;
				}
				else {
					left = left - 2 * diff;
					right = right - diff;
				}
				//cout << left << " " << right << endl;
				if (testSame(left, right)) {
					res.push_back("YES");
				}
				else {
					res.push_back("NO");
				}
			}
		}
	}

	for (string s : res) {
		cout << s << endl;
	}
}
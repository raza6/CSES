#include <iostream>
using namespace std;

int main()
{
    string adn;
    cin >> adn;

    char currChar = 'h';
    int repet = 1;
    int bestRepet = -1;
    for (char& nitrogenousBase : adn) {
        if (nitrogenousBase == currChar) {
            repet++;
        }
        else {
            currChar = nitrogenousBase;
            bestRepet = repet > bestRepet ? repet : bestRepet;
            repet = 1;
        }
    }
    bestRepet = repet > bestRepet ? repet : bestRepet;
    cout << bestRepet << endl;
}

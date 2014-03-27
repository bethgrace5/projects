#include <iostream>
using namespace std;

int main() {
    string input;
    cout <<"Enter strings to be analyzed. Enter empty string when done.\n";
    do {
        getline(cin, input);
        int mismatchLocation;
        if (input.length() > 1)
        if ((mismatchLocation = matchGroupingSymbols(input)) ==-1) {
            cout << "Symbols Match" << endl;
        }
        else {
            cout << "Symbols do not match:\n" << input << endl;
            for (int i = 0; i < mismatchLocation; ++i)
            cout << " ";
            cout << "^" << endl;
        }
    } 
    while (input.length() > 1);

    return 0;
}

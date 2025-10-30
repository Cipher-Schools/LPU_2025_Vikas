#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num > 0)
        cout << "Positive";
    else if (num < 0)
        cout << "Negative";
    else
        cout << "Zero";

    cout << "\nNumbers from 1 to 5: ";
    for (int i = 1; i <= 5; i++)
        cout << i << " ";

    return 0;
}

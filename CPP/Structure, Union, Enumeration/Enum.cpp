#include <iostream>
using namespace std;

enum Week {Mon, Tue, Wed, Thu, Fri, Sat, Sun};

int main() {
    Week today = Fri;
    cout << "Day number: " << today << endl;
    return 0;
}

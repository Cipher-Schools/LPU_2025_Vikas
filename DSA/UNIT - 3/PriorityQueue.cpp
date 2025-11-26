#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);

    cout << pq.top(); // 50 (highest)
}


//Min-heap
//priority_queue<int, vector<int>, greater<int>> pq;

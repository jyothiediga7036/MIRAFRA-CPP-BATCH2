#include <iostream>
#include <queue>  // For std::priority_queue
#include<vector>
using namespace std;
int main() 
{
    // Create a max-heap priority queue of integers
    //std::priority_queue<int,vector<int>,greater<int>> pq;  //min_heap
    std::priority_queue<int> pq;  //max_heap

    // Push elements onto the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Display and pop elements from the priority queue
    while (!pq.empty()) {
        std::cout << "Top element: " << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}

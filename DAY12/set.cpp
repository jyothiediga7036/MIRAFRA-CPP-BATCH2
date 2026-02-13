#include <iostream>
#include <set>
using namespace std;
int main() {
    std::set<int> mySet = {5, 2, 8, 1, 3};

    // Insert elements
    mySet.insert(7);
    mySet.insert(2); // Won't be inserted since 2 is already present

    // Display elements (automatically sorted)
    std::cout << "Set elements: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    if (mySet.find(3) != mySet.end()) {
        std::cout << "3 is present in the set.\n";
    }

    // Erase an element
    mySet.erase(2);

    // Display updated set
    std::cout << "After erasing 2: ";
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
	set<int>k={3,5};
	for(auto x:k)
	{
	if(mySet.contains(x))
	cout<<mySet<<"found "<<x<<endl;
	else
	cout<<mySet<<"not found"<<x<<endl;
	}  
	  
    return 0;
}


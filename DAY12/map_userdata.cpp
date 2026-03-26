#include <iostream>
#include <map>
#include <string>
using namespace std;
struct decencomparator
{
bool operator()(const string &left,const string &right)const
{
return left>right;
}
};
int main() {
    // Create a map with string keys and integer values
    std::map<std::string, int,decencomparator> studentScores;

    // Insert key-value pairs
     studentScores["Bob"] = 92;
    studentScores["Alice"] = 85;
   
    studentScores["Charlie"] = 78;

    // Alternatively, you can use insert method with std::pair
    studentScores.insert(std::make_pair("David", 90));
    studentScores.emplace("Deen",58);
    studentScores.emplace("Deen",80);//dublicates will be ignored
    studentScores["Charlie"] = 100;
    // Accessing elements
    std::cout << "Alice's score: " << studentScores["Alice"] << std::endl;

    // Iterate over the map (elements are sorted by key)
    std::cout << "\nStudent Scores:\n";
    for (const auto& entry : studentScores) {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }
}


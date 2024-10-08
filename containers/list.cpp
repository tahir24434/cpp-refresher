#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

template<typename T>
void printList(const std::list<T>& lst, const std::string& label) {
    std::cout << label << ": ";
    for (const auto& item : lst) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Function to demonstrate different initialization methods
void demonstrateInitialization() {
    std::cout << "--- List Initialization Methods ---\n";

    // 1. Default constructor
    std::list<int> list1;
    printList(list1, "Default constructor");

    // 2. Fill constructor
    std::list<int> list2(5, 10);
    printList(list2, "Fill constructor");

    // 3. Range constructor
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<int> list3(vec.begin(), vec.end());
    printList(list3, "Range constructor");

    // 4. Copy constructor
    std::list<int> list4(list3);
    printList(list4, "Copy constructor");

    // 5. Initializer list
    std::list<int> list5 = {10, 20, 30, 40, 50};
    printList(list5, "Initializer list");

    // 6. Move constructor
    std::list<int> list6(std::move(list5));
    printList(list6, "Move constructor");
    printList(list5, "Original list after move");

    std::cout << std::endl;
}

// Function to demonstrate different list operations
void demonstrateOperations() {
    std::cout << "--- List Operations ---\n";

    std::list<int> myList = {3, 4, 5};
    printList(myList, "Original list");

    // 1. Add elements
    myList.push_back(6);
    printList(myList, "After push_back");
    myList.push_front(2);
    printList(myList, "After push_front");

    // 2. Remove elements
    myList.pop_back();
    printList(myList, "After pop_back");
    myList.pop_front();
    printList(myList, "After pop_front");

    // 3. Insert element
    auto it = std::find(myList.begin(), myList.end(), 4);
    myList.insert(it, 8);
    printList(myList, "After inserting 8 before 4");

    // 4. Erase element
    myList.erase(std::find(myList.begin(), myList.end(), 8));
    printList(myList, "After erasing first 4");

    // 5. Sort and reverse
    myList.sort();
    printList(myList, "After sorting");
    myList.reverse();
    printList(myList, "After reversing");

    // 6. Remove and remove_if
    myList.remove(5);
    printList(myList, "After removing all 5s");
    myList.remove_if([](int n) { return n % 2 == 0; });
    printList(myList, "After removing even numbers");

    // 7. Splice
    std::list<int> otherList = {10, 20, 3};
    myList.splice(myList.begin(), otherList);
    printList(myList, "After splicing otherList at the beginning");

    // 8. Unique
    myList.unique();
    printList(myList, "After removing consecutive duplicates");

    // 9. Merge
    std::list<int> list2 = {2, 4, 6};
    myList.merge(list2);
    printList(myList, "After merging two lists");

    // 10. Using algorithms
    std::transform(myList.begin(), myList.end(), myList.begin(), [](int n) { return n * 2; });
    printList(myList, "After doubling each element");

    int sum = std::accumulate(myList.begin(), myList.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;
}

// New function to demonstrate accessing list elements
void demonstrateAccess() {
    std::cout << "--- Accessing List Elements ---\n";

    std::list<int> myList = {10, 20, 30, 40, 50};
    printList(myList, "Original list");

    // Range-based for loop.
    for (int x : myList) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Iterator based for loop
    //   An iterator is a generalized pointer-like object that allows traversing
    //   elements of the container. 
    //   *it: Dereference the iterator. Access the element that iterator points to. 
    for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using std::for_each with a Lambda
    //   std::for_each(first, last, func);
    //   first: Iterator pointing to the beginning(inclusive) of the range 
    //   last:  Iterator pointing to the end(exlusive) of the range
    //   func: A callable (function, function object, or lambda) that is applied to each element
    //         A lambda expression is an unnamed function that can be defined inline.
    //         [](int i): [] capture clause. Since it's empty, it does not capture any variable.
    //                    (int i) is parameter list. 
    for_each(myList.begin(), myList.end(), 
            [](int x) {cout << x << " ";}
    );
    std::cout << std::endl;

    // 1. Accessing front and back elements
    std::cout << "Front element: " << myList.front() << std::endl;
    std::cout << "Back element: " << myList.back() << std::endl;

    // 2. Using iterators
    std::cout << "First element using iterator: " << *myList.begin() << std::endl;
    std::cout << "Last element using iterator: " << *std::prev(myList.end()) << std::endl;

    // 3. Accessing nth element
    auto it = myList.begin();
    std::advance(it, 2);  // Move to the 3rd element (index 2)
    std::cout << "3rd element: " << *it << std::endl;

    // 5. Reverse iteration
    std::cout << "Reverse iteration: ";
    for (auto rit = myList.rbegin(); rit != myList.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // 6. Finding an element
    auto findIt = std::find(myList.begin(), myList.end(), 30);
    if (findIt != myList.end()) {
        std::cout << "Found 30 at position: " 
                  << std::distance(myList.begin(), findIt) << std::endl;
    }

    // 7. Accessing with bounds checking
    try {
        // This would throw an out_of_range exception if the element doesn't exist
        // std::list doesn't have direct index access, so we'll use std::advance
        auto safeIt = myList.begin();
        std::advance(safeIt, 2);  // Access 3rd element safely
        std::cout << "Safely accessed 3rd element: " << *safeIt << std::endl;

        std::advance(safeIt, 10);  // This will go beyond the end of the list
        std::cout << "This line won't be reached" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

int main() {
    demonstrateInitialization();
    demonstrateOperations();
    demonstrateAccess();  // Add this line to call the new function
    return 0;
}
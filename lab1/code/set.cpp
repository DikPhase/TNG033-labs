#include "set.hpp"

#include <algorithm>  //std::swap

/*
* std::size_t is defined in the C++ standard library
* std::size_t is an unsigned integer type that can store the maximum size of any possible object
* sizes are non-negative integers -- i.e. unsigned integer type
*/

// Initialize the counter of the total number of existing nodes
std::size_t Set::Node::count_nodes = 0;

// Used only for debug purposes
// Return number of existing nodes
std::size_t Set::get_count_nodes() {
    return Set::Node::count_nodes;
}

/* ************************************ */

// Default constructor
Set::Set() : head{new Node{}}, counter{0} {  // create the dummy node
}
// Constructor for creating a singleton {x}
Set::Set(int x) : Set() {
    // ADD CODE. DONE
    insert(head, x);
}
// Constructor: create a set with elements
// elements is not sorted and values in it may not be unique
Set::Set(const std::vector<int>& elements) : Set() {
    /*
    * Sorting a vector cannot used here
    * std::sort and std::unique cannot be used
    */
    // ADD CODE. DONE
    for (int element : elements) {  // Go through every element in the vector
        if (!member(element)) { // Check if the element already exists
            Node* current = head;
            while (current->next != nullptr && current->next->value < element) {
                current = current->next;
            }
            insert(current, element);
        }
    }
}
// copy constructor
Set::Set(const Set& rhs) : Set() {
    // ADD CODE. DONE
    Node* rhsCurrent = rhs.head->next; // Make rhsCurrent point to the first Node to be copied (Not dummy)
    Node* current = head;   // New Nodes, make current point to the first Node (dummy)
    while (rhsCurrent != nullptr) { // Loop through the original list while it isn't a nullptr
        insert(current, rhsCurrent->value);   // Create a new Node that holds the value from the original Node
        current = current->next;  // Update so newNode is the last Node so far
        rhsCurrent = rhsCurrent->next; // Update so we move along the original set
    }
    counter = rhs.counter;
}
// Assignment operator: use copy-and-swap idiom
Set& Set::operator=(Set rhs) {
    // ADD CODE. DONE 
    std::swap(head, rhs.head); // Copy-and-swap idiom.
    std::swap(counter, rhs.counter);

    return *this;
}
// Destructor: deallocate all nodes
Set::~Set() {
    // ADD CODE. DONE
    Node* current = head; // Make the current Node the first Node in the list
    while (head->next  != nullptr) { // While the head-pointer isn't a nullptr
        remove(head);
    }
    delete head;
}
// Return number of elements in the set
std::size_t Set::cardinality() const {
    // ADD CODE. DONE
    return counter; // Returns the amount of Nodes currently in the set.
}
// Test if set is empty
bool Set::empty() const {
    // ADD CODE. DONE
    if (counter == 0) { // If the Node counter is 0, then set is empty
        return true;  // delete, if needed
    }
    else { 
        return false;
    }
}
// Test if x is an element of the set
bool Set::member(int x) const {
    // ADD CODE. DONE
    Node* current = head->next; // Make current a pointer to the Node after the dummmy Node
    while (current != nullptr) { // loop while current isn't a nullptr
        if (current->value == x) { // Check if the value of the current Node is the same as the input value
            return true; // If true then return true
        }
        current = current->next; // Travel along the list/set
    }
    return false;  // delete, if needed
}
// Return true, if *this is a subset of Set b
// Otherwise, false is returned
bool Set::is_subset(const Set& b) const {
    // ADD CODE. DONE
    Node* current = head->next; // Make current a pointer to the first Node (not dummy)
    while (current != nullptr) {    // Loop through entire set until last Node
        if (!b.member(current->value)) {    // If the set b doesn't have a member that matches the value of the current node, return false
            return false;
        }
        current = current->next;    // Travel along the set
    }
    return true;  // if all elements are members of set b, return true
}
// Return a new Set representing the union of Sets *this and b
// Repeated values are not allowed
// Implement an algorithm similar to the one in exercise 3/Set 1, but don't use vectors
Set Set::set_union(const Set& b) const {
    // ADD CODE. DONE
    Set result;
    Node* currentA = head->next;
    Node* currentB = b.head->next;
    Node* result_end = result.head;
                                    
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA->value < currentB->value) {
            result.insert(result_end, currentA->value);
            currentA = currentA->next;
            result_end = result_end->next;
        }
        else if(currentA->value > currentB->value) {
            result.insert(result_end, currentB->value);
            currentB = currentB->next;
            result_end = result_end->next;
        }
        else {
            result.insert(result_end, currentB->value);
            currentB = currentB->next;
            currentA = currentA->next;
            result_end = result_end->next;
        }
        
    }
    while(currentA != nullptr) {
        result.insert(result_end, currentA->value);
        currentA = currentA->next;
        result_end = result_end->next;
    }
    while (currentB != nullptr) {
        result.insert(result_end, currentB->value);
        currentB = currentB->next;
        result_end = result_end->next;
    }
    
    return result;
}
// Return a new Set representing the intersection of Sets *this and b
Set Set::set_intersection(const Set& b) const {
    // ADD CODE
    Set result;
    Node* currentA = head->next;
    Node* currentB = b.head->next;
    Node* result_end = result.head;

    while (currentA != nullptr && currentB != nullptr) {
        if (currentA->value < currentB->value) {
            currentA = currentA->next;
        }
        else if (currentA->value > currentB->value) {
            currentB = currentB->next;
        }
        else {
            result.insert(result_end, currentA->value);
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }
    return result;;  // delete, if needed
}
// Return a new Set representing the difference between Set *this and Set b
Set Set::set_difference(const Set& b) const {
    // ADD CODE
    Set result;

    Node* currentA = head->next;
    Node* currentB = b.head->next;
    Node* result_end = result.head;

    while (currentA != nullptr && currentB != nullptr) {
        if (currentA->value < currentB->value) {
            result.insert(result_end, currentA->value);
            currentA = currentA->next;
            result_end = result_end->next;
        }
        else if (currentA->value > currentB->value) {
            currentB = currentB->next;
        }
        else {
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }
    while (currentA != nullptr) {
        result.insert(result_end, currentA->value);
        currentA = currentA->next;
        result_end = result_end->next;
    }
    return result;  // delete, if needed
}
std::ostream& operator<<(std::ostream& os, const Set& rhs) {
    if (rhs.empty()) {
        os << "Set is empty!";
    } else {
        Set::Node* ptr = rhs.head->next;
        os << "{ ";

        while (ptr != nullptr) {
            os << ptr->value << " ";
            ptr = ptr->next;
        }
        os << "}";
    }
    return os;
}

/********** Private member functions ************/
void Set::insert(Node* p, int value) {
    Node* newNode = new Node(value, nullptr);
    newNode->next = p->next;
    p->next = newNode;
    ++counter;
}
void Set::remove(Node* current) {
    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    --counter;
}
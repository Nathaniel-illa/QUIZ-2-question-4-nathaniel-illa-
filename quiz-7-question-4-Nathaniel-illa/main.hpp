#ifndef MAIN_HPP
#define MAIN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

// Function declarations
void makevector(vector<int> &, int);
void printvector(vector<int>);
void sortEvenNumber(vector<int> &);
int insertEvenNumber(vector<int> &, int);
int deleteEvenNumber(vector<int> &, int);

// Function implementations
void sortEvenNumber(vector<int> &vec) {
    // Collect even numbers and their positions
    vector<int> evenNumbers;
    vector<int> positions;

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] % 2 == 0) {
            evenNumbers.push_back(vec[i]);
            positions.push_back(i);
        }
    }

    // In-place sorting of even numbers
    for (int i = 0; i < evenNumbers.size(); ++i) {
        for (int j = i + 1; j < evenNumbers.size(); ++j) {
            if (evenNumbers[j] < evenNumbers[i]) {
                swap(evenNumbers[i], evenNumbers[j]);
            }
        }
    }

    // Place sorted even numbers back into the original vector
    for (int i = 0; i < evenNumbers.size(); ++i) {
        vec[positions[i]] = evenNumbers[i];
    }
}

int insertEvenNumber(vector<int> &vec, int evenvalue) {
    // Find the first position of an even number greater than the value to be inserted
    int pos = vec.size();
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] % 2 == 0 && vec[i] > evenvalue) {
            pos = i;
            break;
        }
    }

    // Insert the new even number in the found position
    vec.push_back(0); // Add a dummy element to make space
    for (int i = vec.size() - 1; i > pos; --i) {
        vec[i] = vec[i - 1];
    }
    vec[pos] = evenvalue;

    return pos;
}

int deleteEvenNumber(vector<int> &vec, int evenvalue) {
    int count = 0;
    for (auto it = vec.begin(); it != vec.end(); ) {
        if (*it == evenvalue) {
            it = vec.erase(it);
            ++count;
        } else {
            ++it;
        }
    }
    return count;
}

void makevector(vector<int> &vec, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++)
        vec.push_back(rand() % 20);
}

void printvector(vector<int> vec) {
    for (int v : vec)
        cout << v << "\t";
    cout << endl;
}

// Main function
int main() {
    int idx;

    // Test 1
    vector<int> numbers1 = {6, 7, 0, 4, 5, 2, 10, 1, 8, 2};
    cout << "The original vector " << endl;
    printvector(numbers1);
    sortEvenNumber(numbers1);
    printvector(numbers1);
    // Insert 2
    idx = insertEvenNumber(numbers1, 2);
    cout << "Inserted index " << idx << endl;
    printvector(numbers1);

    // Insert 12
    idx = insertEvenNumber(numbers1, 12);
    cout << "Inserted index " << idx << endl;
    printvector(numbers1);

    // Delete 2
    idx = deleteEvenNumber(numbers1, 2);
    cout << "Deleted items " << idx << endl;
    printvector(numbers1);

    // Delete 12
    idx = deleteEvenNumber(numbers1, 12);
    cout << "Deleted items " << idx << endl;
    printvector(numbers1);

    // Test 2 for the vector with Random Values
    vector<int> numbers2;
    makevector(numbers2, 20);
    cout << "The original vector " << endl;
    printvector(numbers2);
    sortEvenNumber(numbers2);
    printvector(numbers2);

    // Insert 22
    idx = insertEvenNumber(numbers2, 22);
    printvector(numbers2);

    return 0;
}

#endif // MAIN_HPP
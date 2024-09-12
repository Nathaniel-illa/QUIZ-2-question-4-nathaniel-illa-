#include "main.hpp"

int main()
{
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

	/***************************************************
	 * Test 2 for the vector with Random Values
	 ***************************************************/
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
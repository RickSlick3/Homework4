#include "table.h"
#include "Treey.h"
#include <random>

using namespace std;


int main(void) {
	table tabley = table(500);
	Treey<int, int>* treey = new Treey<int, int>();
	int randMax = 100; // the highest rand value that can be input into the data structures
	int tableC = 0; // comparison count for tabley

	// making an array of 100 random, unique numbers
	int numArr[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		int num = rand() % randMax + 1;
		if (std::find(std::begin(numArr), std::end(numArr), num) == std::end(numArr)) {
			numArr[i] = num;
		}
		else {
			i--;
		}
	}

	std::cout << "Filling the structures with values: \n\n";

	// adding the first 50 elements to the structures
	for (int i = 0; i <= 49; i++) {
		tableC += tabley.insert(numArr[i]);
		treey->insert(numArr[i], numArr[i]);
	}	

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treey->counter << " comparisons.\n\n";
	std::cout << "Removing multiples of 7 from the structures: \n\n";

	// removing multiples of 7
	int i = 0;
	while(i <= randMax) {
		tableC += tabley.remove(i);
		treey->remove(i);
		i += 7;
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treey->counter << " comparisons.\n\n";
	std::cout << "Filling the structures with values again: \n\n";

	// adding the other 50 elements
	for (int i = 50; i <= 99; i++) {
		tableC += tabley.insert(numArr[i]);
		treey->insert(numArr[i], numArr[i]);
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treey->counter << " comparisons.\n\n";
	std::cout << "Removing multiples of 9 from the structures: \n\n";

	// finding multiples of 9
	i = 0;
	while (i <= randMax) {
		if (i%7 != 0) {
			tableC += tabley.find(i);
			treey->find(i);
		}
		i += 9;
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treey->counter << " comparisons.\n\n";

	tabley.printTable();

}
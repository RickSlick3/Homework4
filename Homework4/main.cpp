#include "table.h"
#include "Treey.h"
#include <random>

using namespace std;


int main(void) {
	table tabley;
	Treey<int, int>* treey = new Treey<int, int>();
	int randMax = 100; // the highest value that can be input into the data structures
	int tableC = 0; // comparison count for tabley
	int treeC = 0; // comparison count for treey

	int numArr[100] = { 0 };
	for (int i = 0; i < 100; i++) {
		int num = rand() % randMax + 1;
		if (std::find(std::begin(numArr), std::end(numArr), num) == std::end(numArr)) {
			numArr[i] = num;
		}
		else {
			num--;
		}
	}

	std::cout << "Filling the structures with values: \n\n";

	for (int i = 0; i <= 49; i++) {
		tableC += tabley.insert(numArr[i]);
		// need to implement comparison count in Treey
		treey->insert(numArr[i], numArr[i]);
	}	

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treeC << " comparisons.\n\n";
	std::cout << "Removing multiples of 7 from the structures: \n\n";

	int i = 7;
	while(i <= randMax) {
		tableC += tabley.remove(i);
		// need to implement comparison count in Treey
		treey->remove(i);
		i += 7;
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treeC << " comparisons.\n\n";
	std::cout << "Filling the structures with values again: \n\n";

	for (int i = 50; i <= 99; i++) {
		tableC += tabley.insert(numArr[i]);
		// need to implement comparison count in Treey
		treey->insert(numArr[i], numArr[i]);
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treeC << " comparisons.\n\n";
	std::cout << "Removing multiples of 9 from the structures: \n\n";

	i = 9;
	while (i <= randMax) {
		tableC += tabley.find(i);
		// need to implement comparison count in Treey
		treey->find(i);
		i += 9;
	}

	std::cout << "Tabley has made " << tableC << " comparisons.\n";
	std::cout << "Treey has made " << treeC << " comparisons.\n\n";

}
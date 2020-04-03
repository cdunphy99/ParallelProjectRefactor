#include <string>
#include <fstream>
#include <iostream>
#include "TreeRow.h"

using namespace std;

int main() {
	int wordLen, numOfPossibleValues;
	string wordCheck, possibleValues;


	cout << "Enter the Password: ";
	cin >> wordCheck; //crashes after this
	wordLen = wordCheck.length();

	//open file
	ifstream inFile;
	inFile.open("C:\\Users\\Michael Foley\\CProgramCode\\passwordGuessor\\possibleValuesList1.txt");
	if (!inFile) {
		printf("Error opening file.\n");
		return 0;
	}
	//stores number of values
	inFile >> numOfPossibleValues;
	getline(inFile, possibleValues);

	cout << numOfPossibleValues;
	inFile.close();



	for (int i = 0; i < numOfPossibleValues; i++)
	{
		TreeRow* nextRow = nullptr;
		//create row 1 here
		TreeRow rowStart = TreeRow(possibleValues[i], &possibleValues, &numOfPossibleValues);
		//
		for (int j = 0; j < wordLen - 2; j++)
		{
			//create next row 
			if (j == 0) {
				nextRow = &TreeRow(rowStart); // check if doesn't work
			}
			else
			{
				nextRow = &TreeRow(*nextRow); // check if doesn't work
			}
		}

		//test row
		if (nextRow->testPermutation(wordCheck)) {
			//if guessed word correct
			goto endProg;
		}
	}
	//for loop for each letter



	//end for

endProg:
	cout << "Word Found";

}
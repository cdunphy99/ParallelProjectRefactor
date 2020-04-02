// ParallelProjectRefactor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define WORD_LIMIT 5
int found = 0;

int checkWord(string* wordA, string* wordB, int Size) {
	int i;
	for (i = 0; i < Size; i++) {
		if (*wordA != *wordB) {
			return 0;
		}
	}
	return 1;
}

void treeLevelGenerator(int Level, string wordCheck, int wSize, string A, int aSize, string* treeLevel, int treeLevelSize);

int main(int argc, char* argv[]) {
	string targetWord, posibleValList;
	int wSize, numOfPosibleValList;

	//sore pointer to word
	targetWord = argv[1];

	//counts size of input word
	wSize = atoi(argv[2]);
	printf("--------- %d ----------", wSize);
	//chack requirments
	if (wSize > WORD_LIMIT) {
		exit(0);
	}

	//Print words pc is finding
	cout << targetWord;

	//open file
	ifstream inFile;
	//inFile.open("C:\\Users\\Michael Foley\\CProgramCode\\passwordGuessor\\possibleValuesList1.txt");
	inFile.open("");
	if (!inFile) {
		printf("Error opening file.\n");
		return 0;
	}
	//stores number of values
	getline(inFile, numOfPosibleValList);
	getline(inFile, posibleValList);
	inFile.close();

	//everything works above
	string* startingTree = new string[numOfPosibleValList];
	for (int j = 0; j < numOfPosibleValList; j++) {
		startingTree[j] = posibleValList[j];
	}
	treeLevelGenerator(wSize, targetWord, wSize, posibleValList, numOfPosibleValList, startingTree, numOfPosibleValList);

	return 0;
}

void treeLevelGenerator(int Level, string wordCheck, int wSize, string A, int aSize, string treeLevel[], int treeLevelSize) {
	if (found == 0) {
		int i, j;
		if (Level == 1) {
			//bottom level
			for (i = 0; i < treeLevelSize; i++) {
				if (1 == checkWord(&wordCheck, &treeLevel[i], wSize - Level + 1)) {
					printf("WORD FOUND!");
					found = 1;
				}
			}
		}
		else {
			//char** newTreeLevel = malloc(sizeof(treeLevel) * aSize + 1);
			string* newTreeLevel = new string[sizeof(treeLevel) * aSize + 1];
			for (i = 0; i < treeLevelSize; i++) {
				for (j = 0; j < aSize; j++) {
					char temp = A[j];
					string temp2 = treeLevel[i];

					newTreeLevel[i][j] = temp + temp2;
				}
			}
			delete (treeLevel);
			treeLevelGenerator(Level - 1, wordCheck, wSize, A, aSize, newTreeLevel, treeLevelSize * aSize);
		}
	}
	else {
		return;
	}
}
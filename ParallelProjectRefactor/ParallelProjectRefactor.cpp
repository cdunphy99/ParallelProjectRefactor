// ParallelProjectRefactor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define WORD_LIMIT 5
int found = 0;

string* newStringCreator(string* startingString, int length, char addingChar) {
	int i;
	string* newString = new string[length + 1];
	for (i = 0; i < length; i++) {
		newString[i] = startingString[i];
	}
	newString[length] = addingChar;
	//free(startingString);
	return newString;
}

int checkWord(string* wordA, string* wordB, int Size) { // this is broken
	int i;
	for (i = 0; i < Size; i++) {
		if (*wordA != *wordB) {
			return 0;
		}
	}
	return 1;
}

void treeLevelGenerator(int Level, string* wordCheck, int wSize, char* A, int aSize, string** treeLevel, int treeLevelSize);

int main(int argc, char* argv[]) {
	string* targetWord = new string;
	int wSize, numOfPosibleValList;

	//sore pointer to word
	*targetWord = argv[1];

	//counts size of input word
	wSize = atoi(argv[2]);
	printf("--------- %d ----------", wSize);
	//chack requirments
	if (wSize > WORD_LIMIT) {
		exit(0);
	}

	//Print words pc is finding
	cout << *targetWord;

	//open file
	ifstream inFile;
	inFile.open("F:\\Code\\ParallelProjectRefactor\\Debug\\possibleValuesList1.txt");
	if (!inFile) {
		printf("Error opening file.\n");
		return 0;
	}
	//stores number of values
	int temp;
	inFile >> temp;
	cout << temp;
	numOfPosibleValList = temp;

	//stores values
	char* posibleValList = new char[numOfPosibleValList];
	int i = 0;
	/*while(i < 26) {
		char temp = (char)fgetc(file);
		if (temp != '\n') {
			printf("%c\n", temp);
			posibleValList[i] = (char)temp;
			i++;
		}
	}*/
	char inTemp;
	for (i = 0; inFile >> inTemp; i++) {
		posibleValList[i] = inTemp;
	}

	//everything works above
	string** startingTree = new string * [numOfPosibleValList];
	for (int i = 0; i < numOfPosibleValList; i++) {
		cout << "FUCK";
		startingTree[i] = new string[numOfPosibleValList];
	}
	for (int j = 0; j < numOfPosibleValList; j++) {
		*startingTree[j] = posibleValList[j];
	}
	printf(" --%d-- \n", wSize);
	treeLevelGenerator(wSize, targetWord, wSize, posibleValList, numOfPosibleValList, startingTree, numOfPosibleValList);

	return 0;
}

void treeLevelGenerator(int Level, string* wordCheck, int wSize, char* A, int aSize, string** treeLevel, int treeLevelSize) {
	
	if (found == 0) {
		int i, j;
		if (Level == 1) {
			//bottom level
			for (i = 0; i < treeLevelSize; i++) {
				if (1 == checkWord(wordCheck, treeLevel[i], wSize - Level + 1)) {
					printf("WORD FOUND!");
					found = 1;
				}
			}
		}
		else {
			//char** newTreeLevel = malloc(sizeof(treeLevel) * aSize + 1);
			string** newTreeLevel = new string * [sizeof(treeLevel) * aSize + 1];
			for (i = 0; i < treeLevelSize; i++) {
				for (j = 0; j < aSize; j++) {
					newTreeLevel[i][j] = newStringCreator(treeLevel[i], (wSize - Level + 1), A[j]);
				}
			}
			delete treeLevel;
			treeLevelGenerator(Level - 1, wordCheck, wSize, A, aSize, newTreeLevel, treeLevelSize * aSize);
		}
	}
	else {
		return;
	}
}
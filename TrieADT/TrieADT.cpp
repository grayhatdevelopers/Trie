// TrieADT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Trie.h"
using namespace std;
int main()
{

    std::cout << "Hello World!\n";
	TRIE dictionary;

	try {
		dictionary.CreateDictionary("dictionary.txt");
		cout << "Created the dictionary!" << endl;
	}
	catch (invalid_argument& e) {
		cout << "Caught an error! " << e.what() << endl;
	}


	cout << endl<<endl;
	string word;
	do {
		cout << endl;
		cout << "Search a word: ";
		getline(cin, word, '\n');
		system("CLS");
		if (word == "")
			break;
		try {
			if (dictionary.FindWord(word)) {
				cout << endl << endl<<endl;
				cout << "Found " << word << " in the dictionary!" << endl;
			}
			else {
				cout << "Couldn't find " << word << ".";
				auto beginTime = time(NULL);
				Vector <string> possibilities = dictionary.SpellChecker(word, 2);
				auto endTime = time(NULL);
				//cout << "The root is " << dictionary.root << endl;
				if (!possibilities.isEmpty()) {
					cout << " Did you mean ";
					for (int i = 0; i < possibilities.Size(); i++) {
						cout << possibilities[i];
						if (i != possibilities.Size() - 1)
							cout << ", ";
					}
					cout << "?"<<endl;
					cout << "The function took " << beginTime - endTime << "ms to obtain this result." << endl;

				}
				cout << endl;
			}
			cout << "What is the meaning of " << word << "? " << endl;
			cout << " - " << dictionary.FindMeaning(word) << endl;
			cout << "What are the synonyms of " << word << "? " << endl;
			Vector<string> synonyms = dictionary.FindSynonyms(word);
			for (int i = 0; i < synonyms.Size(); i++) {
				cout << i + 1 << ". " << synonyms[i] << endl;
			}
		}
		catch (invalid_argument& e) {
			cout << "Error caught! " << e.what() << endl;
			cout << "Would you like to add some meaning to this word? (Y / N) " << endl;
			char option;
			cin >> option;
			cin.ignore();
			if (option == 'y' or option == 'Y') {
				Word newWord(word);
				dictionary.insertTemporary(word);
				dictionary.saveWord(newWord);
			}
			continue;
		}
		catch (logic_error& e) {
			cout << "Error caught! " << e.what() << endl;
			cout << "Would you like to add "<<word<<" to the dictionary? (Y / N) " << endl;
			char option;
			cin >> option;
			cin.ignore();
			if (option == 'y' or option == 'Y') {
				Word newWord(word);
				dictionary.insertTemporary(word);
				dictionary.saveWord(newWord);
			}
			continue;
		}
		


	} while (word != "");

	{	cout << endl << endl;
	cout << "Now testing SpellChecker..." << endl;
	cout << "Enter a word, but wrongly: ";
	string spellcheck;
	cin.ignore();
	getline(cin, spellcheck, '\n');
	auto beginTime = time(NULL);
	Vector <string> possibilities = dictionary.SpellChecker(spellcheck);
	auto endTime = time(NULL);
	//cout << "The root is " << dictionary.root << endl;
	if (possibilities.isEmpty()) {
		cout << "There were no possibilities!" << endl;
	}
	else {
		cout << "The possibilities are..." << endl;
		for (int i = 0; i < possibilities.Size(); i++)
			cout << possibilities[i] << endl;
	}
	cout << "The function took " << beginTime - endTime << "ms to obtain this result." << endl;

	cout << "Are they correct?" << endl;
	char option;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}
	}


	cout << endl<<endl;
	cout << "Now testing prefixes..." << endl;
	cout << "Search a prefix: ";
	string prefix;
	cin.ignore();
	getline(cin, prefix, '\n');
	Vector <string> prefixes = dictionary.OutputPrefix(prefix);
	cout << "The prefixes are..." << endl;
	for (int i = 0; i < prefixes.Size(); i++)
		cout << prefixes[i] << endl;


	cout << "Are they correct?" << endl;
	char option;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}


	{	cout << endl << endl;
	cout << "Now testing suffixes..." << endl;
	cout << "Search a suffix: ";
	string suffix;
	cin.ignore();
	getline(cin, suffix, '\n');
	Vector <string> suffixes = dictionary.OutputSuffix(suffix);
	//cout << "The root is " << dictionary.root << endl;
	cout << "The suffixes are..." << endl;
	for (int i = 0; i < suffixes.Size(); i++)
		cout << suffixes[i] << endl;


	cout << "Are they correct?" << endl;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}
	}


	cout << endl << endl;
	cout << "Now testing anagrams..." << endl;
	cout << "Search a word: ";
	string anagram;
	cin.ignore();
	getline(cin, anagram, '\n');
	Vector <string> anagramVector;
	//cout << "The root is " << dictionary.root << endl;
	anagramVector = dictionary.OutputAnagrams(anagram);
	cout << "The anagrams are..." << endl;
	for (int i = 0; i < anagramVector.Size(); i++)
		cout << anagramVector[i] << endl;


	cout << "Are they correct?" << endl;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}


	cout << endl << endl;
	cout << "Now testing smaller words..." << endl;
	cout << "Enter a number: ";
	int smaller;
	cin.ignore();
	cin >> smaller;
	Vector <string> smallerVector;
	//cout << "The root is " << dictionary.root << endl;
	smallerVector = dictionary.OutputSmaller(smaller);
	cout << "The smaller words are..." << endl;
	for (int i = 0; i < smallerVector.Size(); i++)
		cout << smallerVector[i] << endl;


	cout << "Are they correct?" << endl;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}

	{	cout << endl << endl;
	cout << "Now testing greater words..." << endl;
	cout << "Enter a number: ";
	int smaller;
	cin.ignore();
	cin >> smaller;
	Vector <string> smallerVector;
	//cout << "The root is " << dictionary.root << endl;
	smallerVector = dictionary.OutputGreater(smaller);
	cout << "The greater words are..." << endl;
	for (int i = 0; i < smallerVector.Size(); i++)
		cout << smallerVector[i] << endl;


	cout << "Are they correct?" << endl;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}
	}


	{	cout << endl << endl;
	cout << "Now testing Complete String..." << endl;
	cout << "Enter a string: ";
	string word;
	cin.ignore();
	getline(cin, word, '\n');
	//cout << "The root is " << dictionary.root << endl;
	Vector <string> completed = dictionary.CompleteString(word);
	cout << "The strings are..." << endl;
	for (int i = 0; i < completed.Size(); i++)
		cout << completed[i] << endl;


	cout << "Are they correct?" << endl;
	cin >> option;
	if (option != 'y' and option != 'Y') {
		exit(1);
	}
	}



	cout << endl<<endl;
	cout << "Outputting in ascending order...";
	prefixes = dictionary.OutputAscending();
	for (int i = 0; i < prefixes.Size(); i++)
		cout << prefixes[i] << endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

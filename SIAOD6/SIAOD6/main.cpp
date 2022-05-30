#include <iostream>
#include <fstream>

using namespace std;

static int simpleSearch(char* txt, string search, int txt_length, int search_length) {
	int counterIterations = 0;
	int counterMove = 0;
	for (int i = 0; i <= txt_length - search_length; i++) {
		counterIterations++;
		counterMove++;
		for (int j = 0; txt[i + j] == search[j]; j++) {
			counterIterations++;
			counterMove += 2;
			if (search_length - j == 1) {
				cout << "Iterations and moves: " << counterIterations + counterMove << endl;
				return i;
			}
		}
	}
	cout << "Iterations and moves: " << counterIterations + counterMove << endl;
	return -1;
}

int main()
{
	ifstream file;
	file.open("C:\\Users\\vladn\\Desktop\\text.txt");
	if (file) {
		file.seekg(0, file.end); 
		int txt_length = file.tellg();
		file.seekg(0, file.beg); 
		char* txt = new char[txt_length];
		file.get(txt, txt_length + 1); 
		cout << txt << endl;
		string search;
		cin >> search;
		int search_length = search.length();
		cout << "Index: " << simpleSearch(txt, search, txt_length, search_length) << " ";
	}
	else {
		cout << "file could not be opened";
	}
}
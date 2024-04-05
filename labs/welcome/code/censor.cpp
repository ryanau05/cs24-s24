#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "USAGE: censor [length]" << endl;
		exit(1);
	}

	int num_letters = stoi(argv[1]);
	string text;
	getline(cin, text);
	
	vector<string> sentence;
	string word;

	while (text.length() > 0){
		word = text.substr(0, text.find(' '));
		sentence.push_back(word);
		
		text = text.substr(text.find(' ') + 1);
	}
	/*
	for (int i = 0; i < sentence.size(); i++){
		cout << sentence.at(i) << endl;
	} */
	return 0;
}

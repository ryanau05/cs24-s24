#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		cerr << "USAGE: censor [length]" << std::endl;
		exit(1);
	}

	int word_size = stoi(argv[1]);
	string text;
	getline(cin, text);
	
	vector<string> words_split;
	string word;

	while (text.length() > 0){
		while(text.at(0) == ' '){
			text = text.substr(text.find(' ') + 1);
		}

		if (text.find(' ') == string::npos){
			word = text;
			text = "";
		}
		
		else {
			word = text.substr(0, text.find(' '));
			text = text.substr(text.find(' ') + 1);
		}
		
		words_split.push_back(word);
	}
	
	int vec_size = words_split.size();
	int curr_size;
	for (int i = vec_size - 1; i >= 0; i--){
		curr_size = words_split.at(i).length();
		if (curr_size == word_size){
			words_split.erase(words_split.begin() + i);
		}
	}
	
	vec_size = words_split.size();
	for (int i = 0; i < vec_size - 1; i++){
		cout << words_split.at(i) << " ";
	}
	cout << words_split.at(vec_size - 1) << endl;
	return 0;
}

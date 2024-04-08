#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		cout << "USAGE: censor [length]" << std::endl;
		exit(1);
	}

	int word_size = stoi(argv[1]);
	string text;
	getline(cin, text);
	
	vector<string> words_split;
	string word = "";
	
	int text_length = text.length();
	for (int i = 0; i < text_length; i++){
 	       if(text.substr(i).find(' ') == string::npos && text.substr(i).find('\t') == string::npos){
        		 word = text.substr(i);
        		 words_split.push_back(word);
           		 break;
	 }
	 else if (text.at(i) != ' ' && text.at(i) != '\t'){
		word += text.at(i);
	}
	else if((text.at(i) == ' ' || text.at(i) == '\t') && (text.at(i - 1) != ' ' && text.at(i - 1) != '\t')){
		words_split.push_back(word);
		word = "";
	}
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

#include "FileManager.h"
#include "TextSplitter.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
	//FileManager fin("test_s", "", "txt"), fout("test_s_out", "", "txt");
	//FileManager fin("test_b", "", "txt"), fout("test_b_out", "", "txt");
	//FileManager fin("test_b_1", "", "txt"), fout("test_b_1_out", "", "txt");
	//FileManager fin("test_ukr", "", "txt"), fout("test_ukr_out", "", "txt");
	//FileManager fin("test_pl", "", "txt"), fout("test_pl_out", "", "txt");
	FileManager fin("test_kr", "", "txt"), fout("test_kr_out", "", "txt");
	std::vector<std::string> lines = fin.readFile();
	std::map<std::string, int> words;
	std::vector<std::vector<std::string>> splitedLines;
	for (const auto& l : lines) {
		splitedLines.push_back(TextSplitter(l, " ,-\t\n\\\"()'`{}[].:;!@#$%&_?|/~1234567890<>=+*").split(true));
	}
	for (const auto& spl : splitedLines) {
		for (const auto& word : spl) {
			words[word] += 1;
		}
	}
	fout.writeFile(words);
	system("pause");
}
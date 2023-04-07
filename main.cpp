#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
using namespace std;

void lexer(string s) {
  string lexeme;
  stringstream ss(s);

  ofstream outFile;
  outFile.open("output.txt");
  outFile << "Token__________Lexeme" << endl;
  while (ss >> lexeme) {
    if (regex_match(lexeme, regex("(while|if|else|do|for)"))) {
      outFile << "Keyword				";
    } else if (regex_match(lexeme, regex("([{}():;,])"))) {
      outFile << "Separator				";
    } else if (regex_match(lexeme, regex("([a-zA-Z_][a-zA-Z0-9_]*)"))) {
      outFile << "Identifier				";
    } else if (regex_match(lexeme, regex("(\\+|-|\\*|/|\\=|<|>)"))) {
      outFile << "Operator				";
    } else if (regex_match(lexeme, regex("([0-9]+\\.[0-9]*|[0-9]*\\.[0-9]_)"))) {
      outFile << "Real				";
    }
    outFile << lexeme << endl;
  }
  outFile.close();
}

int main() {
  string code_block;
  ifstream inFile;
  inFile.open("input_scode.txt");
  if (inFile.fail()) {
    cout << "File not found!" << endl;
    return 0;
  }
  getline(inFile, code_block);
  cout << "File string: " << endl << code_block << endl << endl;

  lexer(code_block);

  inFile.close();

  return 0;
}
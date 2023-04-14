/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main() {
    std::ifstream file("words.txt");
    std::string line;
    std::map<std::string, int> wordCount;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            wordCount[word]++;
        }
    }

    for (const auto& pair : wordCount) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}

/*
Problem:
Given a text file called "words.txt", write a C++ program 
that reads in the file, counts the number of occurrences of each word, 
and prints the results to the console.

The output should be case-sensitive, words in uppercase and lowercase 
should be treated as distinct words.
The new streams we learned about in lecture namely std::ifstream, std::getline, 
and std::stringstream will be helpful here! 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
    // TODO: Write your code here
    std::ifstream fp("words.txt");
    std::unordered_map<std::string, int> umap;
    std::string line;

    while (std::getline(fp, line)) {
        std::stringstream words(line);
        std::string word;
        while (words >> word) {
            umap[word]++;
        }
    }

    for (auto &group: umap) {
        std::cout << group.first << " : " << group.second << std::endl;
    }

    return 0;
}
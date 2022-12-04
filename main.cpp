#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <filesystem>
#include <vector>




// TODO: Handle human errors etc.
// TODO: Tests script for program
// TODO: Identify side effects of each function
// TODO: Highlight functional and non functional part of program
// TODO: Powerpoint presentation
// TODO: READMe update -> containing how to use and start program
// TODO: Add debug to makefile maybe?

/**
 * std::map to store keys(strings) and values(ints) pairs
 */
typedef std::map<std::string, int> StringIntMap;

/**
 * word_counter: Reads in non-whitespaces from an istream and places them in a string
 * with the help of an operator >> and updates the statistics of each word in the map.
 *
 * @param input - left side operand , input from std::istream
 * @param words - StringIntMap of word with its occurrence.
 * @return void
 */

auto word_counter = [](std::istream &input, StringIntMap &words) {
// TODO: make word counter conform to functional programming paradigm -> replace while loop maybe?
    std::string stringHolder;

    // Reads non-whitespace and places them in the string holder
    // TODO: Make reader better, character maybe and not whitespaces -> low priority
    while (input >> stringHolder) {
        // Updates the stats in the map
        ++words[stringHolder];
    }
};


/**
 * recursive_directory_search: Uses the std::filesystem library to iterate over
 * elements of a give directory, and, recursively, over the entries of all subdirectories
 * and returns vector of strings with matching file extensions.
 *
 * @param path - Path to the directory to be searched.
 * @param extension - file-extension to filter.
 * @return vector of strings of paths of files with matching extensions.
 */

auto recursive_directory_search = [](const std::string &path, const std::string &extension) -> std::vector<std::string> {
    std::vector <std::string> filepath;
    for (const auto &entry: std::filesystem::recursive_directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            filepath.push_back(entry.path());
        }
    }
    return filepath;
};

/**
 * file_accessor: Opens filepaths, uses the word_counter function and converts the StringIntMap to a vector of
 * pair of strings and ints.
 *
 * @param extensionFile - files with content where each word are to be counted.
 * @return pairs, a vector of pair of strings and ints
 */
auto file_accessor = [](const std::vector <std::string> &extensionFile) -> std::vector <std::pair<std::string, int>>  {
// TODO: Maybe break down into multiple functions
    std::ifstream inputFile;
    StringIntMap map;
    std::vector <std::pair<std::string, int>> pairs;

    for (auto file: extensionFile) {
        inputFile.open(file, std::ios::out);
        if (inputFile.is_open()) {
            word_counter(inputFile, map);
            inputFile.close();
        } else std::cout << "Unable to open file" << std::endl;
    }

    for (auto &word: map) {
        pairs.emplace_back(word);
    }
    return pairs;
};

/**
 * sorter: LambdaIO, sorts the value of each word occurrence in a descending order and prints the result.
 *
 * @param pairs vector of pair of strings and ints
 * @return void
 */
auto sorter = [](std::vector<std::pair<std::string, int>> pairs) -> std::vector<std::pair<std::string, int>> {
    sort(pairs.begin(), pairs.end(), [=](std::pair<std::string , int> &a, std::pair<std::string, int> &b) {
             return a.second > b.second;
         }
    );
    return pairs;
};

int main() {
    std::string path, extension;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;
    std::cout << "Enter extension" << std::endl;
    std::cin >> extension;

    std::vector<std::string> directory = recursive_directory_search(path, extension);
    std::vector<std::pair<std::string, int>> accessor = file_accessor(directory);
    std::vector<std::pair<std::string, int>> pairs = sorter(accessor);
    for (auto &i: pairs) {
        std::cout << i.first << " -> " << i.second << std::endl;
    }

    return 0;
}


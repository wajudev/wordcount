#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <filesystem>
#include <vector>



// TODO: Sort function - decreasing order -> most common to least common -> how to sort the second value of a map? is it better to sort an unordered map!
// TODO: Handle human errors etc.
// TODO: Tests script for program
// TODO: Identify side effects of each function
// TODO: Highlight functional and non functional part of programm
// TODO: Powerpoint presentation
// TODO: READMe update -> containing how to use and start programm
// TODO: Add debug to makefile maybe?

// store string/int pairs
typedef std::map<std::string, int> StringIntMap;


// TODO: make word counter conform to functional programming paradigm -> replace while loop maybe?
auto word_counter = [](std::istream &input, StringIntMap &words) {
    std::string stringHolder;

    // Reads non-whitespace and places them in the string holder
    // TODO: Make reader better, character maybe and not whitespaces -> low priority
    while (input >> stringHolder) {
        // Updates the stats in the map
        ++words[stringHolder];
    }
};

auto recursive_directory_search = [](const std::string &path, const std::string &extension) {
    std::vector <std::string> filepath;
    for (const auto &entry: std::filesystem::recursive_directory_iterator(path)) {
        if (entry.path().extension() == extension) {
            //std::cout << entry.path().stem().string() << std::endl;
            filepath.push_back(entry.path());
            /*for (auto i: filepath) {
                std::cout << i << std::endl;
            }*/
        }
    }
    return filepath;
};

/*auto map_sorter = [](const StringIntMap &map) {

};*/


// TODO: Maybe break down into multiple functions -
auto file_accessor = [](const std::vector <std::string> &extensionFile) {
    std::ifstream inputFile;
    StringIntMap map;

    for (auto file: extensionFile) {
        inputFile.open(file, std::ios::out);
        if (inputFile.is_open()) {
            word_counter(inputFile, map);
            for (auto &word: map) {
                // feature of map that uses <utility> template
                std::cout << word.first << " -> " << word.second << std::endl;
                //map_sorter(word);
            }
            inputFile.close();
        } else std::cout << "Unable to open file" << std::endl;
    }
};


int main() {
    std::string path, extension;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;
    std::cout << "Enter extension" << std::endl;
    std::cin >> extension;

    //recursive_directory_search(path, extension);
    file_accessor(recursive_directory_search(path, extension));

    return 0;
}
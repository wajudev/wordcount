#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <filesystem>


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
    std::string filepath;
    for (const auto &entry: std::filesystem::recursive_directory_iterator(path)) {
        // TODO Do something cool other than print
        if (entry.path().extension() == extension) {
            // TODO maybe save all paths in a vector to be accessed later (Accessed recursively?)
            // std::cout << entry.path().stem().string() << std::endl;
            filepath = entry.path();
        }
    }
    return filepath;
};

// TODO: Figure out how to access content of all files -> currently only works for the last file foun
auto file_accessor = [](const std::string &extensionFile) {
    std::ifstream file;
    StringIntMap map;

    file.open(extensionFile, std::ios::out);

    if (file.is_open()) {
        word_counter(file, map);
        for (auto &word: map) {
            // feature of map that uses <utility> template
            std::cout << word.first << " -> " << word.second << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file" << std::endl;
};

// TODO: Handle human errors etc.

int main() {
    std::string path, extension;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;
    std::cout << "Enter extension" << std::endl;
    std::cin >> extension;

    file_accessor(recursive_directory_search(path, extension));

    return 0;
}
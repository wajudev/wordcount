#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

auto recursive_directory_search = [](const std::string &path, const std::string &extension) {
    std::string filepath;
    for (const auto &entry: std::filesystem::recursive_directory_iterator(path)) {
        // TODO Do something cool other than print
        if (entry.path().extension() == extension) {
            // TODO maybe save all paths in a vector to be accessed later (Accessed recursively?)
            std::cout << entry.path().stem().string() << std::endl;
            filepath = entry.path();
        }
    }
    return filepath;
};

// TODO Figure out how to access content of file
// Doesn't work! & not functional
auto file_accessor = [](const std::string &extensionFile) {
    std::string data;
    std::ifstream file;
    file.open(extensionFile, std::ios::out);

    if (file.is_open()) {
        while (getline(file, data)) {
            std::cout << data << std::endl;
        }
        file.close();
    } else std::cout << "Unable to open file" << std::endl;
};

// TODO Word counter
//auto word_counter = [](){};


// TODO Bericht printer


int main() {
    std::string path, extension;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;
    std::cout << "Enter extension" << std::endl;
    std::cin >> extension;

    file_accessor(recursive_directory_search(path, extension));

    return 0;
}
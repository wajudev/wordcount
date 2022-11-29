#include <iostream>
#include <string>
#include <filesystem>

auto recursive_directory_search =[](const std::string &path, const std::string &extension){
    for (const auto & entry: std::filesystem::recursive_directory_iterator(path)) {
        // TODO Do something cool other than print
        if (entry.path().extension() == extension){
            std::cout << entry.path().stem().string() << std::endl;
        }
    }
};


// TODO Figure out how to access content of file
// TODO Word counter
// TODO Word printer


int main(){
    std::string path, extension;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;
    std::cout << "Enter extension" << std::endl;
    std::cin >> extension;

    recursive_directory_search(path, extension);

    std::cout << "Hello, Welcome to Word Count Universe, where we count words pointlessly" << std::endl;
    return 0;
}
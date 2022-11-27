#include <iostream>
#include <string>
#include <filesystem>

auto recursive_directory_search =[](const std::string &path){
    for (const auto & entry: std::filesystem::recursive_directory_iterator(path)) {
        // TODO Do something cool other than print
        std::cout << entry.path() << std::endl;
    }
};

// TODO Figure out how to integrate file extension as second parameter
// TODO Figure out how to access content of file
// TODO Word counter
// TODO Word printer


int main(){
    std::string path;
    std::cout << "Enter directory path" << std::endl;
    std::cin >> path;

    recursive_directory_search(path);

    std::cout << "Hello, Welcome to Word Count Universe, where we count words pointlessly" << std::endl;
    return 0;
}
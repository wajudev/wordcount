# Wordcount

## Explanation
* The application has two command line arguments: the path to the directory to be analyzed, and the file-extensions (as string) which should be taken into account (for example users want to count words only in, say .java files)
* The program recursively enumerates all files in the directory matching the supplied file extension
* The program computes the list of all words in the files and computes the number of occurences for each word. Thus, the result is a list of words and their number of appearance in all files. The program prints this list sorted by the word count decreasingly (the most common word comes first).

## Getting started
1. Compile program by typing `make`. Now the program starts automatically.
   - Once the program has been compiled, it can be started again and again with the command `.out/main`or you go to the `out`directory and start the program with a double click
2. Specify the path where you want to count the words
3. Specify the file type 
  

## Contributors
* Olanrewaju Ajibua
* Tom Mihnjak

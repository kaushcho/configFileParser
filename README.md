# configFileParser
C++ Library to read and parse configuration files containing key value pairs with support for comments

# Structure
The code is not really structured as a library and since I didn't bother writing a makefile for the project, I left the headers and source in the same directory for now.

# Building
The code has been tested with gcc versions 5.4 and 8.2 on Ubuntu and OSX respectively. 

## Compilation Command
g++ -o configurator -std=c++11 *.cpp

# roman-calculator
This project provides a c library for adding and subtracting Roman numerals. The project has been creating using the Check unit testing framework (https://libcheck.github.io/check/). The source code structure follows the basic setup instructions found with the Check unit testing framework.

## setting up the environment
Before building the library make sure that your Ubuntu 14.04 environment has the following packages installed:
* check 
* git
* autoconf
* automake
* autotools-dev
* valgrind
```bash
sudo apt-get install check
sudo apt-get install git
sudo apt-get install autoconf
sudo apt-get install automake
sudo apt-get install autotools-dev
sudo apt-get install valgrind
```

## building the library and running the tests
The steps are:
* clone the repository
* configure the project
* run the tests
```bash
git clone https://github.com/mtromp/roman-calculator.git
cd roman-calculator
autoreconf --install
./configure
make check
```
The tests should all pass. The library can be found in the src directory.

The command for testing for memory leaks is:
```bash
 libtool --mode=execute valgrind --leak-check=full ./tests/check_romancalc
 ```
 
 ## Future enhancements
 * Take the arrays: symbols and multis out of the abacus structure and make them static elements.
 * Place the build artifacts into a build directory.
 * Place the configuration artifacts into a separate directory in a way that makes it easier to set up .gitignore.
 * Add checks for valid roman numerals.
 * Provide a main program that takes in Roman Numerals and operations from the command line. A quit command would exit the program.
 * Incorporate suggestions from others.
 * Look at other solutions for this kata to get ideas for other improvements.



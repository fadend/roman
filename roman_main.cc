#include "roman.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Takes one arg: <number> to convert\n";
    return 1;
  }
  std::cout << roman_numerals::convert(std::stoi(argv[1])) << '\n';
}
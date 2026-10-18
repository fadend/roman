#include "roman.h"

#include <array>
#include <stdexcept>

namespace roman_numerals {
namespace {
struct Symbol {
  char symbol[3];
  int value;
};

constexpr int kNumSymbols = 13;
constexpr std::array<Symbol, kNumSymbols> kSymbols = {
    Symbol{"M", 1000}, Symbol{"CM", 900}, Symbol{"D", 500}, Symbol{"CD", 400},
    Symbol{"C", 100},  Symbol{"XC", 90},  Symbol{"L", 50},  Symbol{"XL", 40},
    Symbol{"X", 10},   Symbol{"IX", 9},   Symbol{"V", 5},   Symbol{"IV", 4},
    Symbol{"I", 1}};
} // namespace

std::string convert(int n) {
  if (n <= 0 || n >= 4000) {
    throw std::domain_error("outside range [1, 3999]");
  }
  std::string result;
  int remainder = n;
  for (const auto &symbol : kSymbols) {
    while (remainder >= symbol.value) {
      remainder -= symbol.value;
      result.append(symbol.symbol);
    }
  }
  return result;
}

} // namespace roman_numerals
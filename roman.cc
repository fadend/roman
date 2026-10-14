#include "roman.h"

#include <array>
#include <stdexcept>

namespace roman_numerals {
namespace {
struct Symbol {
  char letter;
  int value;
};

constexpr int kNumSymbols = 7;
constexpr std::array<Symbol, kNumSymbols> kSymbols = {
    Symbol{'M', 1000}, Symbol{'D', 500}, Symbol{'C', 100}, Symbol{'L', 50},
    Symbol{'X', 10},   Symbol{'V', 5},   Symbol{'I', 1}};
} // namespace

std::string convert(int n) {
  if (n <= 0 || n >= 4000) {
    throw std::domain_error("outside range [1, 3999]");
  }
  std::string result;
  int remainder = n;
  for (int i = 0; i < kNumSymbols; ++i) {
    const auto &symbol = kSymbols[i];
    int count = 0;
    while (remainder >= symbol.value) {
      remainder -= symbol.value;
      ++count;
    }
    if (count >= 4 && i > 0) {
      const auto &previous = kSymbols[i - 1];
      int diff = previous.value - count * symbol.value;
      result += std::string(diff / symbol.value, symbol.letter);
      result.push_back(previous.letter);
    } else {
      result += std::string(count, symbol.letter);
    }
  }
  return result;
}

} // namespace roman_numerals
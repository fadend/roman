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
    if (count >= 4 && i > 1) {
      const auto &previous1 = kSymbols[i - 1];
      const auto &previous2 = kSymbols[i - 2];
      int diff1 = previous1.value - count * symbol.value;
      int diff2 = previous2.value - count * symbol.value;
      int minus_count1 = diff1 / symbol.value;
      int minus_count2 = diff2 / symbol.value;
      if (minus_count1 < minus_count2) {
        result += std::string(minus_count1, symbol.letter);
        result.push_back(previous1.letter);
      } else {
        result += std::string(minus_count2, symbol.letter);
        result.push_back(previous2.letter);
      }
    } else {
      result += std::string(count, symbol.letter);
    }
  }
  return result;
}

} // namespace roman_numerals
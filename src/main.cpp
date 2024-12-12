#include "../include/acalc/interface/interface.hpp"
#include "../include/acalc/math/math.hpp"

auto main() -> int {
  Interface interface(">", '@');
  Math<double> math;

  interface.add("exit", []() { std::exit(0); });
  interface.add("history", [&interface]() {
    for (const std::string &command : interface.history()) {
      std::cout << command << '\n';
    }
  });
  interface.add("clear", []() { std::cout << "\033[2J\033[1;1H"; });

  while (true) {
    std::string input = interface.getInput();
    if (input.starts_with(interface.symbol())) {
      interface.execute(input);
    } else {
      double result = math.compile(input);
      std::cout << result << '\n';
      interface.addHistory(input);
    }
  }
}

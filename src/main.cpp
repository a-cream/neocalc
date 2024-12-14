#include "../include/neocalc/interface/interface.hpp"
#include "../include/neocalc/math/math.hpp"

auto main() -> int {
  Interface interface(">", '@');
  Math<double> math;

  interface.add(
      "exit", []() { std::exit(0); }, "Exits the program."
  );
  interface.add(
      "history",
      [&interface]() {
        for (const std::string &command : interface.history()) {
          std::cout << command << '\n';
        }
      },
      "Shows the past ran commands & math expressions."
  );
  interface.add(
      "clear", []() { std::cout << "\033[2J\033[1;1H"; }, "Clears the screen."
  );
  interface.add(
      "help",
      [&interface]() {
        std::cout << "Copyright [2024] [Acream]" << '\n';
        std::cout << "Neocalc is a lightweight, lightning-fast mathematical calculator designed for Unix terminals."
                  << '\n'
                  << "Powered by Exprtk, it brings advanced mathematical capabilities directly to your command line."
                  << '\n';
        std::cout << "Commands: " << '\n';
        std::map<std::string, std::string> commands = interface.aboutCommands();
        for (const auto &[command, description] : commands) {
          std::cout << interface.symbol() << command << " - " << description << '\n';
        }
      },
      "Shows information to help you."
  );

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

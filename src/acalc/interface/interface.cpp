#include "../../../include/acalc/interface/interface.hpp"
#include <iostream>

Interface::Interface(const std::string &prompt, char symbol) : m_prompt(prompt), m_symbol(symbol){};

void Interface::execute(const std::string &input) {
  m_history.push_back(input);

  auto it = m_commands.find(input.substr(1));
  if (it != m_commands.end()) {
    it->second();
    return;
  }
  std::cerr << "Could not find command" << '\n';
}

auto Interface::getInput() -> std::string {
  std::cout << m_prompt << ' ';

  std::string input;
  std::getline(std::cin, input);
  return input;
}

void Interface::add(const std::string &command, const std::function<void()> &callback) {
  m_commands[command] = callback;
}

void Interface::addHistory(const std::string &input) { m_history.push_back(input); }

auto Interface::history() const -> const std::vector<std::string> { return m_history; }

auto Interface::symbol() -> char { return m_symbol; }

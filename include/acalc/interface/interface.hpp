#pragma once

#include <functional>
#include <map>
#include <string>

class Interface {
public:
  Interface(const std::string &prompt, char symbol);

  void execute(const std::string &input);
  auto getInput() -> std::string;
  void add(const std::string &command, const std::function<void()> &callback);
  void addHistory(const std::string &input);
  [[nodiscard]] auto history() const -> const std::vector<std::string>;
  auto symbol() -> char;

private:
  std::string m_prompt;
  char m_symbol;
  std::map<std::string, std::function<void()>> m_commands;
  std::vector<std::string> m_history;
};

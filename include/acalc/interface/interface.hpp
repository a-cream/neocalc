#pragma once

#include <functional>
#include <map>
#include <string>

class Interface {
public:
  Interface(const std::string &prompt, char symbol);

  void execute(const std::string &input);
  auto getInput() -> std::string;
  void add(const std::string &command, const std::function<void()> &callback, const std::string &description);
  void addHistory(const std::string &input);
  [[nodiscard]] auto history() const -> std::vector<std::string>;
  [[nodiscard]] auto symbol() const -> char;
  [[nodiscard]] auto aboutCommands() const -> std::map<std::string, std::string>;

private:
  std::string m_prompt;
  char m_symbol;
  std::map<std::string, std::function<void()>> m_commands;
  std::map<std::string, std::string> m_aboutCommands;
  std::vector<std::string> m_history;
};

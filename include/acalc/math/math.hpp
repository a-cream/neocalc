#pragma once

#include "../../vendor/exprtk/exprtk.hpp"
#include <iostream>

template <typename T>
class Math {
public:
  Math<T>() {
    m_symbolTable.add_pi();
    // GR (golden ratio)
    m_symbolTable.add_constant("gr", (1 + std::sqrt(5)) / 2);
  };

  auto compile(const std::string &expression) -> T {
    m_history.push_back(expression);
    m_expression.register_symbol_table(m_symbolTable);

    if (m_parser.compile(expression, m_expression)) {
      return m_expression.value();
    }

    std::cerr << m_parser.error() << '\n';
    return 1;
  }

  void addVariable(const std::string &name, const T &value) {
    m_symbolTable.add_variable(name, value);
  }

  void addFunction(const std::string &name, const std::function<T(...)> &callback) {
    m_symbolTable.add_function(name, callback);
  }

  auto history() -> std::vector<std::string> { return m_history; }

private:
  exprtk::symbol_table<T> m_symbolTable;
  exprtk::parser<T> m_parser;
  exprtk::expression<T> m_expression;
  std::vector<std::string> m_history;
};
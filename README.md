# Acalc: A Powerful Terminal-Based Calculator

Acalc is a lightweight, lightning-fast mathematical calculator designed for Unix terminals. Powered by Exprtk, it brings advanced mathematical capabilities directly to your command line.

## 🚀 Key Features

* **Expressive Calculations**: Leverage the full power of Exprtk's advanced mathematical expression parsing
* **Terminal-Friendly**: Lightweight and fast, optimized for command-line use
* **Built-in Commands**: Special commands like `@clear` for enhanced usability
* **No External Dependencies**: Easy to install and use across different Unix systems

## 📦 Installation

### Prerequisites
- CMake
- C++ compiler with C++20 support

### Compilation Steps
```bash
# Clone the repository
git clone https://github.com/a-cream/acalc.git
cd acalc

# Build the project
cmake -S . -B build && cmake --build build
```

## 💡 Usage Examples

```bash
# Basic arithmetic
> 2 + 3 * 4
14

# Complex mathematical expressions
> sin(pi/2) + sqrt(16)
5

# Special commands
@clear  # Clear the current session
@history   # Show history
```

## 🧮 Supported Operations

Acalc supports a wide range of mathematical operations through Exprtk, including:
- Arithmetic operations
- Trigonometric functions
- Logarithmic functions

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License

Uses Apache-2.0 License.

## 🔗 Related Projects
- [Exprtk](https://github.com/ArashPartow/exprtk) - Mathematical Expression Parser Library

# Aether Engine

**Aether** is a lightweight **2D game engine** written in **C++**, built on top of **SDL3**.  
It’s designed to provide a simple and flexible foundation for creating 2D games.

---

## 🚀 Features

- Built with **C++17+**
- Uses **SDL3** for rendering, input, and window management
- Simple and modular architecture
- Basic 2D rendering pipeline (sprites, textures, etc.)
- Cross-platform support (Windows, Linux, macOS)

---

## 🛠️ Getting Started

### Prerequisites
- **CMake** (version 3.20 or higher)
- **SDL3** development libraries
- A **C++17-compatible** compiler (e.g., MSVC, Clang, or GCC)

### Build Instructions

```bash
git clone https://github.com/lowlevelmetal/aetherengine.git aether
cd aether
mkdir build && cd build
cmake ..
cmake --build .
````

---

## 🧩 Example

```cpp
#include <Aether/Aether.hpp>

int main() {
    Aether::Engine engine("Aether Demo", 800, 600);

    while (engine.isRunning()) {
        engine.handleEvents();
        engine.clear();

        // Draw your game objects here

        engine.present();
    }

    return 0;
}
```

---

## 📂 Project Structure

```
Aether/
├── src/include/       # Public headers
├── src/           # Engine source code
├── examples/      # Example projects
├── assets/        # Textures, sounds, etc.
└── CMakeLists.txt # Build configuration
```

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

## 💬 Contributing

Contributions are welcome!
Feel free to submit issues, feature requests, or pull requests.

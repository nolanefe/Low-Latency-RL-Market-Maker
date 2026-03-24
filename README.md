# Low-Latency RL Market Maker #

A lightweight, C++ based market-making matching engine integrated with a custom Q-Learning algorithm. This project serves as a conceptual prototype to bridge the gap between AI theoretical models (Reinforcement Learning) and high-performance, memory-safe execution environments. 

##  Core Architecture ##
* **Q-Learning Agent:** Implements the Bellman equation using standard C++ data structures (`std::unordered_map`, `std::vector`) for $O(1)$ average time complexity on state lookups.
* **State Hashing:** Utilizes bitwise hashing to convert market states (bid-ask spread, inventory) into lightweight `uint64_t` keys for rapid memory access.
* **Zero-Leak Memory:** Built entirely without manual memory management (`new`/`delete`), relying on modern C++ standard library containers to ensure safety.

##  Tech Stack ##
* **Language:** C++17
* **Build System:** CMake
* **Domain:** Reinforcement Learning, Algorithmic Trading Concepts

##  Build and Execution ##
Note: Requires a C++17 compliant compiler (GCC/Clang/MSVC) and CMake 3.10+.
This project uses CMake for cross-platform compilation. 

```bash
1. Clone the repository
git clone [https://github.com/nolanefe/Low-Latency-RL-Market-Maker.git](https://github.com/nolanefe/Low-Latency-RL-Market-Maker.git)
cd Low-Latency-RL-Market-Maker

2. Compile and run using the provided script
chmod +x build.sh
./build.sh
```

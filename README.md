# PracticeCPP – C++ Interview Prep Project

This project is a personal C++ playground for reviewing and implementing core techniques, data structures, algorithms, and modern features in preparation for technical interviews.

---

## CI/CD Pipeline and Tooling

This project uses **GitHub Actions** for continuous integration. Key features:

1. **Build & Test**  
   - Automatically compiles the project with CMake on every push or pull request.
   - Runs all Catch2 unit tests.
   - Ensures the build is passing before merging changes.

2. **Static Analysis (clang-tidy)**  
   - Checks for potential bugs, bad practices, and performance issues.
   - Configured with a `.clang-tidy` file to control which checks run.
   - Results are displayed in the GitHub Actions logs.

3. **Code Coverage (llvm-cov)**  
   - Built with Clang coverage instrumentation (`-fprofile-instr-generate`, `-fcoverage-mapping`).
   - Executes tests and merges profile data into a coverage report.
   - Uploads a detailed line-by-line coverage file (`coverage.txt`) to GitHub Actions artifacts.
   - Excludes irrelevant directories (e.g. `_deps/`, `tests/`).
   - Shows how much of the codebase is exercised by tests.

### Running the Pipeline Locally

You can replicate the CI steps locally:

1. **Install Dependencies**  
   - Clang/LLVM (for instrumentation, static analysis, and coverage)
   - CMake (for building)

2. **Build With Coverage**  
   ```bash
   ./scripts/build_with_coverage.sh



---

## ✅ Completed Bit Manipulation Features

The following utility functions have been implemented and tested as part of the `BitManipulator` module:

- [x] `getNthBit` – Returns 0 or 1 for the given bit position  
- [x] `setNthBit` – Returns a copy of the number with the given bit set to 1  
- [x] `clearNthBit` – Returns a copy of the number with the given bit cleared to 0  
- [x] `printBits` – Prints a 32-bit binary representation to standard output  
- [x] `countNumberOfBitsSet` – Counts the number of bits set to 1 using Brian Kernighan’s algorithm  
- [x] `reverseBits` – Reverses the bits over a given width (e.g. 4, 8, 32 bits)  
- [x] `swapBits` – Swaps bits at two specified positions  
- [x] `isPowerOfTwo` – Returns true if the number is a power of two  
- [x] `isolateRightmostSetBit` – Returns the least significant bit that is set  

All functions are implemented as `static` methods and fully unit tested using Catch2.

---

## 📦 Data Structures (from scratch)
- [ ] Singly Linked List
- [ ] Doubly Linked List
- [ ] Stack
- [ ] Queue (circular preferred)
- [x] Hash Table
- [ ] Binary Tree (with traversal)
- [ ] Trie
- [ ] Graph (adjacency list/matrix)
- [ ] LRU Cache

---

## ⚙️ Algorithms
- [ ] Bubble Sort
- [ ] Insertion Sort
- [ ] Merge Sort
- [ ] Quick Sort
- [ ] Binary Search (iterative)
- [ ] Binary Search (recursive)
- [ ] Recursion / Backtracking (e.g., N-Queens, Subsets)
- [ ] DFS/BFS (tree or graph)
- [ ] Dynamic Programming (Fibonacci, Coin Change)

---

## 📚 STL Practice
- [ ] Vectors & Iterators
- [ ] Sets & Maps
- [ ] Queues & Priority Queues
- [ ] `std::sort`, `std::find_if`, `std::accumulate`
- [ ] `std::pair`, `std::tuple`, `std::optional`
- [ ] Range-based for loops

---

## 🔐 Object-Oriented Programming
- [x] Classes & Constructors
- [ ] Inheritance
- [ ] Virtual functions & Polymorphism
- [ ] Rule of 3 / Rule of 5
- [ ] Operator Overloading
- [ ] Interfaces via abstract classes

---

## 🧼 Memory Management
- [ ] Raw pointers with `new`/`delete`
- [ ] RAII pattern
- [ ] `unique_ptr`, `shared_ptr`, `weak_ptr`
- [ ] Dangling pointer examples
- [ ] Manual vs. smart pointer comparison

---

## 💎 Modern C++ Features
- [ ] `auto`, `decltype`, `constexpr`
- [ ] Lambda expressions
- [ ] `std::function`
- [ ] Move semantics
- [ ] `std::optional`, `std::variant`
- [ ] Structured bindings (C++17)

---

## 🔧 Multithreading (Advanced)
- [ ] `std::thread`, `std::mutex`, `std::lock_guard`
- [ ] Deadlock example + fix
- [ ] `std::condition_variable`
- [ ] Thread-safe data structure
- [ ] `std::async` / `std::future`

---

## 🧪 Unit Testing & Debugging
- [x] Catch2 integration
- [x] Binary printing with `std::bitset`
- [ ] Test coverage for all modules
- [ ] TDD examples

---

## 💼 System Design Concepts (Lite)
- [ ] Layered design (Data, Logic, UI separation)
- [ ] Interface/abstraction via pure virtual classes
- [ ] Testable modules with dependency injection

---

## ✅ Usage

```bash
cmake -S . -B build
cmake --build build
./build/src/PracticeApp
./build/tests/UnitTests -s
./scripts/build_with_coverage.sh
./scripts/run_coverage.sh
clang-tidy src/*.cpp -- -Iinclude -std=c++17

# PracticeCPP – C++ Interview Prep Project

This project is a personal C++ playground for reviewing and implementing core techniques, data structures, algorithms, and modern features in preparation for technical interviews.

---

## 🧠 Bit Manipulation
- [x] `reverseBits()`
- [x] `countSetBits()`
- [ ] `checkPowerOfTwo()`
- [ ] `swapBits()`
- [ ] `isolateRightmostSetBit()`

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

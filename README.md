# Modern C++ 32 Lectures

This project contains example code from the "Modern C++ 32 Lectures" course, demonstrating various features and best practices of modern C++.

## Directory Structure

```
.
├── README.md
├── nrvo.cpp
├── obj_lifecycle.cpp
├── smart_ptr.cpp
└── vector.cpp
```

## File Descriptions

### vector.cpp
Demonstrates the usage of `std::vector` and the impact of the `reserve` function on performance. Shows when constructor, copy constructor, and move constructor are called during container operations.

Key learning points:
- Usage of `std::vector::reserve()`
- Impact of move semantics on container performance
- Object lifecycle management

### smart_ptr.cpp
Implements a smart pointer class similar to `std::shared_ptr`, showcasing memory management techniques in modern C++.

Features include:
- Shared ownership mechanism
- Reference counting management
- Automatic memory release
- Support for various type casting operations (static_pointer_cast, dynamic_pointer_cast, etc.)
- Move semantics support

### obj_lifecycle.cpp
Demonstrates C++ object lifecycle management, including:
- Constructor and destructor call order
- Return Value Optimization (RVO/NRVO)
- Rvalue references and move semantics
- Temporary object lifecycle management

### nrvo.cpp
Specifically demonstrates Named Return Value Optimization (NRVO) concepts and effects.

## Compilation and Execution

Each example can be compiled and run separately:

```bash
# Compile vector example
g++ -o vector vector.cpp
./vector

# Compile smart pointer example
g++ -o smart_ptr smart_ptr.cpp
./smart_ptr

# Compile object lifecycle example
g++ -o obj_lifecycle obj_lifecycle.cpp
./obj_lifecycle

# Compile NRVO example
g++ -o nrvo nrvo.cpp
./nrvo
```

## Learning Objectives

Through these example codes, you can learn:

1. **Container Usage Best Practices** - How to effectively use `std::vector` and its performance optimization techniques
2. **Smart Pointer Implementation** - Understanding how smart pointers work and memory management mechanisms
3. **Object Lifecycle Management** - Mastering object construction, destruction, and optimization techniques in C++
4. **Modern C++ Features** - Including move semantics, template programming, exception safety, etc.
5. **RAII Principle** - Resource Acquisition Is Initialization programming concept

## Notes

These implementations are primarily for educational purposes, showcasing core concepts of modern C++. In production environments, it's recommended to use components provided by the standard library, such as `std::shared_ptr`, rather than self-implemented versions.
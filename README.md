# Modern C++ 32 Lectures

This project contains example code from the "Modern C++ 32 Lectures" course, demonstrating various features and best practices of modern C++.

## Directory Structure

```
.
├── README.md
├── nrvo.cpp
├── obj_lifecycle.cpp
├── smart_ptr.cpp
├── priority_queue.cpp
├── func_obj.cpp
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

### func_obj.cpp
Demonstrates usage of function objects and standard algorithms like `std::sort` with different comparison functions.

### priority_queue.cpp
Shows how to use `std::priority_queue` with custom comparators, particularly with `std::pair` elements.

### related_container.cpp
Demonstrates usage of related containers in the STL.
- `std::set` and `std::multiset` usage with custom comparators
- `std::map` and `std::multimap` operations
- Iterator usage with map containers
- Range operations with `equal_range`, `lower_bound`, and `upper_bound`

### unordered_container.cpp
Examples of unordered containers from the STL.
- `std::unordered_set` and `std::unordered_map` usage
- Hash function customization
- Bucket interface operations

## Compilation and Execution

Each example can be compiled and run separately:

```bash
# Compile example file
clang++ -std=c++17 -W -Wall -Wfatal-errors example.cpp -o example

# Run example
./example
```

## Learning Objectives
Through these example codes, you can learn:

1. Container Usage Best Practices - How to effectively use std::vector and its performance optimization techniques
2. Smart Pointer Implementation - Understanding how smart pointers work and memory management mechanisms
3. Object Lifecycle Management - Mastering object construction, destruction, and optimization techniques in C++
4. Modern C++ Features - Including move semantics, template programming, exception safety, etc.
5. RAII Principle - Resource Acquisition Is Initialization programming concept
6. Standard Library Algorithms - Using function objects and standard algorithms effectively
7. STL Containers - Working with various containers including sequence, associative, and unordered containers

## Notes

These implementations are primarily for educational purposes, showcasing core concepts of modern C++. In production environments, it's recommended to use components provided by the standard library, such as std::shared_ptr, rather than self-implemented versions.
# Modern C++ Smart Pointer Implementation

This project demonstrates a custom implementation of a smart pointer similar to `std::shared_ptr` in C++. It includes basic memory management features and supports common pointer operations.

## Features

- **Shared Ownership**: Multiple `smart_ptr` instances can share ownership of the same object
- **Automatic Memory Management**: Automatic deletion of managed objects when no more `smart_ptr` instances reference them
- **Type Safety**: Template-based design ensuring type safety
- **Move Semantics**: Support for move operations to transfer ownership efficiently
- **Cast Operations**: Support for common casting operations:
  - `static_pointer_cast`
  - `dynamic_pointer_cast`
  - `const_pointer_cast`
  - `reinterpret_pointer_cast`

## Classes

### `smart_ptr<T>`
Main smart pointer template class that manages the lifetime of dynamically allocated objects.

Key methods:
- Constructor: `smart_ptr(T *ptr = nullptr)`
- Copy constructor and assignment operator for shared ownership
- Move constructor and assignment operator for transferring ownership
- Dereference operators: `operator*()` and `operator->()`
- Boolean conversion: `operator bool()`
- Utility methods:
  - `get()`: Returns raw pointer
  - `use_count()`: Returns reference count
  - `swap()`: Swaps contents with another smart_ptr

### `shared_count`
Helper class that maintains the reference count for shared objects.

## Usage Example

```cpp
#include "smart_ptr.cpp"

// Create a smart pointer to a circle object
smart_ptr<circle> ptr1(new circle());
printf("use count of ptr1 is %ld\n", ptr1.use_count());

// Share ownership with another smart pointer
smart_ptr<shape> ptr2 = ptr1;
printf("use count after sharing is %ld\n", ptr1.use_count());

// Perform dynamic cast
smart_ptr<circle> ptr3 = dynamic_pointer_cast<circle>(ptr2);
```

## Implementation Details

The implementation follows modern C++ practices with:
- RAII (Resource Acquisition Is Initialization) principles
- Move semantics for efficient resource management
- Template metaprogramming for type safety
- Exception safety considerations (noexcept where appropriate)

## Building and Running

To build and run this project:

```bash
g++ -o smart_ptr smart_ptr.cpp
./smart_ptr
```

Note: This implementation is for educational purposes and may not be suitable for production use. For production code, use `std::shared_ptr` from the standard library.

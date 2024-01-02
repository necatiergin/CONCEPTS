// From Nicholai Jossutis C++20 book.
// http://cppstd20.com/code/lang/maxvalue.cpp.html
#include <iostream>

// concept for pointer-like objects:
template<typename T>
concept IsPointer = requires(T p) {
    *p;             // operator * has to be valid
    p == nullptr;   // can compare with nullptr
    {p < p} -> std::convertible_to<bool>;  // < yields bool
};

// maxValue() for plain values:
auto maxValue(auto a, auto b)
{
    return b < a ? a : b;
}

// maxValue() for pointers:
auto maxValue(IsPointer auto a, IsPointer auto b)
    requires std::totally_ordered_with<decltype(*a), decltype(*b)>
{
    return maxValue(*a, *b);  // return maximum value of where the pointers refer to
}

int main()
{
    int x = 42;
    int y = 77;
    std::cout << maxValue(x, y) << '\n';      // maximum value of ints
    std::cout << maxValue(&x, &y) << '\n';    // maximum value of where the pointers point to

    int* xp = &x;
    int* yp = &y;
    std::cout << maxValue(&xp, &yp) << '\n';  // maximum value of pointer to pointer

    double d = 49.9;
    std::cout << maxValue(xp, &d) << '\n';    // maximum value of int and double pointer
}

/*
we cannot use maxValue() to check for the maximum of two iterator values:
std::vector coll{0, 8, 15, 11, 47};
auto pos = std::find(coll.begin(), coll.end(), 11); // find specific value
if (pos != coll.end()) {
// maximum of first and found value:
auto val = maxValue(coll.begin(), pos); // ERROR
}
The reason is that we require the parameters to be comparable with nullptr, which is not required to be
supported by iterators. Whether or not this is what you want is a design question. However, this example
demonstrates that it is important to think carefully about the definition of general concepts.


*/


  

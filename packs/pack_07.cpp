#include <concepts>

template <typename Base, typename... Derived>
concept AllDerivedFrom = (std::derived_from<Derived, Base> && ...);

struct Animal {};

struct Dog : Animal {};
struct Cat : Animal {};
struct Bird : Animal {};

struct Car {};

static_assert(AllDerivedFrom<Animal, Dog, Cat, Bird>);

static_assert(!AllDerivedFrom<Animal, Dog, Car>);

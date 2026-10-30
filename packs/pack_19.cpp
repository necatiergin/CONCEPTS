template <typename T, typename... Ts>
concept SameSize = requires
{
    requires ((sizeof(T) == sizeof(Ts)) && ...);
};

static_assert(SameSize<int, int, int>);

static_assert(SameSize<char, char, char>);

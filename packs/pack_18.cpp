template <typename... Ts>
concept AllSmall = requires
{
    requires ((sizeof(Ts) <= 8) && ...);
};

struct Big {
    char buffer[100];
};

static_assert(!AllSmall<int, Big>);

template <typename... Ts>
concept Incrementable = requires(Ts... args)
{
    (++args, ...);
};

static_assert(Incrementable<int, long, double>);

static_assert(!Incrementable<const int>);

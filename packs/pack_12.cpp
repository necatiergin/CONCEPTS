template <typename... Ts>
concept AllDereferenceable = requires(Ts... args)
{
    ((*args), ...);
};

static_assert(AllDereferenceable<int*, double*, char*>);

static_assert(!AllDereferenceable<int*, int>);

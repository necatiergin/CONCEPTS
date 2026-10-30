template <typename... Fs>
concept AllCallable = requires(Fs... funcs)
{
    (funcs(), ...);
};

struct F1 {
    void operator()() {}
};

struct F2 {
    int operator()() { return 10; }
};

struct F3 {};

static_assert(AllCallable<F1, F2>);

static_assert(!AllCallable<F1, F3>);

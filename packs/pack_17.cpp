template <typename... Ts>
concept AllSmall = requires
{
    requires ((sizeof(Ts) <= 8) && ...);
};

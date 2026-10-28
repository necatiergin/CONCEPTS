template<class T>
concept SmallType = requires {
    // ...
    requires sizeof(T) <= 8;
};

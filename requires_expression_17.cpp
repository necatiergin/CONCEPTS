template<typename Container>
concept C1 = requires(Container::size_type) { }; //error


template<typename Container>
concept C2 = requires(Container::size_type) { true; }; //valid

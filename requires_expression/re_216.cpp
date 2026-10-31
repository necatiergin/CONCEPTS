template <typename T, typename P>
concept Con = requires(T tval, P p) {
	*p < tval; 
}
|| requires(P p) {
	p == nullptr;
};

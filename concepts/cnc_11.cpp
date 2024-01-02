#include <concepts>
#include <iterator>

template <typename T>
concept has_at = requires(T t, int i)
{
	t.at(i);
};

template <typename T>
concept has_iterator = requires(T t)
{
	{ std::begin(t) } -> std::input_iterator;
};

template <has_iterator T>
auto&& get(T&& t, int i)
{
	if constexpr (has_at<T>)
		return t.at(i);
	else
		return *std::next(std::begin(t), i);
}

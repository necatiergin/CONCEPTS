#include <concepts>

template <typename T>
concept Clock = requires (T clock)
{
	clock.start();
	clock.stop();
	clock.time();
};

struct Myclock {
	void start();
	void stop();
	double time()const;
};

template <Clock C>
class Myclass {

};

int main()
{
	Myclass<Myclock> m;
	//...
}

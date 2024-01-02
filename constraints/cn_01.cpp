#include <concepts>
#include <vector>


template<typename T>
requires (sizeof(T) > 2) // ad-hoc Boolean expression
&& requires { typename T::value_type; } // requires expression
&& std::input_iterator<T> // concept
void foo(T x) {
	
}

// constraint'lerin karşılanması için
// a) T türünün sizeof değeri 4'den  büyük olmalı
// b) T türünün value_type isimli 
// c) T türü standart std::input_iterator concept'ini karşılamalı (satisfy)

int main()
{
	std::vector<int> ivec(10);
	foo(ivec.begin());
}

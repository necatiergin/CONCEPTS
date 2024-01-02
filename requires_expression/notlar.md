* _requires clasue_ ile _requires expression_ birbiriyle karıştırılmamalı.
Örnek bir _requires expression_ <br>

```
template<typename T>
concept IsPointer = requires(T p) { *p; };
```
* _requires expression_ ile türler ya da parametrelere ilişkin bir yada birden fazla ister _(requirement)_ tanımlanabilir.

* Daha karmaşık bir örneğe bakalım:

```
#include <concepts>

template<typename T>
concept IsPointer = requires(T p) {
	*p; // 1
	p == nullptr; // 2
	{p < p} -> std::same_as<bool>; // 3
};


//1 *p ifadesi geçerli olmalı
//2 p == nullptr karşılaştırması geçerli olmalı
//3 p < p karşılaştırması geçerli olmalı ve elde edilen tür bool türü olmalı
``` 
* _requires expression_,  _requires clause_ ile birlikte bir _constraint_ olarak kullanılabilir, Ancak bu durum biraz görüntü kirliliği oluşturuyor:

```
template<typename T>
requires requires(T p) { *p; } // constrain template with ad-hoc requirement
auto maxValue(T a, T b)
{
	return maxValue(*a, *b);
}
```

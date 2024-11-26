_C++20 _ standardı ile dile eklenen concept'ler ve bunlara ilişkin araçlar ve standart kütüphane öğeleriyle şablonların _(templates)_ belirli türler ya da değerler için kullanımlarını kısıtlayabilir _(constrain)_ ve bunları kullanarak türden bağımsız _(generic)_ kodlarda derleme zamanında kod seçimi yaptırabiliriz.


#### concept'ler hangi faydaları sağlıyor?

- template kodları yazmayı, okumayı ve _debug_ etmeyi kolaylaştırıyor: : _TMP for everybody_
- template parametrelerine yönelik kısıtlamalar arayüzün _(interface)_ bir bileşeni hale geliyor. Bir _template_'a baktığımızda onun kısıtlamalarını doğrudan görebiliyoruz.
- _function overloading_ mekanizamasını destekliyor. Farklı kısıtlamalara göre fonksiyonları _overload_ edebiliyoruz.
- template argümanlarına yönelik hata mesajları çok daha kısa ve anlaşılır hale geliyor.
- _concept_'ler generik programlama tarafında _"placeholder"_ olarak kullanılabiliyor.
- kendi _concept_'lerimizi oluşturabiliyoruz.
- fonksiyon şablonlarında, sınıf şablonlarında, tür eş isim şablonlarında ve değişken şablonlarında kullanabiliyoruz.
- _non-type_ parametreler için de kullanabiliyoruz. 

#### requires clause
Bir _requires clause_ ile bir sınıf şablonu _(class template)_ bir fonksiyon şablonu _(function template)_ bir tür eş isim şablonu _(alias template)_ ya da bir değişken şablonu _(variable template)_ kısıtlanabilir.
Bir _requires clause_ _requires_ anahtar sözcüğü ve bir derleme zamanı _boolean_ ifadeden oluşur. Nitelediği _template_'in kullanımını kısıtlar _(constrains)_<br>
_requires clause_ operandı derleme zamanında değerlendirilir.

Boolean ifadeler şunlardan biri olabilir:<br>
- tek başına bir derleme zamanı ifadesi _(ad hoc compile time expression)_
- bir _concept_
- bir _requires expression_

Tüm _constraintler_ bir _boolean_ ifadenin kullanılabildiği  her yerde kullanılabilir.<br>
_Requires clause_'da birden fazla kısıtlamayı _(constraints)_ && operatörünü kullanarak kombine edebiliriz.
Eğer kısıtlamalardan birinin karşılanması yeterli ise yani alternatif kısıtlamalar oluşturmak istersek || operatörünü kullanabiliriz. 
```cpp
#include <iterator>
template<typename T>
requires (sizeof(T) > 4) // ad-hoc Boolean expression
&& requires { typename T::value_type; } // requires expression
&& std::input_iterator<T> // concept

void foo(T x) {
//...
}
```

Kısıtlamaların sıralaması bir anlam farklılığı oluşturmaz.<br>
Kısıtlamalarda || operatörü seyrek olarak kullanılır. Sık kullanımı derleme zamanını uzatabilir.<br>
_requires clause_'da birden fazla template parametresi kullanılabilir. Böylece _template_ parametreleri arasındaki ilişkiler kısıtlanabilir:

```cpp
#include <type_traits>

template<typename T, typename U>
requires std::convertible_to<T, U>
auto foo(T t, U u) 
{
	//...	
	return t + u;
}
```

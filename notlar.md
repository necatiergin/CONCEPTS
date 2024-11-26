#### concept'ler hangi faydaları sağlıyor?

- template kodları yazmayı ve _debug_ etmeyi kolaylaştırıyor.
- template kodları okumayı kolaylaştırıyor.
- template kodların derlenmesini kolaylaştırıyor.
- Burada slogan şu olmalı: _TMP for everybody_
 
- template parametrelerine yönelik kısıtlamalar arayüzün _(interface)_ bir bileşeni hale geliyor. Bir _template_'a baktığımızda onun kısıtlamalarını doğrudan görebiliyoruz.
- _function overloading_ mekanizamasını destekliyor. Farklı kısıtlamalara göre fonksiyonları _overload_ edebiliyoruz.
- template argümanlarına yönelik hata mesajları çok daha kısa ve anlaşılır hale geliyor.
- _concept_'ler generik programlama tarafında _"placeholder"_ olarak kullanılabiliyor.
- kendi _concept_'lerimizi oluşturabiliyoruz.
- hem fonksiyon şablonlarında hem de sınıf şablonlarında kullanabiliyoruz.
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
Eğer kısıtlamalardan birinin karşılanması yeterli ise || operatörünü kullanabiliriz. 
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

Kısıtlamaların sıralaması bir anlam farklılığı oluşturmaz.

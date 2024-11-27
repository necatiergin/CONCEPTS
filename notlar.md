_C++20_ standardı ile dile eklenen _concept_'ler ve bunlara ilişkin araçlar ve standart kütüphane öğeleriyle şablonların _(templates)_ belirli türler ya da değerler için kullanımlarını kısıtlayabilir _(constrain)_ ve bunları kullanarak türden bağımsız _(generic)_ kodlarda derleme zamanında kod seçimi yaptırabiliriz.


#### concept'ler hangi faydaları sağlıyor?
- template kodları yazmayı, okumayı ve _debug_ etmeyi kolaylaştırıyor:  _TMP for everybody_
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

_Boolean_ ifadeler şunlardan biri olabilir:<br>
- tek başına bir derleme zamanı ifadesi _(ad hoc compile time expression)_
- bir _concept_
- bir _requires expression_

Tüm _constraintler_ bir _boolean_ ifadenin kullanılabildiği her yerde kullanılabilir.<br>
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

_&&_ ve _||_ operatörlerinin operandı olan derleme zamanı ifadelerinin parantez içine alınması gerekmez.
Ancak _ad hoc boolean_ ifadelerin parantez içine yazılması gerekir:

```cpp
requires sizeof(T) > 2 && sizeof(U) > 2  //geçersiz
requires (sizeof(T) > 2) && (sizeof(U) > 2) // geçerli
requires std::integral<T> && std::floating_point<U> //geçerli
```
aşağıdaki kodlarda geçerli _require clause_'lar için örnekler veriliyor:
```cpp
#include <type_traits>
#include <concepts>
#include <string>

template<typename T>
requires (sizeof(long long) > sizeof(long))

template<typename T>
requires (sizeof(T) > 1)

template<int N>
requires (N > 0)

template<typename T>
requires std::is_pointer_v<T> || std::is_same_v<T, std::nullptr_t>

template<typename T>
requires std::is_pointer_v<T> || std::same_as<T, std::nullptr_t>

template<typename T>
requires (!std::is_convertible_v<T, std::string>)

template<typename T>
requires (!std::convertible_to<T, std::string>)

template<typename T>
requires std::integral<std::remove_reference_t<decltype(*std::declval<T>())>>

template<typename T>
requires false 

```
#### requires expression
_template_'ler üzerinde gereklilikler _(requirements)_ başka bir yolu bir _requires expression_ oluşturmaktır. Bir _requires expression_ derleme zamanında ele alınan ve _bool_ türden değer oluşturan bir ifadedir. Böyle bir ifade, belirtilen gereklilikler karşılanırsa _true_ değeri aksi halde _false_ değeri üretir. 
Derleme zamanında _bool_ türden bir değer kullanılan herhangi bir yerde bir _requires expression_ kullanılabilir.
_requires expression_ bir _template_'den kod üretildiğinde _(template instantiation)_ ele alınır. 
Gövdesi _(body)_ boş olan bir _requires expression_ _true_ değeri üretir.

_requires expression_ _requires clause_'dan farklı yapılardır.
_requires expression_ bir ya da birden fazla template parametresinin kısıtlanması için basit ve esnek bir sentaks sağlar. _requires expression_ ile aşağıdaki belirlemeler yapılabilir:

- var/geçerli olması gereken türler _(nested types)_
- geçerli olması gereken ifadeler
- ifadelerin türleri
- ifadelerin yürütülmesi durumunda _exception_ gönderilmeme garantisi

Bir _requires expression_ _requires_ anahtar sözcüğü ile başlar. Bu anahtar sözcükten sonra opsiyonel bir parameter listesi bulunabilir. Daha sonra yer alan bir blok içinde gereklilikler ifade edilir. Her bir gereklilik noktalı virgül atomu ile sonlandırılır. Bir _requires expression_ içinde şunlardan biri bulunabilir:

##### simple requirements
Bir ifadenin geçerliliği sınanır. İfade geçerli değilse _requires expression_ _false_ değer üretir. Geçerliliği sınanan ifade yürütülmez _(unevaluated context)_.

##### type requirements
Belirtilen türün geçerliliği sınanır. Böyle bir tür mümkün değil ise _requires expression_ _false_ değer üretir.

##### compound requirements
Bir ifadenin sağlaması gereken niteliklerini belirler. 
- İfadenin türü
- ifadenin türünün sağlaması gereken özellikler
- ifadenin _noexcept_ olması 

##### nested requirements
_requires_ anahtar sözcüğü ile belirtilen koşullar

Aşağıdaki kodda tanımlanan _Nec concept_'inde bir _requires expression_ kullanılıyor:
```
#include <concepts>

template <typename T>
concept Nec = requires(T x)
{
    //simple requirements
    x == x;  // T türünden nesneler == operatörü ile karşılaştırılabilirler
    ++x; //T türünden nesneler önek arttırma operatörüne operand olabilirler
    
    //type requirement
    typename T::size_type;  // T türünün içsel _size_type_ isimli bir türü var
    
    // compound requirements
    { x * x } -> std::convertible_to<T>;      
    // x * x gecerli bir ifade ve ürettiği değer T türüne dönüştürlebilir 


    // nested requirements
    requires std::same_as<T, decltype(&x)>;  
	// adres operatörünün ürettiği değerin türü T* türü
};
```
#### conceptler nasıl ve nerelerde kullanılır?
bir concept bir require clause'un ifadesi ya da ifadelerinden biri olabilir:
```cpp
#include <concepts>

template <typename T>
requires std::integral<T>
void foo(T x)
{
	// ...
}
```
Yukarıdaki kodda _foo_ isimli fonksiyonu kısıtlayan _requires clause_'un ifadesi olarak standart bir _concept_ olan _std::integral_ kullanılıyor.

_concept_'ler _template_ tür parametresi yerine kullanılabilir:

```
#include <concepts>

template <std::integral T>
void foo(T x)
{
	// ...
}
```
 

#### standart concept'ler
Standart kütüphane hazır olarak kullanabileceğimiz birçok _concept_ sunmaktadır.  

**devam edecek...**

**kaynak: C++20 The Complete Guide by Nicholai Jossutis**

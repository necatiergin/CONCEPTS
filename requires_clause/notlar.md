Bir _requires clause_ _requires_ anahtar sözcüğü ve bir derleme zamanı_ boolean_ ifadeden oluşur. Nitelediği _template_'in kullanımını kısıtlar _(constrains)_<br>
Boolean ifade şunlardan biri olabilir:<br>
  • Tek başına bir derleme zamanı ifadesi
  • Bir _concept_
  • bir _requires expression_

Tüm _constraintler_ bir _boolean_ ifadenin kullanılabildiği  her yerde kullanılabilir.<br>
_Requires clause_'da birden fazla kısıtlamayı _(constraints)_ && operatörünü kullanarak kombine edebiliriz: 
```
template<typename T>
requires (sizeof(T) > 4) // ad-hoc Boolean expression
&& requires { typename T::value_type; } // requires expression
&& std::input_iterator<T> // concept

void foo(T x) {
//...
}
```

Kısıtlamaların sıralaması bir anlam farklılığı oluşturmaz.

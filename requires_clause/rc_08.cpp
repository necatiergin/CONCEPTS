template <typename T>
requires requires(T x)		//valid syntax  requires clause + requires expression
{
    x + x;
} 
T foo(T x) 
{
}

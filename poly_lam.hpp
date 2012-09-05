namespace poly_lam {
template <typename X> struct get_the_return_type;
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)                > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const          > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)       volatile > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const volatile > { typedef Ret return_type; };

template <typename T0, typename T1>
struct poly_lam_struct {
	typedef typeof( [](T0 x,T1 y){ return x+y;} ) lambda_type;
	typedef decltype( &lambda_type :: operator())  fptr_t;
	typedef get_the_return_type<fptr_t> x;
	typedef typename get_the_return_type<fptr_t> :: return_type return_type;
	static return_type execute(T0 t0, T1 t1) {
		static lambda_type * const l_ptr = nullptr;
		return (*l_ptr)(t0, t1);
	}
};

template <typename T0, typename T1>
auto pol(T0 t0, T1 t1) -> typename poly_lam_struct<T0,T1> :: return_type
{
	return poly_lam_struct<T0,T1> :: execute(t0, t1);
}
}

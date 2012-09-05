namespace poly_lam {
template <typename X> struct get_the_return_type;
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)                > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const          > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)       volatile > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const volatile > { typedef Ret return_type; };

#define POLY_LAM_FIRST( name, t0, t1, lambda_text )  \
	template <typename T0, typename T1> \
	struct just_the_lambda_itself_ ## name { \
		typedef typeof( [](T0 x,T1 y){ return x+y;} ) lambda_type; \
	}; \
	template <typename T0, typename T1> \
	auto name(T0 t0, T1 t1) -> typename all_the_other_details<T0,T1, just_the_lambda_itself_ ## name<T0,T1> > :: return_type \
	{ \
		return all_the_other_details<T0,T1, just_the_lambda_itself_ ## name<T0,T1> > :: execute(t0, t1); \
	} \
	struct dummy_struct_to_take_the_semicolon ## name {}

template <typename T0, typename T1>
struct just_the_lambda_itself {
	typedef typeof( [](T0 x,T1 y){ return x+y;} ) lambda_type;
};

template <typename T0, typename T1, typename TheLambdaType >
struct all_the_other_details {
	typedef typename TheLambdaType :: lambda_type lambda_type;
	typedef decltype( &lambda_type :: operator())  fptr_t;
	typedef get_the_return_type<fptr_t> x;
	typedef typename get_the_return_type<fptr_t> :: return_type return_type;
	static return_type execute(T0 t0, T1 t1) {
		static lambda_type * const l_ptr = nullptr;
		return (*l_ptr)(t0, t1);
	}
};

}

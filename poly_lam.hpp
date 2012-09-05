namespace poly_lam {
template <typename X> struct get_the_return_type;
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)                > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const          > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...)       volatile > { typedef Ret return_type; };
template <typename Ret, typename Class, typename ...Args> struct get_the_return_type< Ret (Class::*) (Args...) const volatile > { typedef Ret return_type; };


template <typename T0, typename T1, typename TheLambdaType >
struct all_the_other_details {
	typedef typename TheLambdaType :: lambda_type lambda_type;
	typedef decltype( &lambda_type :: operator())  fptr_t;
	typedef get_the_return_type<fptr_t> x;
	typedef typename get_the_return_type<fptr_t> :: return_type return_type;
	template<typename TT0, typename TT1> // for perfect forwarding
	static return_type execute(TT0 && t0, TT1 && t1) {
		static lambda_type * const l_ptr = nullptr;
		return (*l_ptr)( std :: forward<TT0>(t0), std :: forward<TT1>(t1) );
	}
};

} // namespace poly_lam

#define POLY_LAM_FIRST( name, t0, t1, lambda_text )  \
	namespace poly_lam_details { \
	template <typename T0, typename T1> \
	struct just_the_lambda_itself_ ## name { \
		typedef typeof( [](const T0 & t0,const T1 & t1) { cout << "in the lambda" << endl; lambda_text } ) lambda_type; \
	}; \
	} /* namespace poly_lam_details */ \
	template <typename T0, typename T1> \
	static auto name(T0 && t0, T1 && t1) -> typename poly_lam :: all_the_other_details<T0,T1,  poly_lam_details ::just_the_lambda_itself_ ## name<T0,T1> > :: return_type \
	{ \
		return  poly_lam ::all_the_other_details<T0,T1,  poly_lam_details ::just_the_lambda_itself_ ## name<T0,T1> > :: execute(std::forward<T0>(t0), std::forward<T1>(t1)); \
	} \
	struct dummy_struct_to_take_the_semicolon ## name {}

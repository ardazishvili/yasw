#ifndef YASW_MISC_H
#define YASW_MISC_H

#include <iostream>

template <class T>
constexpr std::string_view type_name()
{
    using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}


template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_index(int, const std::tuple<Tp...> &, FuncT)
{ }

template<std::size_t I = 0, typename FuncT, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_index(int index, const std::tuple<Tp...>& t, FuncT f)
{
    if (index == 0) f(std::get<I>(t));
    for_index<I + 1, FuncT, Tp...>(index-1, t, f);
}


template <typename T> struct extract_args {};

template <template <typename> typename Pack, typename T>
struct extract_args<Pack<T>> {
    using type = typename T::element_type;
};

#endif //YASW_MISC_H

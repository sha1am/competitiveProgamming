#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <ostream>

#ifndef _MSC_VER
#  if __cplusplus < 201103
#    define constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN
#  elif __cplusplus < 201402
#    define constexpr constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN noexcept
#  else
#    define constexpr constexpr
#    define CONSTEXPR14_TN constexpr
#    define NOEXCEPT_TN noexcept
#  endif
#else  // _MSC_VER
#  if _MSC_VER < 1900
#    define constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN
#  elif _MSC_VER < 2000
#    define constexpr constexpr
#    define CONSTEXPR14_TN
#    define NOEXCEPT_TN noexcept
#  else
#    define constexpr constexpr
#    define CONSTEXPR14_TN constexpr
#    define NOEXCEPT_TN noexcept
#  endif
#endif  // _MSC_VER

class string_view1 {
    const char* const p_;
    const std::size_t sz_;

public:
    typedef const char* const_iterator;

    template <std::size_t N>
    constexpr string_view1(const char(&a)[N]) NOEXCEPT_TN
: p_(a)
    , sz_(N-1)
    {}

    constexpr string_view1(const char* p, std::size_t N) NOEXCEPT_TN
: p_(p)
    , sz_(N)
    {}

    constexpr const char* data() const NOEXCEPT_TN {return p_;}
    constexpr std::size_t size() const NOEXCEPT_TN {return sz_;}

    constexpr const_iterator begin() const NOEXCEPT_TN {return p_;}
    constexpr const_iterator end()   const NOEXCEPT_TN {return p_ + sz_;}

    constexpr char operator[](std::size_t n) const {
        return n < sz_ ? p_[n] : throw std::out_of_range(" string_view1");
    }
};

inline
std::ostream&
operator<<(std::ostream& os, string_view1 const& s) {
    return os.write(s.data(), s.size());
}

// template <class T>
// CONSTEXPR14_TN
// string_view1
// type_name()
// {
// #ifdef __clang__
//     string_view1 p = __PRETTY_FUNCTION__;
//     return string_view1(p.data() + 31, p.size() - 31 - 1);
// #elif defined(__GNUC__)
//     string_view1 p = __PRETTY_FUNCTION__;
// #  if __cplusplus < 201402
//     return string_view1(p.data() + 36, p.size() - 36 - 1);
// #  else
//     return string_view1(p.data() + 46, p.size() - 46 - 1);
// #  endif
// #elif defined(_MSC_VER)
//     string_view1 p = __FUNCSIG__;
//     return string_view1(p.data() + 38, p.size() - 38 - 7);
// #endif
// }


template <class T>
constexpr
string_view1
type_name() {
//using namespace std;
#ifdef __clang__
    string_view1 p = __PRETTY_FUNCTION__;
    return string_view1(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view1 p = __PRETTY_FUNCTION__;
#if __cplusplus < 201402
    return string_view1(p.data() + 36, p.size() - 36 - 1);
#else
    return string_view1(p.data() + 49, p.find(';', 49) - 49);
#endif
#elif defined(_MSC_VER)
    string_view1 p = __FUNCSIG__;
    return string_view1(p.data() + 84, p.size() - 84 - 7);
#endif
}
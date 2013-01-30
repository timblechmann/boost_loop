// boost loop
//
// Copyright (C) 2013 Tim Blechmann
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_LOOP_HPP
#define BOOST_LOOP_HPP

#include <boost/type_traits/is_integral.hpp>
#include <boost/static_assert.hpp>

namespace boost       {
namespace loop_detail {

template<typename T, typename IntType>
inline void run_object(T const & t, void (T::*func)() const, IntType)
{
    (t.*func)();
}

template<typename T, typename IntType>
inline void run_object(T & t, void (T::*func)(), IntType)
{
    (t.*func)();
}

template<typename T, typename IntType>
inline void run_object(T const & t, void (T::*func)(IntType) const, IntType x)
{
    (t.*func)(x);
}


template<typename T, typename IntType>
inline void run_object(T & t, void (T::*func)(IntType), IntType x)
{
    (t.*func)(x);
}

template<typename T, typename IntType>
inline void run_object(T & t, IntType x)
{
    run_object(t, &T::operator(), x);
}

template<typename IntType>
inline void run_object(void (*t)(IntType), IntType i)
{
    (*t)(i);
}

template<typename IntType>
inline void run_object(void (*t)(), IntType)
{
    (*t)();
}

} /* namespace loop_detail */

template <typename IntType, typename Functor>
inline void loop(IntType loop_count, Functor & f)
{
    BOOST_STATIC_ASSERT(boost::is_integral<IntType>::value);

    for (IntType i = 0; i != loop_count; ++i)
        loop_detail::run_object(f, i);
}

template <typename IntType, typename Functor>
inline void loop(IntType loop_count, Functor const & f)
{
    BOOST_STATIC_ASSERT(boost::is_integral<IntType>::value);

    for (IntType i = 0; i != loop_count; ++i)
        loop_detail::run_object(f, i);
}


} /* namespace boost */

#endif /* BOOST_LOOP_HPP */

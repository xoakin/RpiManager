/*
 * Utils.hpp
 *
 *  Created on: Jul 4, 2017
 *      Author: joaquin
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_


template<typename F, typename... Ts>
inline
auto
reallyAsync(F&& f, Ts&&... params)
{
	return std::async(std::launch::async,
	std::forward<F>(f),
	std::forward<Ts>(params)...);
}


#endif /* UTILS_HPP_ */

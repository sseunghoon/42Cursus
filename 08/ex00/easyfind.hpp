#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>

class ElementNotFound: public std::exception {
public:
	const char* what() const throw() {
		return "Element not found";
	}
};

template<typename T>
typename T::iterator easyfind(T& container, int val) {
    typename T::iterator iter = std::find(container.begin(), container.end(), val);
    if (iter == container.end())
        throw ElementNotFound();
    return iter;
}

template<typename T>
typename T::iterator easyfind(const T& container, int val) {
    typename T::iterator iter = std::find(container.begin(), container.end(), val);
    if (iter == container.end())
        throw ElementNotFound();
    return iter;
}

#endif

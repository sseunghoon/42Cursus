/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:25 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/23 13:49:59 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fractional_bits = 8;
		
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator = (const Fixed& fixed);
		
		bool operator > (const Fixed& fixed) const;
		bool operator < (const Fixed& fixed) const;
		bool operator >= (const Fixed& fixed) const;
		bool operator <= (const Fixed& fixed) const;
		bool operator == (const Fixed& fixed) const;
		bool operator != (const Fixed& fixed) const;

		Fixed operator + (const Fixed& fixed);
		Fixed operator - (const Fixed& fixed);
		Fixed operator * (const Fixed& fixed);
		Fixed operator / (const Fixed& fixed);

		Fixed& operator ++ ();
		Fixed operator ++ (int);
		Fixed& operator -- ();
		Fixed operator -- (int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed& min(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
		static Fixed& max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);
};

std::ostream& operator << (std::ostream &out, const Fixed &fixed);

#endif
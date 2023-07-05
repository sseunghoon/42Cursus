/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/23 14:00:55 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->fractional_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->fractional_bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed& fixed) const {
	return (value > fixed.value);
}

bool Fixed::operator < (const Fixed& fixed) const {
	return (value < fixed.value);
}

bool Fixed::operator >= (const Fixed& fixed) const {
	return (value >= fixed.value);
}

bool Fixed::operator <= (const Fixed& fixed) const {
	return (value <= fixed.value);
}

bool Fixed::operator == (const Fixed& fixed) const {
	return (value == fixed.value);
}

bool Fixed::operator != (const Fixed& fixed) const {
	return (value != fixed.value);
}

Fixed Fixed::operator + (const Fixed& fixed) {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator - (const Fixed& fixed) {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator * (const Fixed& fixed) {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator / (const Fixed& fixed) {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator ++ () {
	this->value += 1;
	return *this;
}

Fixed Fixed::operator ++ (int) {
	Fixed tmp(*this);

	this->value += 1;

	return tmp;
}

Fixed& Fixed::operator -- () {
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator -- (int) {
	Fixed tmp(*this);

	this->value -= 1;

	return tmp;
}

int Fixed::getRawBits(void) const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return this->value / (float)(1 << this->fractional_bits);
}

int Fixed::toInt(void) const {
	return this->value / (1 << this->fractional_bits);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 < fixed2) {
		return fixed1;
	} else {
		return fixed2;
	}
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 < fixed2) {
		return fixed1;
	} else {
		return fixed2;
	}
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
	if (fixed1 > fixed2) {
		return fixed1;
	} else {
		return fixed2;
	}
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
	if (fixed1 > fixed2) {
		return fixed1;
	} else {
		return fixed2;
	}
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 12:36:33 by songseunghu       #+#    #+#             */
/*   Updated: 2023/06/22 16:53:43 by songseunghu      ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator > (const Fixed& fixed) {
	return (value > fixed.value);
}

bool Fixed::operator < (const Fixed& fixed) {
	return (value > fixed.value);
}

bool Fixed::operator >= (const Fixed& fixed) {
	return (value >= fixed.value);
}

bool Fixed::operator == (const Fixed& fixed) {
	return (value == fixed.value);
}

bool Fixed::operator != (const Fixed& fixed) {
	return (value != fixed.value);
}

Fixed &Fixed::operator + (const Fixed& fixed) {
	Fixed new_fixed;
	new_fixed.value = value + fixed.value;
	
	return (new_fixed);
}

Fixed &Fixed::operator - (const Fixed& fixed) {
	Fixed new_fixed;
	new_fixed.value = value - fixed.value;
	
	return (new_fixed);
}

Fixed &Fixed::operator * (const Fixed& fixed) {
	Fixed new_fixed;
	new_fixed.value = value * fixed.value;
	
	return (new_fixed);
}

Fixed &Fixed::operator / (const Fixed& fixed) {
	Fixed new_fixed;
	new_fixed.value = value / fixed.value;
	
	return (new_fixed);
}

Fixed &Fixed::operator ++ (const Fixed& fixed) {
	return (new_fixed.value++);
}

Fixed &Fixed::operator -- (const Fixed& fixed) {
	return (new_fixed.value++);
}

int Fixed::getRawBits(void) const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat(void) const {
	return this->value / (float)(1 << this->fractional_bits);
}

int Fixed::toInt(void) const {
	return this->value >> this->fractional_bits;
}
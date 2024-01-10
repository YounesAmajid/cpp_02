/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:47:49 by yamajid           #+#    #+#             */
/*   Updated: 2024/01/09 21:14:11 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedValue(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i_number){
    std::cout << "Int constructor called" << std::endl;
    fixedValue = i_number << fractionalBits;
}

Fixed::Fixed(const float f_number){
    std::cout << "Float constructor called" << std::endl;
    fixedValue = roundf(f_number * (1 << fractionalBits));
}
 
Fixed::Fixed(const Fixed& other): fixedValue(other.fixedValue){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other){
    std::cout <<"Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedValue = other.fixedValue;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
    os <<  obj.toFloat() << std::endl;
    return os;
}

float   Fixed::toFloat(void) const{
    return static_cast<float>(fixedValue) / (1 << fractionalBits);
}

int     Fixed::toInt(void) const{
   return fixedValue >> fractionalBits;
}

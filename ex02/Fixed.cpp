/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:04:49 by yamajid           #+#    #+#             */
/*   Updated: 2024/01/10 11:55:28 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed(): fixedValue(0){
}

Fixed::Fixed(const int i_number){
    fixedValue = i_number << fractionalBits;
}

Fixed::Fixed(int i_number, int j){
    (void)j;
    fixedValue = i_number;
}

Fixed::Fixed(const float f_number){
    fixedValue = roundf(f_number * (1 << fractionalBits));
}
 
Fixed::Fixed(const Fixed& other): fixedValue(other.fixedValue){
}

Fixed::~Fixed(){
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj){
    os <<  obj.toFloat() << std::endl;
    return os;
}

int Fixed::getRawBits(void) const{
    return (fixedValue);
}

Fixed& Fixed::operator=(const Fixed& other){
    if (this != &other)
        fixedValue = other.fixedValue;
    return *this;
}

bool   Fixed::operator==(const Fixed& obj){
    if (fixedValue == obj.fixedValue)
        return true;
    return false;
}

bool   Fixed::operator!=(const Fixed& obj){
    if (fixedValue != obj.fixedValue)
        return true;
    return false;
}

bool   Fixed::operator>=(const Fixed& obj){
    if (fixedValue >= obj.fixedValue)
        return true;
    return false;
}

bool   Fixed::operator<=(const Fixed& obj){
    if (fixedValue <= obj.fixedValue)
        return true;
    return false;
}

bool   Fixed::operator<(const Fixed& obj){
    if (fixedValue < obj.fixedValue)
        return true;
    return false;
}

bool   Fixed::operator>(const Fixed& obj){
    if (fixedValue > obj.fixedValue)
        return true;
    return false;
}

Fixed Fixed::operator+(const Fixed& obj){
    Fixed tmp(this->fixedValue + obj.fixedValue, 0);
    return tmp;
}

Fixed Fixed::operator-(const Fixed& obj){
    Fixed tmp(this->fixedValue - obj.fixedValue, 0);
    return tmp;
}

Fixed Fixed::operator*(const Fixed& obj){
    Fixed tmp(this->fixedValue * obj.fixedValue, 0);
    tmp.fixedValue = tmp.fixedValue >> fractionalBits;
    return tmp;
}

Fixed Fixed::operator/(const Fixed& obj){
    Fixed tmp(this->fixedValue / obj.fixedValue, 0);
    tmp.fixedValue = tmp.fixedValue << fractionalBits;
    return tmp;
}

Fixed&  Fixed::min(Fixed& f1, Fixed& f2){
    if (f1.fixedValue < f2.fixedValue)
        return f1;
    return f2;
}

const Fixed&  Fixed::min(const Fixed& f1, const Fixed& f2){
    if (f1.fixedValue < f2.fixedValue)
        return f1;
    return f2;
}

Fixed&  Fixed::max(Fixed& f1, Fixed& f2){
    if (f1.fixedValue > f2.fixedValue)
        return f1;
    return f2;
}

const Fixed&  Fixed::max(const Fixed& f1, const Fixed& f2){
    if (f1.fixedValue > f2.fixedValue)
        return f1;
    return f2;
}

Fixed& Fixed::operator++(){
        fixedValue++;
    return *this;
}

Fixed& Fixed::operator--(){
        fixedValue--;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    fixedValue++;
    return temp;
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    fixedValue--;
    return temp;
}

float   Fixed::toFloat(void) const{
    return static_cast<float>(fixedValue) / (1 << fractionalBits);
}

int     Fixed::toInt(void) const{
   return fixedValue >> fractionalBits;
}


void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixedValue = raw;
}
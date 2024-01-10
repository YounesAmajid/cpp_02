/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:04:55 by yamajid           #+#    #+#             */
/*   Updated: 2024/01/10 11:25:35 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
    private:
        int fixedValue;
        static const int fractionalBits;

    public:
        ~Fixed();
        Fixed();
        Fixed(const int i_number);
        Fixed(const float f_number);
        Fixed(const int i_number, int j);
        Fixed(const Fixed& other);
        bool                    operator==(const Fixed& obj);
        bool                    operator!=(const Fixed& obj);
        bool                    operator>(const Fixed& obj);
        bool                    operator<(const Fixed& obj);
        bool                    operator>=(const Fixed& obj);
        Fixed&                  operator=(const Fixed& obj);
        bool                    operator<=(const Fixed& obj);
        Fixed                   operator+(const Fixed& obj);
        Fixed                   operator-(const Fixed& obj);
        Fixed                   operator*(const Fixed& obj);
        Fixed                   operator/(const Fixed& obj);
        Fixed&                  operator++();
        Fixed&                  operator--();
        Fixed                   operator++(int);
        Fixed                   operator--(int);
        float                   toFloat(void) const;
        int                     toInt(void) const;
        void                    setRawBits(int const raw);
        int                     getRawBits() const;
        static Fixed&           min(Fixed& f1, Fixed& f2); 
        static Fixed&           max(Fixed& f1, Fixed& f2); 
        static const Fixed&     min(const Fixed& f1, const Fixed& f2); 
        static const Fixed&     max(const Fixed& f1, const Fixed& f2);
};
std::ostream&   operator<<(std::ostream& os, const Fixed& obj);
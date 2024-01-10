/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamajid <yamajid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:48:00 by yamajid           #+#    #+#             */
/*   Updated: 2024/01/09 15:11:53 by yamajid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
    private:
        int fixedValue;
        static const int fractionalBits;
    public:
        Fixed();
        Fixed(const int i_number);
        Fixed(const float f_number);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed&          operator=(const Fixed& other);
        float           toFloat(void) const;
        int             toInt(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Fixed& obj);
#ifndef FIXEDPOINTNUMBER_H_
#define FIXEDPOINTNUMBER_H_

#include <stdint.h>

class FixedPointNumber 
{
	public:
		// fractional_bit_count must be 0 ... 15
		// integer_bit_count = 16 - fractional_bit_count - 1
		FixedPointNumber(const int& value, const int& fractional_bit_count);
		FixedPointNumber(FixedPointNumber * n);
		FixedPointNumber();
		int to_int();
		FixedPointNumber operator+(const FixedPointNumber& addend_right);
		FixedPointNumber operator-(const FixedPointNumber& subtrahend);
		FixedPointNumber operator*(const FixedPointNumber& factor_right);
		FixedPointNumber operator/(const FixedPointNumber& divisor);
	private:
		int16_t value_representation;
		uint8_t integer_bit_count;
		uint8_t fractional_bit_count;

};

#endif

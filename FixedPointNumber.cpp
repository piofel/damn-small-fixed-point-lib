#include "FixedPointNumber.h"

FixedPointNumber::FixedPointNumber(const int& value, const int& fractional_bit_count) 
{
       	this->fractional_bit_count = (uint8_t) fractional_bit_count;
	this->integer_bit_count = (uint8_t) (16 - fractional_bit_count - 1);
	value_representation = (int16_t) (value << fractional_bit_count);
}

FixedPointNumber::FixedPointNumber(FixedPointNumber * n)
{
	value_representation = n->value_representation;
	integer_bit_count = n->integer_bit_count;
	fractional_bit_count = n->fractional_bit_count;
}

FixedPointNumber::FixedPointNumber()
{
}

int FixedPointNumber::to_int()
{
	int16_t v = value_representation >> (fractional_bit_count - 1);
	int16_t half = v & (int16_t) 1;
	v >>= 1;
	return (int) (v + half);
}


FixedPointNumber FixedPointNumber::operator+(const FixedPointNumber& addend_right)
{
	FixedPointNumber result = FixedPointNumber(this);	
	result.value_representation += addend_right.value_representation;
	return result;
}

FixedPointNumber FixedPointNumber::operator-(const FixedPointNumber& subtrahend)
{
	FixedPointNumber result = FixedPointNumber(this);	
	result.value_representation -= subtrahend.value_representation;
	return result;
}

FixedPointNumber FixedPointNumber::operator*(const FixedPointNumber& factor_right)
{
	FixedPointNumber result = FixedPointNumber(this);	
	int32_t r = (int32_t) result.value_representation;
	int32_t frv = (int32_t) factor_right.value_representation;
	r *= frv;
	r >>= fractional_bit_count;
	result.value_representation = (int16_t) r;
	return result;
}

FixedPointNumber FixedPointNumber::operator/(const FixedPointNumber& divisor)
{
	FixedPointNumber result = FixedPointNumber(this);	
	int32_t r = (int32_t) result.value_representation;
	r <<= fractional_bit_count;
	int32_t dv = (int32_t) divisor.value_representation;
	r /= dv;
	result.value_representation =  (int16_t) r;
	return result;
}

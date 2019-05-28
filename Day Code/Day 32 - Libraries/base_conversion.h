#pragma once
#include <iostream>

class base_conversion
{
public:
	/*	@brief Converts string of 1's and 0's to integer
		@param The null terminated string to convert
		@return The integer value of the converted string
	*/
	static int binary_string_to_integer(const char* a_binary_string);
	
	/*	@brief Converts string of 1's and 0's to integer
		@param The destination char*
		@param The integer to convert
		@note the char* should be sizeof(int) + 1 bytes long
	*/
	static void interger_to_binary_string(char* a_binary_string, int value);

	/*	@brief Sets the bits at the given index ot the passed state
		@param The bitfield to edit by reference
		@param The index of the bit to change
		@param The desired state of the bit at the index
	*/
	static void set_bit(int& a_bit_field, char a_bit_index, bool a_state);

	/*	@brief Reads the state of the bit at an index from a given bitfield
		@param The bitfield, read only, to check
		@param The index of the bit to check
		@return The current state of the bit at the index
	*/
	static bool get_bit(const int a_bit_field, int a_bit_index);

	/*	@brief Dumps the bianry of the given int to iostream
		@param The ineger to display, bitwise
	*/
	static void print_int_as_binary(const int a_bit_field, bool a_spaced);
};


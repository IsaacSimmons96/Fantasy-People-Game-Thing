#include "pch.h"
#include "..\headers\dice_functions.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "..\Headers\typedefs.h"
#include <signal.h>

//-----------------------------------------------------------------------------------------------------
// returns a number that is generated using the dice supplied, number of rolls and the bonus added.
//-----------------------------------------------------------------------------------------------------
uint16_t roll_dice(DND_DICE dice, uint16_t number_of_rolls /*= 1*/, uint16_t add_bonus_to_roll /*= 0*/)
{
	if (dice == DND_DICE::FLAT_1)
	{
		return 1 + number_of_rolls + add_bonus_to_roll;
	}
	else if (dice == DND_DICE::NONE, dice == DND_DICE::INVALID)
	{
		return 0;
	}

	// HARRY
	// This is called a "Conditional (or Ternary) Operator" its basically like an If statement but on one line?
	// Below we ask the question "is the dice a PERCENTILE dice?" the first value is true result, the second is the false
	// So if it is a PERCENTILE dice, then its true and we return 10, if its not, then its false and we get the maximum roll for the dice type
	const uint8_t maximum_roll = dice == DND_DICE::PERCENTILE ? 10 : get_max_roll_for_dice(dice);
	const uint8_t minimum_roll = 1;
	uint16_t total_roll_result = 0;
	
	for (int i = 0; i != number_of_rolls; ++i)
	{
		uint8_t temp = rand() % maximum_roll + minimum_roll;

		if (dice == DND_DICE::PERCENTILE)
		{
			temp = temp * 10;
		}

		total_roll_result += temp;
	}

	return total_roll_result + add_bonus_to_roll;
}

//-----------------------------------------------------------------------------------------------------
// returns a string value for the dice parameter so a D20 would return a string saying "D20"
//-----------------------------------------------------------------------------------------------------
string get_string_from_DND_DICE(DND_DICE dice)
{
	string string_out = "INVALID";
	switch (dice)
	{
	case DND_DICE::D4:
		string_out = "D4";
		break;
	case DND_DICE::D6:
		string_out = "D6";
		break;
	case DND_DICE::D8:
		string_out = "D8";
		break;
	case DND_DICE::D10:
		string_out = "D10";
		break;
	case DND_DICE::D12:
		string_out = "D12";
		break;
	case DND_DICE::D20:
		string_out = "D20";
		break;
	case DND_DICE::PERCENTILE:
		string_out = "PERCENTILE";
		break;
	case DND_DICE::FLAT_1:
		string_out = "1";
		break;
	case DND_DICE::NONE:
		string_out = "None";
		break;
	default:
		break;
	}
	return string_out;
}

//-----------------------------------------------------------------------------------------------------
// returns the maximum roll for the dice supplied! example a d20s max roll is 20.
//-----------------------------------------------------------------------------------------------------
uint8_t get_max_roll_for_dice( DND_DICE dice )
{
	switch ( dice )
	{
	case DND_DICE::D4:
		return 4;
		break;
	case DND_DICE::D6:
		return 6;
		break;
	case DND_DICE::D8:
		return 8;
		break;
	case DND_DICE::D10:
		return 10;
		break;
	case DND_DICE::D12:
		return 12;
		break;
	case DND_DICE::D20:
		return 20;
		break;
	case DND_DICE::PERCENTILE:
		return 100;
		break;
	case DND_DICE::FLAT_1:
		return 1;
		break;
	case DND_DICE::NONE:
		return 0;
		break;
	}
	return 0;
}
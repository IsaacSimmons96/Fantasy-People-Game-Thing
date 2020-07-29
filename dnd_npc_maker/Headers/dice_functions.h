#pragma once
#include "typedefs.h"

enum class DND_DICE : char
{
	D4,
	D6,
	D8,
	D10,
	D12,
	D20,
	PERCENTILE,
	FLAT_1,
	NONE,
	INVALID
};

string get_string_from_DND_DICE( DND_DICE dice );

uint16_t roll_dice( DND_DICE dice, uint16_t number_of_rolls = 1, uint16_t add_bonus_to_roll = 0 );
uint8_t get_max_roll_for_dice( DND_DICE dice );
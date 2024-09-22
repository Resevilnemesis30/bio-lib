/*
*
*	Megan Grass
*	March 07, 2024
*
*
*	TODO:
*
*/


#include "bio_common.h"


/*
	Get Stage and Room from string
*/
void Resident_Evil_Common::GetStageRoom(std::string Str) try
{
	if (std::to_underlying(Game) & (BIO3))
	{
		Stage = std::stoi(Str.substr(1, 1), nullptr, 16);
		Room = std::stoi(Str.substr(2, 2), nullptr, 16);
		Player = 0;
	}
	else
	{
		Stage = std::stoi(Str.substr(4, 1), nullptr, 16);
		Room = std::stoi(Str.substr(5, 2), nullptr, 16);
		Player = std::stoi(Str.substr(7, 1), nullptr, 16);
	}
}
catch (...) { Stage = 0, Room = 0; Player = 0; }
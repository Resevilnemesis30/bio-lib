/*
*
*	Megan Grass
*	April 20, 2024
*
*
*	TODO:
*
*/


#pragma once

#include <lib_gte.h>

#include <std_basic_fstream.h>

#include <std_text.h>


enum class Resident_Evil_2_Collision_Shape : std::uint8_t
{
	Box,								// Square or Rectangle
	Naname_a,							// Oblique Triangle			// \| SouthEast
	Naname_b,							// Oblique Triangle			// |/ SouthWest
	Naname_c,							// Oblique Triangle			// /| NorthWest
	Naname_d,							// Oblique Triangle			// |\ NorthEast
	Hishi,								// Rhombus
	Circle,								// Circle
	Koban_x,							// Oblong Oval Circle		// X-Axis
	Koban_z,							// Oblong Oval Circle		// Z-Axis
	Box_1,								// Square or Rectangle		// Special Function: Climb Up
	Box_2,								// Square or Rectangle		// Special Function: Jump Down
	Slope,								// Oblique Triangle			// Special Function: Walkway Slope
	Box_3,								// Square or Rectangle		// Special Function: Stairs
	Curve								// Curve (Sewer pipe, found in 40B and 40F)
};


#pragma pack(push, 1)


struct Resident_Evil_2_SCA_Header
{
	std::int16_t Cx;					// Axis Center Point - Used to generate "Area" bitfield of "Type" variable
	std::int16_t Cz;					// Axis Center Point - Used to generate "Area" bitfield of "Type" variable
	std::uint32_t nData;				// Collision Amount (-1 for actual amount)
	std::int32_t Ceiling;				// Ceiling height for entire room (* -1800 for actual height)
	std::uint32_t Color;				// RGB color of collision; unused, probably dev leftovers
};


struct Resident_Evil_2_SCA_Data
{
	std::int16_t X;
	std::int16_t Z;
	std::uint16_t W;
	std::uint16_t D;
	union Id
	{
		std::uint16_t Data;				// Contiguous
		struct Bits						// Bitfield
		{
			std::uint16_t Shape : 4;	// 0	// Box			// Square/Rectangle
										// 1	// Naname_a		// Oblique Triangle			// \|
										// 2	// Naname_b		// Oblique Triangle			// |/
										// 3	// Naname_c		// Oblique Triangle			// /|
										// 4	// Naname_d		// Oblique Triangle			// |\
										// 5	// Hishi		// Rhombus
										// 6	// Circle		// Circle
										// 7	// Koban_x		// Oblong Oval Circle		// X-Axis
										// 8	// Koban_z		// Oblong Oval Circle		// Z-Axis
										// 9	// Box_1		// Square or Rectangle		// Special Function: Climb Up
										// 10	// Box_2		// Square or Rectangle		// Special Function: Jump Down
										// 11	// Slope		// Oblique Triangle			// Special Function: Walkway Slope
										// 12	// Box_3		// Square or Rectangle		// Special Function: Stairs
										// 13	// Curve		// Sewer pipe, found in 40B and 40F
			std::uint16_t bit0 : 4;		// 0x00 = Weapon Collision OFF (Desk, etc)
										// 0x08 = Weapon Collision ON (Wall, etc)
			std::uint16_t bit1 : 1;		// 0x00 = nFloor Height OFF (Cannot Walk Under)
										// 0x01 = nFloor Height ON (Can Walk Under)
			std::uint16_t bit2 : 1;		// 0x00 = 
										// 0x01 = 
			std::uint16_t bit3 : 1;		// 0x00 = Enemy Collision OFF
										// 0x01 = Enemy Collision ON
			std::uint16_t bit4 : 1;		// 0x00 = 
										// 0x01 = 
			std::uint16_t bit5 : 1;		// 0x00 = 
										// 0x01 = 
			std::uint16_t bit6 : 1;		// 0x00 = Bullet Collision OFF
										// 0x01 = Bullet Collision ON
			std::uint16_t bit7 : 1;		// 0x00 = Object Collision OFF
										// 0x01 = Object Collision ON
			std::uint16_t bit8 : 1;		// 0x00 = Player Collision OFF
										// 0x01 = Player Collision ON
		} Bits;
	} Id;
	union Type
	{
		std::uint16_t Data;				// Contiguous
		struct Bits						// Bitfield
		{
			std::uint16_t Area : 4;		// Axis Quadrant(s)
										// Determine axis quadrants for the collision
										//
										// Axis quadrant values, where "Cx" and "Cz" is the center point:
										//
										//		2 | 1
										//		-----
										//		8 | 4
										//
										// Formula to calculate this value:
										//		ULONG Sca_get_area(LONG X, LONG Z, LONG Sx, LONG Sz)
										//		{
										//			return (1 << ((UINT)(X - Sx) >> 0x1f)) << ((UINT)(Z - Sz) >> 0x1e & 2);
										//		}
										//		ULONG Area0 = Sca_get_area((X - 1800), (Z - 1800), Header->Cx, Header->Cz);
										//		ULONG Area1 = Sca_get_area((X + (W + 1800)), (Z - 1800), Header->Cx, Header->Cz);
										//		ULONG Area2 = Sca_get_area((X - 1800), (Z + (D + 1800)), Header->Cx, Header->Cz);
										//		ULONG Area4 = Sca_get_area((X + (W + 1800)), (Z + (D + 1800)), Header->Cx, Header->Cz);
										//		Area = (Area0 | Area1 | Area2 | Area3);

			std::uint16_t StairWD : 1;	// Stair & Slope Low/High
										// Determines where the High and Low points are located for the "Stair" and "Slope" shape types
										// Ignored when shape type is not either "Stair" or "Slope"
										// 
										// 00	// if StairXZ = 0 (X-Axis)
													// High = EAST (X)
													// Low = WEST (X+W)
												// if StairXZ = 1 (Z-Axis)
													// High = SOUTH (Z)
													// Low = NORTH (Z+D)
										// 
										// 01	// if StairXZ = 0 (X-Axis)
													// High = WEST (X+W)
													// Low = EAST (X)
												// if StairXZ = 1 (Z-Axis)
													// High = NORTH (Z+D)
													// Low = SOUTH (Z)

			std::uint16_t StairXZ : 1;	// Stair & Slope Axis
										// Determines if "Stair" and "Slope" shape types are accessible from either the X or Z axis
										// Ignored when shape type is not either "Stair" or "Slope"
										// 00 = X-Axis
										// 01 = Z-Axis

			std::uint16_t nFloor : 6;	// Height in units of -1800
										// Accepted values are 0-31 (Range: 0, -57600)
										// Used by the Sca_get_high function to obtain height of collision
										// Ignored when shape type is "Slope" (height is always -1800, hardcoded in executable)
										// Actual Height = ((Height * -200) + (nFloor * -1800));
										// This value is irregular in ROOM104:
										//		 Wrecked Vehicles (Value: 33)

			std::uint16_t Height : 4;	// Height in units of -200
										// Accepted values are 0-15 (Range: 0, -3000)
										// Used by the Sca_get_high function to obtain height of collision
										// Ignored when shape type is "Slope" (height is always -1800, hardcoded in executable)
										// This value is normally set to 9 by default to ensure the height is at least -1800
										// This value is irregular in ROOM104:
										//		 Wrecked Vehicles (Value: 2)
										//		 Wrecked Motorcycle (Value: 1)
		} Bits;
	} Type;
	std::uint32_t Floor;				// Ground in units of -1800
										// Accepted bits are 0-31 (Range: 0, -55800)
										// Used by the Sca_get_low function to obtain ground of collision
										//
										// Formula:
										//		Floor = 0;	// Reset to null before setting
										// 
										//		if (!Bit)	// Ground height is zero (0)
										//		{
										//			ULONG High = ((Height * -200) + (nFloor * -1800));
										//			High /= -1800;
										//			if (!High) { Floor = 1; }	// Floor variable cannot be zero (0)
										//			else for (ULONG nBit = NULL; nBit < High; nBit++) { Floor |= 1 << nBit; }
										//		}
										//
										//		else Floor |= 1 << Bit;		// Collision is not at ground level (Ceiling, lifted platform, etc)
};


#pragma pack(pop)


class Resident_Evil_2_SCA {
private:

	// Header
	Resident_Evil_2_SCA_Header Header;

	// Data
	std::vector<Resident_Evil_2_SCA_Data> Data;

public:

	/*
		Construction
	*/
	explicit Resident_Evil_2_SCA(void) :
		Header(Resident_Evil_2_SCA_Header())
	{
	}

	/*
		Copy
	*/
	Resident_Evil_2_SCA(const Resident_Evil_2_SCA& v) noexcept : Header(v.Header), Data(v.Data) {}
	Resident_Evil_2_SCA& operator = (const Resident_Evil_2_SCA& v) noexcept { return *this = Resident_Evil_2_SCA(v); }

	/*
		Move
	*/
	Resident_Evil_2_SCA(Resident_Evil_2_SCA&& v) noexcept : Header(std::exchange(v.Header, {})), Data(std::exchange(v.Data, {})) {}
	Resident_Evil_2_SCA& operator = (Resident_Evil_2_SCA&& v) noexcept
	{
		std::swap(Header, v.Header);
		std::swap(Data, v.Data);
		return *this;
	}

	/*
		Get data count
	*/
	std::size_t Count(void) const { return Data.size(); }

	/*
		Get data element
	*/
	Resident_Evil_2_SCA_Data* Get(const std::size_t& iElement) { return &Data[iElement]; }

	/*
		Push back empty element
	*/
	void New(void) { Data.push_back(Resident_Evil_2_SCA_Data()); }

	/*
		Push back element from buffer
	*/
	void Add(Resident_Evil_2_SCA_Data& Input) { Data.push_back(Input); }

	/*
		Copy element to buffer
	*/
	void Copy(std::size_t iEntry, Resident_Evil_2_SCA_Data& Output) { Output = Data[iEntry]; }

	/*
		Paste element from buffer
	*/
	void Paste(std::size_t iEntry, Resident_Evil_2_SCA_Data& Input) { Data[iEntry] = Input; }

	/*
		Insert element
	*/
	void Insert(std::size_t iEntry, Resident_Evil_2_SCA_Data& Input) { Data.insert(Data.begin() + iEntry, Input); }

	/*
		Delete element
	*/
	void Delete(std::size_t iEntry) { Data.erase(Data.begin() + iEntry); }

	/*
		Open
	*/
	std::uintmax_t Open(StdFile& File, std::uintmax_t _Ptr);

	/*
		Open
	*/
	bool Open(std::filesystem::path Path, std::uintmax_t _Ptr = 0);

	/*
		Save
	*/
	std::uintmax_t Save(StdFile& File, std::uintmax_t _Ptr);

	/*
		Save
	*/
	bool Save(std::filesystem::path Path, std::uintmax_t _Ptr);

	/*
		Close
	*/
	void Close(void);

	/*
		Calculate Axis Center Point
	*/
	void CalcCxCz(void);

	/*
		Get Area
	*/
	std::uint32_t GetArea(std::int32_t X, std::int32_t Z, std::int32_t Sx, std::int32_t Sz);

	/*
		Set Area
	*/
	void SetArea(std::size_t iCollision);

	/*
		Get Ground (Low)
	*/
	std::uint32_t GetGroundLow(std::size_t iCollision);

	/*
		Get Ground (High)
	*/
	std::uint32_t GetGroundHigh(std::size_t iCollision);

	/*
		Get Floor
	*/
	std::uint32_t GetFloor(std::size_t iCollision);

	/*
		Set Floor
	*/
	std::uint32_t SetFloor(std::size_t iCollision, std::int32_t Bit);

};
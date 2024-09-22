/*
*
*	Megan Grass
*	March 07, 2024
*
*
*	TODO: 
*
*
*	CREDIT:
*
*		BS Decode: https://github.com/pmandin/reevengi-tools
*
*		SLD Decompression: https://github.com/pmandin/reevengi-tools
*
*/


#pragma once

#include <std_basic_fstream.h>

#include <std_text.h>

#include <sony_executable.h>

#include <sony_texture.h>

#include <sony_bitstream.h>

#include <sony_soundbank.h>

#include <bio_common.h>

#include <bio3_model.h>

#include "sld/bio3_sld.h"


class Resident_Evil_3 :
	private Resident_Evil_Common {
private:

	// Sony PlayStation Bitstream
	std::unique_ptr<Sony_PlayStation_Bitstream> Bs;

	// Resident Evil 3 SLD
	std::unique_ptr<Resident_Evil_3_SLD> Sld;

	std::unique_ptr<Resident_Evil_3_Model> Test;

	// Print Command Line Help
	void PrintHelp(void);

public:

	/*
		Construction
	*/
	explicit Resident_Evil_3(void) :
		Bs(std::make_unique<Sony_PlayStation_Bitstream>()),
		Sld(std::make_unique<Resident_Evil_3_SLD>()),
		Test(std::make_unique<Resident_Evil_3_Model>())
	{
		Game = Resident_Evil_Video_Game::Resident_Evil_3;
	}
	virtual ~Resident_Evil_3(void)
	{
		Bs.reset();
		Sld.reset();
		Test.reset();
	}

	/*
		Command Line Interface
	*/
	void Commandline(StrVec Args);

	/*
		Decompress SLD from unsigned char array
	*/
	bool DecompressSLD(std::vector<std::uint8_t> SLD, std::vector<std::uint8_t>& Output) { return Sld->Decompress(SLD, Output); }

	/*
		Decompress SLD from file
	*/
	bool DecompressSLD(std::filesystem::path Input) { return Sld->Decompress(Input); }

	/*
		Extract contents of BSS file container
	*/
	bool ExtractBSS(std::filesystem::path Input);

	/*
		Extract contents of Model file container
	*/
	bool ExtractModel(std::filesystem::path Input) { return Test->Open(Input); }

};
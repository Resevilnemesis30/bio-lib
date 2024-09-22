/*
*
*	Megan Grass
*	March 07, 2024
*
*
*	TODO: 
* 
*		Find CLUT for CORE01.TIM
*
*
*	CREDIT:
*
*		ADT Decompression: https://github.com/pmandin/reevengi-tools
*
*		BS Decode: https://github.com/pmandin/reevengi-tools
*
*		SLD Decompression: https://github.com/pmandin/reevengi-tools
*
*/


#include <bio2.h>


/*
	Print Command Line Help
*/
void Resident_Evil_2::PrintHelp(void)
{
	std::cout << "Resident Evil 2: Help" << std::endl << std::endl;
	std::cout << "\t<op>\t\t\tasm (assemble) or dis (disassemble)" << std::endl << std::endl;
	std::cout << "\tADT <file>\t\tDecompress ADT file" << std::endl;
	std::cout << "\tBGM <op> <file>\t\tExtract or repack contents of BGM file container" << std::endl;
	std::cout << "\tBSS <file>\t\tExtract contents of BSS file container" << std::endl;
	std::cout << "\tCPT <file>\t\tDecompress CPT file" << std::endl;
	std::cout << "\tDIE <op> <file>\t\tExtract or repack contents of DIE file container" << std::endl;
	std::cout << "\tITP <file>\t\tExtract contents of ITP file container" << std::endl;
	std::cout << "\tPDEMO <op> <file>\t\tAssemble or disassemble PDEMO file from/to text" << std::endl;
	std::cout << "\tPIX <file>\t\tConvert headerless TIM file to bitmap" << std::endl;
	std::cout << "\tSAVEBGM <file>\tExtract BGM table from save file" << std::endl;
	std::cout << "\tSLD <file>\t\tDecompress SLD file" << std::endl << std::endl;
	std::cout << "\tSTAGEXA <OverlayAddress> <offset> <count> <file>\tExtract XA_sector from STAGEx.BIN" << std::endl;
	std::cout << "BS decode, ADT and SLD decompression: https://github.com/pmandin/reevengi-tools" << std::endl;
}


/*
	Command Line Interface
*/
void Resident_Evil_2::Commandline(StrVec Args)
{
	Standard_String Str;

	Standard_FileSystem FS;

	for (std::size_t i = 0; i < Args.size(); i++)
	{
		Str.ToUpper(Args[i]);

		if (Args[i] == "HELP")
		{
			PrintHelp();
		}

		if (Args[i] == "ADT")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::filesystem::path Output = Input;
					Output.replace_extension(".out");
					std::cout << "Resident Evil 2: ADT decompressing " << Input.filename() << " to " << Output.filename() << std::endl;
					if (Adt->Decompress(Input, Output))
					{
						std::cout << "Resident Evil 2: ADT decompression successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: ADT error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: ADT error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: ADT error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "BGM")
		{
			if (i + 2 < Args.size())
			{
				String Op = Args[i + 1];
				std::filesystem::path Input = Args[i + 2];
				if (FS.Exists(Input))
				{
					if (Str.ToUpper(Op) == "ASM")
					{
						std::cout << "Resident Evil 2: Assembling " << Input.filename() << std::endl;
						if (AssembleBGM(Input))
						{
							std::cout << "Resident Evil 2: BGM assembly successful" << std::endl;
						}
						else
						{
							std::cout << "Resident Evil 2: BGM error" << std::endl;
						}
					}
					if (Str.ToUpper(Op) == "DIS")
					{
						std::cout << "Resident Evil 2: Extracting contents of " << Input.filename() << std::endl;
						if (ExtractBGM(Input))
						{
							std::cout << "Resident Evil 2: BGM extraction successful" << std::endl;
						}
						else
						{
							std::cout << "Resident Evil 2: BGM error" << std::endl;
						}
					}
				}
				else
				{
					std::cout << "Resident Evil 2: BGM error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: BGM error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "BSS")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::cout << "Resident Evil 2: Extracting contents of " << Input.filename() << std::endl;
					if (ExtractBSS(Input))
					{
						std::cout << "Resident Evil 2: BSS extraction successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: BSS error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: BSS error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: BSS error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "CPT")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::cout << "Resident Evil 2: Decompressing " << Input.filename() << std::endl;
					if (DecompressCPT(Input))
					{
						std::cout << "Resident Evil 2: CPT Decompression successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: CPT error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: CPT error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: CPT error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "DIE")
		{
			if (i + 2 < Args.size())
			{
				String Op = Args[i + 1];
				std::filesystem::path Input = Args[i + 2];
				if (FS.Exists(Input))
				{
					if (Str.ToUpper(Op) == "ASM")
					{
						std::cout << "Resident Evil 2: Assembling " << Input.filename() << std::endl;
						if (AssembleDIE(Input))
						{
							std::cout << "Resident Evil 2: DIE assembly successful" << std::endl;
						}
						else
						{
							std::cout << "Resident Evil 2: DIE error" << std::endl;
						}
					}
					if (Str.ToUpper(Op) == "DIS")
					{
						std::cout << "Resident Evil 2: Extracting contents of " << Input.filename() << std::endl;
						if (ExtractDIE(Input))
						{
							std::cout << "Resident Evil 2: DIE extraction successful" << std::endl;
						}
						else
						{
							std::cout << "Resident Evil 2: DIE error" << std::endl;
						}
					}
				}
				else
				{
					std::cout << "Resident Evil 2: DIE error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: DIE error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "ITP")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::cout << "Resident Evil 2: Extracting contents of " << Input.filename() << std::endl;
					if (ExtractITP(Input))
					{
						std::cout << "Resident Evil 2: ITP extraction successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: ITP error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: ITP error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: ITP error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "PDEMO")
		{
			if (i + 2 < Args.size())
			{
				String Op = Args[i + 1];
				std::filesystem::path Input = Args[i + 2];
				if (Str.ToUpper(Op) == "ASM")
				{
					std::cout << "Resident Evil 2: Assembling " << Input.filename() << std::endl;
					if (AssemblePDEMO(Input))
					{
						std::cout << "Resident Evil 2: PDEMO assembly successful" << std::endl;
					}
				}
				if (Str.ToUpper(Op) == "DIS")
				{
					std::cout << "Resident Evil 2: Disassembling contents of " << Input.filename() << std::endl;
					if (DisassemblePDEMO(Input))
					{
						std::cout << "Resident Evil 2: PDEMO disassembly successful" << std::endl;
					}
				}
			}
			else
			{
				std::cout << "Resident Evil 2: PDEMO error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "PIX")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::cout << "Resident Evil 2: Extracting contents of " << Input.filename() << std::endl;
					if (ExtractPIX(Input))
					{
						std::cout << "Resident Evil 2: PIX conversion successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: PIX error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: PIX error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: PIX error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "SAVEBGM")
		{
			if ((i + 1) < Args.size())
			{
				std::filesystem::path Filename = Args[i + 1];
				std::cout << "Resident Evil 2: Extracting BGM table from " << Filename.filename() << std::endl;
				if (ExtractBgmFromSaveFile(Filename))
				{
					std::cout << "Resident Evil 2: Successfully extracted BGM table" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: SAVEBGM error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}
		}

		if (Args[i] == "SLD")
		{
			if (i + 1 < Args.size())
			{
				std::filesystem::path Input = Args[i + 1];
				if (FS.Exists(Input))
				{
					std::filesystem::path Output = Input;
					Output.replace_extension(".tim");
					std::cout << "Resident Evil 2: SLD decompressing " << Input.filename() << " to " << Output.filename() << std::endl;
					if (DecompressSLD(Input))
					{
						std::cout << "Resident Evil 2: SLD decompression successful" << std::endl;
					}
					else
					{
						std::cout << "Resident Evil 2: SLD error" << std::endl;
					}
				}
				else
				{
					std::cout << "Resident Evil 2: SLD error, input file not found" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: SLD error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}

		}

		if (Args[i] == "STAGEXA")
		{
			if ((i + 4) < Args.size())
			{
				std::uintmax_t StartAddress = std::strtoull(Args[i + 1].c_str(), nullptr, 16);
				std::uintmax_t Offset = std::strtoull(Args[i + 2].c_str(), nullptr, 16);
				std::size_t Count = std::strtoull(Args[i + 3].c_str(), nullptr, 10);
				std::filesystem::path Filename = Args[i + 4];
				std::cout << "Resident Evil 2: Extracting Xa_sector[" << std::dec << Count << "][3] from " << Filename.filename() << " at offset " << std::hex << Offset << std::endl;
				if (ExtractXaSectorFromStageBin(StartAddress, Offset, Count, Filename))
				{
					std::cout << "Resident Evil 2: Successfully extracted Xa_sector table" << std::endl;
				}
			}
			else
			{
				std::cout << "Resident Evil 2: STAGEXA error, not enough arguments" << std::endl << std::endl;
				PrintHelp();
			}
		}

	}

}


/*
	Extract BGM table from save file
*/
bool Resident_Evil_2::ExtractBgmFromSaveFile(std::filesystem::path Input)
{
	std::unique_ptr<StdFile> File = std::make_unique<StdFile>();
	if (!File->Open(Input, FileAccessMode::Read, true, false))
	{
		Str->Message("SAVEBGM: Error, could not open %s", Input.filename().string().c_str());
		return false;
	}

	std::unique_ptr<StdText> Text = std::make_unique<StdText>();
	Text->SetBOM(TextFileBOM::UTF8);

	std::uintmax_t nroom[7] = { 0x1F, 0x1E, 0x10, 0x13, 0x0C, 0x1A, 0x07 };

	struct BGMCTR
	{
		std::uint8_t Main;
		std::uint8_t Sub;
	};

	std::vector<BGMCTR> BGM(0x30);

	std::uintmax_t pBGMCTR = 0x22C;

	for (std::uintmax_t i = 0; i < 7; i++)
	{
		for (auto& b : BGM)
		{
			b.Main = 0xFF;
			b.Sub = 0xFF;
		}

		for (std::uintmax_t x = 0; x < nroom[i]; x++, pBGMCTR += sizeof(BGMCTR))
		{
			File->Read(pBGMCTR, &BGM[x], sizeof(BGMCTR));

			std::cout << "SAVEBGM: " << Text->FormatCStyle("STAGE %X ROOM %02X: %02X %02X", i + 1, x, BGM[x].Main, BGM[x].Sub) << std::endl;
		}

		String Output = File->GetDirectory(Input).string() += "/" + Input.stem().string() + "_stage" + std::to_string(i + 1) + "_bgm";

		Output += b_PreferAsm ? ".asm" : ".txt";

		if (Text->Open(Output, FileAccessMode::Write))
		{
			std::size_t r = 0;

			for (auto& b : BGM)
			{
				if (b_PreferAsm)
				{
					Text->AddLine(Text->FormatCStyle("\t.byte\t0x%02X,\t0x%02X\t;; R%X%02X\n", b.Main, b.Sub, (i + 1), r));
				}
				else
				{
					Text->AddLine(Text->FormatCStyle("0x%02X 0x%02X\tR%X%02X\n", b.Main, b.Sub, (i + 1), r));
				}

				r++;
			}

			Text->FlushUTF8();
			Text->Close();
		}
		else
		{
			std::cout << "SAVEBGM: Warning, could not create " << Output << std::endl;
		}
	}

	File->Close();

	return true;
}


/*
	Open BSS file container
*/
std::unique_ptr<Standard_Image> Resident_Evil_2::OpenBSS(std::filesystem::path Input, std::int32_t No)
{
	std::unique_ptr<Standard_Image> Image = std::make_unique<Standard_Image>(ImageFormat::BMP, 320, 240, 32, 0);

	StdFile m_Input { Input, FileAccessMode::Read_Ex, true, false };
	if (!m_Input)
	{
		Str->Message("Resident Evil 2: BSS error, could not open %s", Input.filename().string().c_str());
		return Image;
	}

	if (m_Input.Size() % 65536 != 0)
	{
		Str->Message("Resident Evil 2: BSS error, file size is not a multiple of 65536");
		return Image;
	}

	size_t nBs = m_Input.Size() / 65536;

	if (!nBs)
	{
		Str->Message("Resident Evil 2: BSS error, no bitstreams");
		return Image;
	}

	struct BitStream_Header
	{
		std::uint16_t Length;
		std::uint16_t ID;
		std::uint16_t Q_Scale;
		std::uint16_t Version;
	};

	BitStream_Header Header{};

	struct BSS_Index
	{
		uint32_t Bs_size;
		uint32_t b_Sld;
	};

	BSS_Index Index{};

	uintmax_t pBs = 65536 * No;
	uint32_t Flag = 0;

	uintmax_t ZeroBytes = 0;
	uintmax_t pIndex = m_Input.Find(&ZeroBytes, sizeof(uintmax_t), pBs);
	m_Input.Align(pIndex, 4);

	m_Input.Read(pIndex - 4, &Flag, sizeof(uint32_t));
	if (Flag == 1)
	{
		pIndex -= 8;
		m_Input.Read(pIndex, &Index, sizeof(BSS_Index));
	}
	else
	{
		pIndex -= 4;
		m_Input.Read(pIndex, &Index, sizeof(BSS_Index));
	}
	uintmax_t pSld = pBs + Index.Bs_size;
	uintmax_t Sld_size = pIndex - pSld;

	std::vector<std::uint8_t> BS(Index.Bs_size);
	m_Input.Read(pBs, BS.data(), Index.Bs_size);

	std::vector<std::uint8_t> BMP(320 * 240 * 4);
	std::memcpy(&Header, &BS.data()[0], sizeof(BitStream_Header));
	Bs->mdec_decode(&BS.data()[8], Header.Version, 320, 240, Header.Q_Scale, &BMP.data()[0]);

	size_t pImg = 0;
	for (int32_t y = 0; y < 240; y++)
	{
		for (int32_t x = 0; x < 320; x++, pImg += 4)
		{
			uint32_t Color = BMP[pImg + 2] | (BMP[pImg + 1] << 8) | (BMP[pImg + 0] << 16) | (BMP[pImg + 3] << 24);
			Image->SetPixel(x, y, Color);
		}
	}

	return Image;
}


/*
	Extract contents of BSS file container
*/
bool Resident_Evil_2::ExtractBSS(std::filesystem::path Input)
{
	StdFile m_Input { Input, FileAccessMode::Read_Ex, true, false };

	if (!m_Input)
	{
		Str->Message("BSS Extraction: Error, could not open %s", Input.filename().string().c_str());
		return false;
	}

	if (m_Input.Size() % 65536 != 0)
	{
		Str->Message("BSS Extraction: Error, file size is not a multiple of 65536");
		return false;
	}

	size_t nBs = m_Input.Size() / 65536;

	if (!nBs)
	{
		Str->Message("BSS Extraction: Error, no bitstreams to extract");
		return false;
	}

	std::filesystem::path Dir = m_Input.GetDirectory() / m_Input.GetFileName().stem();

	m_Input.CreateDirectory(Dir);

	GetStageRoom(m_Input.GetFileName().stem().string());

	uintmax_t pBs = 0;

	uintmax_t pIndex = 0;

	uint32_t Flag = 0;

	struct BitStream_Header
	{
		std::uint16_t Length;
		std::uint16_t ID;
		std::uint16_t Q_Scale;
		std::uint16_t Version;
	};

	BitStream_Header Header{};

	struct BSS_Index
	{
		uint32_t Bs_size;
		uint32_t b_Sld;
	};

	BSS_Index Index{};

	for (size_t i = 0; i < nBs; i++, pBs += 65536)
	{
		uintmax_t ZeroBytes = 0;

		pIndex = m_Input.Find(&ZeroBytes, sizeof(uintmax_t), pBs);

		if (pIndex % 4 != 0) { pIndex += 4 - (pIndex % 4); }

		m_Input.Read(pIndex - 4, &Flag, sizeof(uint32_t));

		if (Flag == 1)
		{
			pIndex -= 8;
			m_Input.Read(pIndex, &Index, sizeof(BSS_Index));
		}
		else
		{
			pIndex -= 4;
			m_Input.Read(pIndex, &Index, sizeof(BSS_Index));
		}

		uintmax_t pSld = pBs + Index.Bs_size;

		uintmax_t Sld_size = pIndex - pSld;

		std::cout << "Bs_size " << std::hex << Index.Bs_size << std::dec << std::endl;
		std::cout << "b_Sld " << std::hex << Index.b_Sld << std::dec << std::endl;
		std::cout << "pSld " << std::hex << pSld << std::dec << std::endl;
		std::cout << "Sld_size " << std::hex << Sld_size << std::dec << std::endl;

		std::vector<std::uint8_t> BS(Index.Bs_size);

		m_Input.Read(pBs, BS.data(), Index.Bs_size);

		std::filesystem::path OutStr = Str->FormatCStyle("%s/ROOM_%X%02X_%02d.bs", Dir.string().c_str(), Stage, Room, i);

		m_Input.Create(OutStr, BS);

		std::cout << "BSS Extraction: Decoding bitstream" << std::endl;

		std::vector<std::uint8_t> BMP(320 * 240 * 4);

		std::memcpy(&Header, &BS.data()[0], sizeof(BitStream_Header));

		Bs->mdec_decode(&BS.data()[8], Header.Version, 320, 240, Header.Q_Scale, &BMP.data()[0]);

		std::cout << "BSS Extraction: Decoding bitstream complete" << std::endl;

		std::cout << "BSS Extraction: Converting to bitmap" << std::endl;

		Standard_Image Image { ImageFormat::BMP, 320, 240, 32, 0 };

		size_t pImg = 0;

		for (int32_t y = 0; y < 240; y++)
		{
			for (int32_t x = 0; x < 320; x++, pImg += 4)
			{
				uint32_t Color = BMP[pImg + 2] | (BMP[pImg + 1] << 8) | (BMP[pImg + 0] << 16) | (BMP[pImg + 3] << 24);
				Image.SetPixel(x, y, Color);
			}
		}

		Image.SaveAsBitmap(OutStr.replace_extension(".bmp"));

		std::cout << "BSS Extraction: Conversion complete" << std::endl;

		if (Index.b_Sld)
		{
			std::vector<std::uint8_t> SLD(Sld_size);

			m_Input.Read(pSld, SLD.data(), Sld_size);

			OutStr = Str->FormatCStyle("%s/ROOM_%X%02X_%02d_MASK.sld", Dir.string().c_str(), Stage, Room, i);

			m_Input.Create(OutStr, SLD);

			std::cout << "BSS Extraction: Decompressing SLD to TIM" << std::endl;

			std::vector<std::uint8_t> TIM(0x10220);

			if (DecompressSLD(SLD, TIM))
			{
				OutStr.replace_extension(".tim");

				m_Input.Create(OutStr, TIM);

				std::cout << "BSS Extraction: Decompressing SLD complete" << std::endl;

				Sony_PlayStation_Texture Texture { OutStr };

				std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

				Image->SaveAsBitmap(OutStr.replace_extension(".bmp"));

				Image->Close();
			}
		}
	}

	m_Input.Close();

	return true;
}


/*
	Extract contents of ITP file container
*/
bool Resident_Evil_2::ExtractITP(std::filesystem::path Input)
{
	StdFile m_Input { Input, FileAccessMode::Read_Ex, true, false };

	if (!m_Input)
	{
		Str->Message("ITP Extraction: Error, could not open %s", Input.filename().string().c_str());
		return false;
	}

	std::uintmax_t FileSize = m_Input.Size();

	std::filesystem::path Dir = m_Input.GetDirectory();

	m_Input.CreateDirectory(Dir / Input.stem());

	std::uintmax_t Offset = 0;

	std::uintmax_t Counter = 0;

	std::vector<std::uint8_t> Palette(sizeof(bio2_ds_ST0_texture00_clut01));

	std::memcpy(Palette.data(), bio2_ds_ST0_texture00_clut01, sizeof(bio2_ds_ST0_texture00_clut01));

	while (Offset < FileSize)
	{
		Sony_PlayStation_Texture Texture;

		Texture.SetSTP4Bpp(false);

		Texture.Open(m_Input, Offset);

		std::uintmax_t TextureSize = Texture.Size();

		if (!TextureSize) { break; }

		std::filesystem::path Filename = Str->FormatCStyle("%s/%s/%s_%02d_Large.tim", Dir.string().c_str(), Input.stem().string().c_str(), Input.stem().string().c_str(), Counter);

		Texture.Save(Filename);

		std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

		Image->SaveAsBitmap(Filename.replace_extension(".bmp"));

		Image->Close();

		Offset += TextureSize;

		std::uint32_t DummyBytes = 0;

		m_Input.Read(Offset + 0x4B0, &DummyBytes, sizeof(std::uint32_t));

		if (DummyBytes)
		{
			Texture.SetWidth(40);

			Texture.SetHeight(60);

			Texture.ReadPixels(m_Input, Offset, 0x960);
		}
		else
		{
			Texture.SetWidth(40);

			Texture.SetHeight(30);

			Texture.ReadPixels(m_Input, Offset, 0x4B0);
		}

		Texture.CopyPalette(Palette);

		Filename = Str->FormatCStyle("%s/%s/%s_%02d_Small.tim", Dir.string().c_str(), Input.stem().string().c_str(), Input.stem().string().c_str(), Counter);

		Texture.Save(Filename);

		Image = Texture.GetBitmap();

		Image->SaveAsBitmap(Filename.replace_extension(".bmp"));

		Image->Close();

		Offset += 0x1000 - (Offset % 0x1000);

		Counter++;
	}

	m_Input.Close();

	return true;
}


/*
	Extract contents of PIX file container
*/
bool Resident_Evil_2::ExtractPIX(std::filesystem::path Input)
{
	StdFile m_Input { Input, FileAccessMode::Read_Ex, true, false };

	if (!m_Input)
	{
		Str->Message("PIX Conversion: Error, could not open %s", Input.filename().string().c_str());
		return false;
	}

	std::filesystem::path Dir = m_Input.GetDirectory();

	std::uintmax_t FileSize = m_Input.Size();

	std::uintmax_t Offset = 0;

	std::uintmax_t Counter = 0;

	if ((Input.filename() == "ITEMALL.PIX") || (Input.filename() == "MIX.PIX"))
	{
		m_Input.CreateDirectory(Dir / Input.stem());

		std::vector<std::uint8_t> Palette(sizeof(bio2_ds_ST0_texture00_clut01));

		std::memcpy(Palette.data(), bio2_ds_ST0_texture00_clut01, sizeof(bio2_ds_ST0_texture00_clut01));

		while (Offset < FileSize)
		{
			Sony_PlayStation_Texture Texture;

			Texture.SetSTP4Bpp(false);

			Texture.Create(8, 40, 30, 1);

			Texture.CopyPalette(Palette);

			Texture.ReadPixels(m_Input, Offset, 0x4B0);

			std::filesystem::path Filename = Str->FormatCStyle("%s/%s/%s_%02d.tim", Dir.string().c_str(), Input.stem().string().c_str(), Input.stem().string().c_str(), Counter);

			Texture.Save(Filename);

			std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

			Image->SaveAsBitmap(Filename.replace_extension(".bmp"));

			Image->Close();

			Offset += 0x4B0;

			Counter++;
		}

		m_Input.Close();

		return true;
	}

	if ((Input.filename() == "MAPS.PIX") ||
		(Input.filename() == "MAP00.PIX") ||
		(Input.filename() == "MAP01.PIX") ||
		(Input.filename() == "MAP02.PIX") ||
		(Input.filename() == "MAP03.PIX") ||
		(Input.filename() == "MAP10.PIX"))
	{
		m_Input.CreateDirectory(Dir / Input.stem());

		while (Offset < FileSize)
		{
			Sony_PlayStation_Texture Texture;

			Texture.SetSTP4Bpp(false);

			Texture.Create(4, 256, 256, 21);

			std::uintmax_t ClutPtr = 0;

			for (size_t iClut = 0; iClut < 21; iClut++)
			{
				std::vector<std::uint8_t> Palette(sizeof(std::uint16_t) * 16);

				std::memcpy(Palette.data(), &bio2_ds_ST0_texture01_clut[ClutPtr], (sizeof(std::uint16_t) * 16));

				ClutPtr += (sizeof(std::uint16_t) * 16);

				Texture.CopyPalette(Palette, iClut);
			}

			Texture.ReadPixels(m_Input, Offset, 0x8000);

			std::filesystem::path Filename = Str->FormatCStyle("%s/%s/%s_%02d.tim", Dir.string().c_str(), Input.stem().string().c_str(), Input.stem().string().c_str(), Counter);

			Texture.Save(Filename);

			std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

			for (uint32_t iClut = 0; iClut < Texture.GetClutSize(); iClut++)
			{
				Texture.UpdateBitmapPalette(Image, iClut);

				Filename = Str->FormatCStyle("%s/%s/%s_%02d_%02d.tim", Dir.string().c_str(), Input.stem().string().c_str(), Input.stem().string().c_str(), Counter, iClut);

				Image->SaveAsBitmap(Filename.replace_extension(".bmp"));
			}

			Image->Close();

			Offset += 0x8000;

			Counter++;
		}

		m_Input.Close();

		return true;
	}

	if (FileSize == 0x4000)
	{
		std::vector<std::uint8_t> Pixels(0x4000);

		m_Input.Read(0, Pixels.data(), 0x4000);

		Sony_PlayStation_Texture Texture;

		Texture.Create(16, 256, 256, 0);

		Texture.CopyPixels(Pixels, 0);

		Texture.Save(Input.replace_extension(".tim"));

		std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

		Image->SaveAsBitmap(Input.replace_extension(".bmp"));

		Image->Close();

		m_Input.Close();

		return true;
	}

	if (FileSize == 0x25800)
	{
		Sony_PlayStation_Texture Texture;

		Texture.Create(16, 320, 240, 0);

		Texture.ReadPixels(m_Input, 0, 0x25800);

		Texture.Save(Input.replace_extension(".tim"));

		std::unique_ptr<Standard_Image> Image = Texture.GetBitmap();

		Image->SaveAsBitmap(Input.replace_extension(".bmp"));

		Image->Close();
	}

	m_Input.Close();

	return true;
}


/*
	Extract XA sector from stage_.bin
*/
bool Resident_Evil_2::ExtractXaSectorFromStageBin(std::uintmax_t StartAddress, std::uintmax_t Offset, std::size_t Count, std::filesystem::path Input)
{
	if (!Exe->OpenOverlay(StartAddress, Input.string()))
	{
		Str->Message("STAGEXA: Error, could not open %s", Input.filename().string().c_str());
		return false;
	}

	Standard_FileSystem FS;

	std::unique_ptr<StdText> Text = std::make_unique<StdText>();
	Text->SetBOM(TextFileBOM::UTF8);
	if (!Text->Open(FS.GetDirectory(Input) / Input.stem().string() += b_PreferAsm ? "_xas.asm" : "_xas.txt", FileAccessMode::Write))
	{
		Str->Message("STAGEXA: Error, could not create %s_xas", Input.stem().string().c_str());
		Exe->Close();
		return false;
	}

	std::uint16_t Xa_sector[3]{};

	for (std::size_t i = 0; i < Count; i++)
	{
		std::uintmax_t pData = (Offset + (i * (sizeof(std::uint16_t) * 3)));

		Exe->Read(pData, Xa_sector, sizeof(std::uint16_t) * 3);

		if (b_PreferAsm)
		{
			Text->AddLine(Text->FormatCStyle("\t.dh\t\t0x%02X,\t0x%02X,\t0x%02X\t;;\n", Xa_sector[0], Xa_sector[1], Xa_sector[2]));
		}
		else
		{
			Text->AddLine(Text->FormatCStyle("%d %d %d\n", Xa_sector[0], Xa_sector[1], Xa_sector[2]));
		}

		std::cout << "STAGEXA: " << Text->FormatCStyle("%d %d %d", Xa_sector[0], Xa_sector[1], Xa_sector[2]) << std::endl;
	}

	Text->FlushUTF8();
	Text->Close();

	Exe->Close();

	return true;
}
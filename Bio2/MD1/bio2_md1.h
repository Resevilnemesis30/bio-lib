/*
*
*	Megan Grass
*	March 07, 2024
*
*
*	TODO:
*
*/


#pragma once

#include <std_basic_fstream.h>

#include <std_text.h>

#include <sony_model.h>

#include <bio3_md2.h>


#pragma pack(push, 1)


struct Resident_Evil_2_Model_Header
{
	std::uint32_t pTexture;			// 0x00	// Absolute pointer to UV mapping data chunk
	std::uint32_t pad;				// 0x04	// Always zero (0)
	std::uint32_t nObject;			// 0x08	// Object count, (relative, absolute = nObject / 2)
};


struct Resident_Evil_2_Model_Index
{
	struct Triangle
	{
		std::uint32_t pVertice;		// 0x00	// Vertice pointer (relative)
		std::uint32_t nVertice;		// 0x04	// Vertice count
		std::uint32_t pNormal;		// 0x08	// Normal pointer (relative)
		std::uint32_t nNormal;		// 0x0C	// Normal count
		std::uint32_t pPrimitive;	// 0x10	// Primitive pointer (relative)
		std::uint32_t nPrimitive;	// 0x14	// Primitive/Texture count
		std::uint32_t pTexture;		// 0x18	// Texture pointer (relative)
	} Tri;
	struct Quadrangle
	{
		std::uint32_t pVertice;		// 0x1C	// Vertice pointer (relative)
		std::uint32_t nVertice;		// 0x20	// Vertice count
		std::uint32_t pNormal;		// 0x24	// Normal pointer (relative)
		std::uint32_t nNormal;		// 0x28	// Normal count
		std::uint32_t pPrimitive;	// 0x2C	// Primitive pointer (relative)
		std::uint32_t nPrimitive;	// 0x30	// Primitive/Texture count
		std::uint32_t pTexture;		// 0x34	// Texture pointer (relative)
	} Quad;
};


struct Resident_Evil_2_Triangle_Primitive
{
	std::int16_t n0;
	std::int16_t v0;
	std::int16_t n1;
	std::int16_t v1;
	std::int16_t n2;
	std::int16_t v2;
};


struct Resident_Evil_2_Triangle_Texture
{
	std::uint8_t u0;
	std::uint8_t v0;
	std::uint16_t Clut;
	std::uint8_t u1;
	std::uint8_t v1;
	std::uint16_t Page;
	std::uint8_t u2;
	std::uint8_t v2;
	std::uint16_t pad;
};


struct Resident_Evil_2_Quadrangle_Primitive
{
	std::int16_t n0;
	std::int16_t v0;
	std::int16_t n1;
	std::int16_t v1;
	std::int16_t n2;
	std::int16_t v2;
	std::int16_t n3;
	std::int16_t v3;
};


struct Resident_Evil_2_Quadrangle_Texture
{
	std::uint8_t u0;
	std::uint8_t v0;
	std::uint16_t Clut;
	std::uint8_t u1;
	std::uint8_t v1;
	std::uint16_t Page;
	std::uint8_t u2;
	std::uint8_t v2;
	std::uint16_t pad0;
	std::uint8_t u3;
	std::uint8_t v3;
	std::uint16_t pad1;
};


#pragma pack(pop)


struct Resident_Evil_2_Triangle
{
	Resident_Evil_2_Triangle_Primitive Primitive;
	Resident_Evil_2_Triangle_Texture Texture;
};


struct Resident_Evil_2_Quadrangle
{
	Resident_Evil_2_Quadrangle_Primitive Primitive;
	Resident_Evil_2_Quadrangle_Texture Texture;
};


struct Resident_Evil_2_Model_Object
{
	std::vector<SVECTOR> Vertice;
	std::vector<SVECTOR> Normal;
	std::vector<Resident_Evil_2_Triangle> Triangle;
	std::vector<Resident_Evil_2_Quadrangle> Quadrangle;
};


class Resident_Evil_2_MD1 {
private:

	// Resident Evil 2 Model Object
	std::vector<Resident_Evil_2_Model_Object> Object;

	// Flag
	bool b_Open;

public:

	/*
		Construction
	*/
	explicit Resident_Evil_2_MD1(std::filesystem::path Path) : b_Open(false)
	{
		Open(Path);
	}
	explicit Resident_Evil_2_MD1(void) : b_Open(false)
	{
	}
	virtual ~Resident_Evil_2_MD1(void)
	{
		Close();
	}

	/*
		Check if the model is open
	*/
	bool operator !() { return !b_Open; }

	/*
		Check if the model is open
	*/
	bool IsOpen(void) const noexcept { return b_Open; }

	/*
		Force open if object container is not empty
	*/
	bool ForceOpen(void) noexcept { if (!Object.empty()) { b_Open = true; } return b_Open; }

	/*
		Open
	*/
	std::uintmax_t Open(StdFile& File, std::uintmax_t _Ptr);

	/*
		Open
	*/
	bool Open(std::filesystem::path Input, std::uintmax_t _Ptr = 0);

	/*
		Save
	*/
	std::uintmax_t Save(StdFile& File, std::uintmax_t _Ptr);

	/*
		Save
	*/
	bool Save(std::filesystem::path Output, std::uintmax_t _Ptr = 0);

	/*
		Save object
	*/
	bool SaveObject(std::filesystem::path Output, std::size_t iObject);

	/*
		Save all objects
	*/
	bool SaveAllObjects(std::filesystem::path Directory, std::filesystem::path Stem = "obj");

	/*
		Get Sony PlayStation Model
	*/
	std::unique_ptr<Sony_PlayStation_Model> GetTMD(void);

	/*
		Get Resident Evil 3 Model
	*/
	std::unique_ptr<Resident_Evil_3_MD2> GetMD2(void);

	/*
		Get total object count
	*/
	std::size_t GetObjectCount(void) const { return Object.size(); }

	/*
		Push back empty object
	*/
	void AddObject(Resident_Evil_2_Model_Object Input) { Object.push_back(Input); }

	/*
		Get total vertice count
	*/
	std::size_t GetVerticeCount(void) const;

	/*
		Get object vertice count
	*/
	std::size_t GetVerticeCount(std::size_t iObject) const;

	/*
		Get total normal count
	*/
	std::size_t GetNormalCount(void) const;

	/*
		Get object normal count
	*/
	std::size_t GetNormalCount(std::size_t iObject) const;

	/*
		Get total triangle count
	*/
	std::size_t GetTriangleCount(void) const;

	/*
		Get object triangle count
	*/
	std::size_t GetTriangleCount(std::size_t iObject) const;

	/*
		Get total quadrangle count
	*/
	std::size_t GetQuadrangleCount(void) const;

	/*
		Get object quadrangle count
	*/
	std::size_t GetQuadrangleCount(std::size_t iObject) const;

	/*
		Get file size
	*/
	std::uintmax_t Size(void) const;

	/*
		Close
	*/
	void Close(void);

};
#include "Png.hpp"

PngChunk::PngChunk(void)
{
	this->length = 0;
	this->type = 0;
	this->crc = 0;
}

PngChunk::PngChunk(std::ifstream &file)
{
	this->length = 0;
	this->type = 0;
	this->crc = 0;

	if (!file.is_open())
		return ;

	this->length = read_int32(file);
	this->type = read_int32(file);

	for (u_int i = 0; i < this->length; i++)
		this->data.push_back(read_byte(file));
	this->crc = read_int32(file);
}

PngChunk::~PngChunk(void)
{
}

u_char
read_byte(std::fstream &file)
{
	u_char byte;
	
	byte = 0;
	if (!file.eof())
		file >> &byte;
	return byte;
}

u_int
read_int32(std::fstream &file)
{
	union {
		struct {
			u_char a;
			u_char b;
			u_char g;
			u_char r;
		};
		u_int hex;
	};
	r = read_byte(file);
	g = read_byte(file);
	b = read_byte(file);
	a = read_byte(file);
	return hex;
}

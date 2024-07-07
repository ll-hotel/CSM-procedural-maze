#include "PngChunk.hpp"
#include <fstream>

PngChunk::PngChunk(void): length(0), type(0), crc(0), data()
{
}

PngChunk::PngChunk(std::ifstream &file): length(0), type(0), crc(0), data()
{
	if (!file.is_open())
		return ;
	file.read((char *)&this->length, sizeof(this->length));
	file.read((char *)&this->type, sizeof(this->type));
	for (u_int i = 0; i < this->length; i++)
		this->data.push_back(file.get());
	file.read((char *)&this->crc, sizeof(this->crc));
}

PngChunk::~PngChunk(void)
{
}

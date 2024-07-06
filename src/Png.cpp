#include "Png.hpp"
#include "PngChunk.hpp"
#include <fstream>
#include <iostream>

Png::Png(void)
{
	this->width = 0;
	this->height = 0;
	this->bit_depth = 0;
	this->color_type = 0;
	this->compression_method = 0;
	this->interlace_method = 0;
	this->pixels = NULL;
}

Png::Png(std::string &filename)
{
	std::ifstream	file;
	u_long			signature;

	file.open(filename, std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return ;
	}

	signature = read_int32(file);
	signature = (signature << 32) | read_int32(file);
	if (signature != PNG_SIGNATURE)
	{
		std::cerr << "Error: invalid file signature" << std::endl;
		file.close();
		return ;
	}

	while (!file.eof())
	{
		PngChunk chunk = PngChunk(file);
		if (chunk.type)
			this->chunks.push_back(chunk);
	}

	for (PngChunk ichunk : this->chunks)
	{
		if (ichunk.type == PNG_IHDR)
		{
			this->width = *((u_int *)(ichunk.data.c_str()));
			this->height = *((u_int *)(ichunk.data.c_str() + 4));
			this->bit_depth = ichunk.data.c_str()[9];
			this->color_type = ichunk.data.c_str()[10];
			this->compression_method = ichunk.data.c_str()[11];
			this->filter_method = ichunk.data.c_str()[12];
			this->interlace_method = ichunk.data.c_str()[13];
		}
		else if (ichunk.type == PNG_IDAT)
		{
			this->pixels = (u_int *)ichunk.data.c_str();
		}
	}

	file.close();
}

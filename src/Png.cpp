#include "Png.hpp"
#include "PngChunk.hpp"
#include <fstream>
#include <ios>
#include <iostream>

static bool check_signature(char *signature);

Png::Png(void)
{
	this->width = 0;
	this->height = 0;
	this->bit_depth = 0;
	this->colour_type = 0;
	this->compression_method = 0;
	this->filter_method = 0;
	this->interlace_method = 0;
	this->pixels = NULL;
}

bool
Png::from_name(const char *filename)
{
	std::ifstream	file;
	char			signature[8];

	file.open(filename, std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return false;
	}

	file.read(signature, 8);
	if (!check_signature(signature))
	{
		file.close();
		return false;
	}
	std::cout << "Nice signature" << std::endl;

	while (!file.eof())
	{
		PngChunk chunk = PngChunk(file);
		this->chunks.push_back(chunk);
		if (chunk.type == PNG_IEND)
			break ;
	}
	std::cout << "Chunks: " << this->chunks.size() << std::endl;

	for (PngChunk ichunk : this->chunks)
	{
		if (ichunk.type == PNG_IHDR)
		{
			this->width = *((u_int *)(ichunk.data.c_str()));
			this->height = *((u_int *)(ichunk.data.c_str() + 4));
			this->bit_depth = ichunk.data.c_str()[9];
			this->colour_type = ichunk.data.c_str()[10];
			this->compression_method = ichunk.data.c_str()[11];
			this->filter_method = ichunk.data.c_str()[12];
			this->interlace_method = ichunk.data.c_str()[13];
		}
		else if (ichunk.type == PNG_IDAT)
		{
			this->pixels = (const u_char *)ichunk.data.c_str();
		}
	}

	file.close();

	std::cout << "this->width = " << this->width << '\n';
	std::cout << "this->height = " << this->height << '\n';
	std::cout << "this->bit_depth = " << this->bit_depth << '\n';
	std::cout << "this->colour_type = " << this->colour_type << '\n';
	std::cout << "this->compression_method = " << this->compression_method << '\n';
	std::cout << "this->filter_method = " << this->filter_method << '\n';
	std::cout << "this->interlace_method = " << this->interlace_method << std::endl;
	return true;
}

void put_hex(u_long n, u_long size)
{
	u_char tmp;

	for (int i = size - 1; i >= 0; i -= 1)
	{
		tmp = (n >> (i * 8)) & 0xff;
		std::cout << "0123456789abcdef"[(tmp & 0xf0) >> 4];
		std::cout << "0123456789abcdef"[(tmp & 0x0f)];
	}
}

static bool check_signature(char *signature)
{
	std::cout << "Got:\n";
	put_hex(*(u_long *)signature, 8);
	std::cout << "\nWanted:\n";
	put_hex(PNG_SIGNATURE_REV, 8);
	std::cout << std::endl;

	if (*(u_long *)(signature) == PNG_SIGNATURE_REV)
		return true;

	std::cerr << "Error: invalid file signature " << std::endl;
	return false;
}

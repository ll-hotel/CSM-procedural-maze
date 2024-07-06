#ifndef PNGCHUNK_HPP
# define PNGCHUNK_HPP
# include <string>
// PNG file should begin with a 8-byte signature
// (see https://en.wikipedia.org/wiki/PNG#File_format)
# define PNG_SIGNATURE 0x89504e470d0a1a0a
# define PNG_IHDR 0x49484452
# define PNG_IDAT 0x49444154
# define PNG_IEND 0x49454E44

class PngChunk
{
public:
	u_int		length;
	u_int		type;
	std::string	data;
	u_int		crc;

	PngChunk(void);
	PngChunk(std::ifstream &);
	~PngChunk(void);
};
#endif

#ifndef PNG_HPP
# define PNG_HPP
# include "PngChunk.hpp"
# include <vector>
/* PNG file should begin with a 8-byte signature
 * (see https://en.wikipedia.org/wiki/PNG#File_format) */
# define PNG_SIGNATURE 0x89504e470d0a1a0a
# define PNG_SIGNATURE_REV 0x0a1a0a0d474e5089
# define PNG_IHDR 0x49484452
# define PNG_IDAT 0x49444154
# define PNG_IEND 0x49454e44

class Png
{
public:
	Png(void);
	bool from_name(const char *filename);

	u_int		width;
	u_int		height;
	u_char		bit_depth;
	u_char		colour_type;
	u_char		compression_method;
	u_char		filter_method;
	u_char		interlace_method;
	const u_char *pixels;
private:
	std::vector<PngChunk> chunks;
};

#endif

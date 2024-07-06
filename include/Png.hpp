#ifndef PNG_HPP
# define PNG_HPP
# include "PngChunk.hpp"
# include <fstream>
# include <vector>

class Png
{
public:
	Png(void);
	Png(std::string &filename);

	u_int width;
	u_int height;
	u_char bit_depth;
	u_char color_type;
	u_char compression_method;
	u_char filter_method;
	u_char interlace_method;
	u_int *pixels;
private:
	std::vector<PngChunk> chunks;
};

u_char read_byte(std::ifstream &file);
u_int read_int32(std::ifstream &file);

#endif

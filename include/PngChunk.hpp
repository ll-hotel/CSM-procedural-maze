#ifndef PNGCHUNK_HPP
# define PNGCHUNK_HPP
# include <string>
# include <fstream>

class PngChunk
{
public:
	PngChunk(void);
	PngChunk(std::ifstream &);
	~PngChunk(void);

	u_int		length;
	u_int		type;
	u_int		crc;
	std::string	data;
};
#endif

#include "file.h"

namespace  util
{
	std::string File::contents(const char *filename)
	{
		std::ifstream fs(filename);
		std::string content, err,  line;

		if ( ! fs.is_open()) {
			err = "Could not open file: ";
			err += filename;
			
			std::cerr << err << std::endl;
			throw std::runtime_error(err);
		}

		while (std::getline(fs, line))
			content.append( line +"\n");

		fs.close();

		return content;
	}
}

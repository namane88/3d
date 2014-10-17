#ifndef FILE_H
#define FILE_H


#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

namespace util
{
	class File
	{
		private:
			File();

		public:

		static std::string contents(const char *filename);
	};
}

#endif

#include "model_loader.h"

ModelLoader::ModelLoader(const std::string &file)
{
	this->loadModel(file);
}




void ModelLoader::loadModel(const std::string &file)
{
	std::ifstream fs(file.c_str());		
	std::string line;

	if ( ! fs.is_open()) {
		std::string error("Could not open file: ");
		error += file;

		throw std::runtime_error(error);
	}

	while (std::getline(fs, line))
		this->interpret_line(line);

	fs.close();
}

void ModelLoader::interpret_line(std::string &line)
{
	const char *s = line.c_str();
	float v1, v2, v3;
	unsigned i1, i2, i3, t1, t2, t3, n1, n2, n3;



	if (sscanf(s, "v %f %f %f", &v1, &v2, &v3) == 3) 
		onV(v1, v2, v3);
	
	else if (sscanf(s, "vn %f %f %f", &v1, &v2, &v3) == 3)
		onVN(v1, v2, v3);
	
	else if (sscanf(s, "vt %f %f", &v1, &v2) == 2)
		onVT(v1, v2);

	else if (sscanf(s, "f %u %u %u", &i1, &i2, &i3) == 3) 
		onFace(i1, i2, i3);
	
	else if (sscanf(s, "f %u/%u %u/%u %u/%u", 
		&i1, &t1, 
		&i2, &t2, 
		&i3, &t3) == 6) 
	{ 
		onFace(	i1, t1, 
				i2, t2, 
				i3, t3);
	}

	else if (sscanf(s, "f %u/%u/%u %u/%u/%u %u/%u/%u", 
		&i1, &t1, &n1, 
		&i2, &t2, &n2, 
		&i3, &t3, &n3) == 9) 
	{
		onFace( i1, t1, n1,
				i2, t2, n2,
				i3, t3, n3);
	}
}

void ModelLoader::onV(float v1, float v2, float v3) {
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
}

void ModelLoader::onVT(float t1, float t2) {
	vt.push_back(t1);
	vt.push_back(t2);
}

void ModelLoader::onVN(float n1, float n2, float n3) {
	vn.push_back(n1);
	vn.push_back(n2);
	vn.push_back(n3);
}

void ModelLoader::copyValues(std::vector<float>& src, std::vector<float>& dst, unsigned i1, unsigned i2, unsigned i3, int max)
{
	for(int i = 0; i < max; i++)
		dst.push_back( src[( (i1-1) * max ) + i] );
	
	for(int i = 0; i < max; i++)
		dst.push_back( src[( (i2-1) * max ) + i] );

	for(int i = 0; i < max; i++)
		dst.push_back( src[( (i3-1) * max ) + i] );
}

void ModelLoader::onFace(unsigned i1, unsigned i2, unsigned i3) 
{
	copyValues(v, vertices, i1, i2, i3);
}

void ModelLoader::onFace(	unsigned i1, unsigned t1,
							unsigned i2, unsigned t2,
							unsigned i3, unsigned t3)
{
	copyValues(v , vertices, i1, i2, i3); 
	copyValues(vt, textureCoords, t1, t2, t3, 2);
}

void ModelLoader::onFace(	unsigned i1, unsigned t1, unsigned n1,
							unsigned i2, unsigned t2, unsigned n2,
							unsigned i3, unsigned t3, unsigned n3)
{
	copyValues(v , vertices, i1, i2, i3); 
	copyValues(vt, textureCoords, t1, t2, t3, 2);
	copyValues(vn, normals, n1, n2, n3);
}


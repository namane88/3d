#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

class ModelLoader
{
	private:
		std::vector<float> v, vn, vt;
		std::vector<float> vertices, normals, textureCoords;

		void loadModel(const std::string &file);
		void interpret_line(std::string &);

		void onV(float, float, float);
		void onVN(float, float, float);
		void onVT(float, float);

		void onFace(unsigned v1, unsigned v2, unsigned v3);

		void onFace(unsigned v1, unsigned t1,
					unsigned v2, unsigned t2,
					unsigned v3, unsigned t3);

		void onFace(unsigned v1, unsigned t1, unsigned n1,
					unsigned v2, unsigned t2, unsigned n2,
					unsigned v3, unsigned t3, unsigned n3);

		void copyValues(std::vector<float>& src, std::vector<float>& dst, unsigned i1, unsigned i2, unsigned i3, int max = 3);
	public:
		ModelLoader(const std::string &file);


		std::vector<float>& getVertices() { return vertices; }
		std::vector<float>& getNormals() { return normals; }
		std::vector<float>& getTexCoords() { return textureCoords; }
};

#endif

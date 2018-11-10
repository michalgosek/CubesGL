#pragma once
#include <vector>

#include "glm.hpp"

const std::vector<float> vertices = {

	//VertexCords		    //TexCords:			[ID:]
	 0.5f,  0.5f,  0.5f,	1.0f, 0.0f,			//0
	 0.5f,  0.5f,  0.5f,	1.0f, 1.0f,			//1
	 0.5f,  0.5f, -0.5f,	1.0f, 1.0f,			//2
	 0.5f, -0.5f,  0.5f,	0.0f, 0.0f,			//3

	 0.5f, -0.5f,  0.5f,	1.0f, 0.0f,			//4
	 0.5f, -0.5f, -0.5f,	0.0f, 1.0f,			//5
	 0.5f, -0.5f, -0.5f,	1.0f, 0.0f,			//6
	 0.5f, -0.5f, -0.5f,	1.0f, 1.0f,			//7

	-0.5f,  0.5f,  0.5f,	0.0f, 0.0f,			//8
	-0.5f,  0.5f,  0.5f,	0.0f, 1.0f,			//9
	-0.5f,  0.5f,  0.5f,	1.0f, 0.0f,			//10
	-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,			//11

	-0.5f,  0.5f, -0.5f,	0.0f, 1.0f,			//12
	-0.5f,  0.5f, -0.5f,	1.0f, 1.0f,			//13
	-0.5f, -0.5f,  0.5f,	0.0f, 0.0f,			//14
	-0.5f, -0.5f, -0.5f,	0.0f, 0.0f,			//15
	-0.5f, -0.5f, -0.5f,	0.0f, 1.0f,			//16
};

const unsigned int rLength = vertices.size() / 17;

const std::vector<int> planes = {
														//Planes: [ID:]
	15,		6,		2,		2,		11,		15,			//0
	14,		4,		1,		1,		 9,		14,			//1
	10,	   13,	   16,	   16,	    14,		10,			//2
	 0,		2,		5,		5,		 3,		 0,			//3
	16,		7,		4,		4,		14,		16,			//4
	11,		2,		0,		0,		 8,		11,			//5
};

const std::vector<glm::vec3> cubes = {

	 glm::vec3(0.0f, 0.0f, -1.0f), //top-center
	 glm::vec3(-4.0f, 3.0f, -7.0f),  //top-left
	 glm::vec3(4.0, 3.0f, -7.0f), //top-right
	 glm::vec3(4.0f, -3.0f, -7.0f), //bottom-right
	 glm::vec3 (-4.0f, -3.0f, -7.0f) //bottom-left

};


//...will be fixed in next relase...
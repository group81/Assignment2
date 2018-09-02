#include "Trapezoidal.h"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <map>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <unistd.h>
#include <sys/time.h>
#elif defined(WIN32)
#include <Windows.h>
#include <tchar.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>
#include <sys/time.h>
#endif


#include "Camera.hpp"
#include "Ground.hpp"
#include "KeyManager.hpp"

#include "Shape.hpp"
#include "Vehicle.hpp"

#include "RemoteDataManager.hpp"
#include "Messages.hpp"
#include "HUD.hpp"
#include "ObstacleManager.hpp"

trapezoidal::trapezoidal() {}
trapezoidal::trapezoidal(double aLength, double bLength, double height, double depth, double offset) 
{
	this->a = aLength;
	this->b = bLength;
	this->h = height;
	this->d = depth;
	this->o = offset;
}

void trapezoidal::draw()
{
	glBegin(GL_QUADS);
	//face ABCD
	glVertex3f(a / 2, 0, -d / 2);			//A
	glVertex3f(-a / 2, 0, -d / 2);			//B
	glVertex3f(-a / 2, 0, d / 2);			//C
	glVertex3f(a / 2, 0, d / 2);			//D
	//face EFGH
	glVertex3f(a / 2 - o, h, -d / 2);		//E
	glVertex3f(a / 2 - o - b, h, -d / 2);	//F
	glVertex3f(a / 2 - o - b, h, d / 2);	//G
	glVertex3f(a / 2 - o, h, d / 2);		//H
	//face ABFE
	glVertex3f(a / 2, 0, -d / 2);			//A
	glVertex3f(-a / 2, 0, -d / 2);			//B
	glVertex3f(a / 2 - o - b, h, -d / 2);	//F
	glVertex3f(a / 2 - o, h, -d / 2);		//E
	//face BCGF
	glVertex3f(-a / 2, 0, -d / 2);			//B
	glVertex3f(-a / 2, 0, d / 2);			//C
	glVertex3f(a / 2 - o - b, h, d / 2);	//G
	glVertex3f(a / 2 - o - b, h, -d / 2);	//F
	//face CDHG
	glVertex3f(-a / 2, 0, d / 2);			//C
	glVertex3f(a / 2, 0, d / 2);			//D
	glVertex3f(a / 2 - o, h, d / 2);		//H
	glVertex3f(a / 2 - o - b, h, d / 2);	//G
	//face DAEH
	glVertex3f(a / 2, 0, d / 2);			//D
	glVertex3f(a / 2, 0, -d / 2);			//A
	glVertex3f(a / 2 - o, h, -d / 2);		//E
	glVertex3f(a / 2 - o, h, d / 2);		//H
	glEnd();
}
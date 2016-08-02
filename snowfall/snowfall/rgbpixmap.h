#include <GL\freeglut.h>

// RGBpixmap.h: a class to support working with RGB pixmaps.
#ifndef _RGBPIXMAP
#define _RGBPIXMAP
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
using namespace std;
typedef unsigned char uchar;

class IntRect  //aligned rectangle with integer coordinates, used for viewport
{
public:
	IntRect() { l = 0; r = 100; b = 0; t = 100; } //constructors
	IntRect(int left, int right, int bottom, int top)
	{
		l = left; r = right; b = bottom; t = top;
	}
	void set(int left, int right, int bottom, int top)
	{
		l = left; r = right; b = bottom; t = top;
	}
	void draw(void); //draw this rectangle using OpenGL
	int getL(void)
	{
		return l;
	}
	int getR(void)
	{
		return r;
	}
	int getT(void)
	{
		return t;
	}
	int getB(void)
	{
		return b;
	}

private:
	int l, r, b, t;
};

//@@@@@@@@@@@@@@@@@@ IntPoint class @@@@@@@@@@@@@@@@
class IntPoint { // for 2D points with integer coordinates
public:
	int x, y;
	void set(int dx, int dy) { x = dx; y = dy; }
	void set(IntPoint& p) { x = p.x; y = p.y; }
	IntPoint(int xx, int yy) { x = xx; y = yy; }
	IntPoint() { x = y = 0; }
};


class Point2   //single point w/ floating point coordinates
{

public:
	float x, y;
	Point2() { x = y = 0.0f; } //constructor 1
	Point2(float xx, float yy) { x = xx; y = yy; } //constructor 2
	void set(float xx, float yy) { x = xx; y = yy; }
	float getX() { return x; }
	float getY() { return y; }
	void draw(void)
	{
		glBegin(GL_POINTS); //draw this point
		glVertex2f((GLfloat)x, (GLfloat)y);
		glEnd();
	}

};

//@@@@@@@@@@@@@@@@@@ Point3 class @@@@@@@@@@@@@@@@
class Point3 {
public:
	float x, y, z;
	void set(float dx, float dy, float dz) { x = dx; y = dy; z = dz; }
	void set(Point3& p) { x = p.x; y = p.y; z = p.z; }
	Point3(float xx, float yy, float zz) { x = xx; y = yy; z = zz; }
	Point3() { x = y = z = 0; }
	void build4tuple(float v[])
	{// load 4-tuple with this color: v[3] = 1 for homogeneous
		v[0] = x; v[1] = y; v[2] = z; v[3] = 1.0f;
	}
};

//@@@@@@@@@@@@@@@@@@ Vector3 class @@@@@@@@@@@@@@@@
class Vector3 {
public:
	float x, y, z;
	void set(float dx, float dy, float dz) { x = dx; y = dy; z = dz; }
	void set(Vector3& v) { x = v.x; y = v.y; z = v.z; }
	void flip() { x = -x; y = -y; z = -z; } // reverse this vector
	void setDiff(Point3& a, Point3& b)//set to difference a - b
	{
		x = a.x - b.x; y = a.y - b.y; z = a.z - b.z;
	}
	void normalize()//adjust this vector to unit length
	{
		double sizeSq = x * x + y * y + z * z;
		if (sizeSq < 0.0000001)
		{
			return; // does nothing to zero vectors;
		}
		float scaleFactor = 1.0 / (float)sqrt(sizeSq);
		x *= scaleFactor; y *= scaleFactor; z *= scaleFactor;
	}
	Vector3(float xx, float yy, float zz) { x = xx; y = yy; z = zz; }
	Vector3(Vector3& v) { x = v.x; y = v.y; z = v.z; }
	Vector3() { x = y = z = 0; } //default constructor
	Vector3 cross(Vector3 b) //return this cross b
	{
		Vector3 c(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x);
		return c;
	}
	float dot(Vector3 b) // return this dotted with b
	{
		return x * b.x + y * b.y + z * b.z;
	}
};

class mRGB {   // the name RGB is already used by Windows
public: uchar r, g, b;
		mRGB() { r = g = b = 0; }
		mRGB(mRGB& p) { r = p.r; g = p.g; b = p.b; }
		mRGB(uchar rr, uchar gg, uchar bb) { r = rr; g = gg; b = bb; }
		void set(uchar rr, uchar gg, uchar bb) { r = rr; g = gg; b = bb; }
};


//$$$$$$$$$$$$$$$$$ RGBPixmap class $$$$$$$$$$$$$$$
class RGBpixmap {
private:
	mRGB* pixel; // array of pixels

public:
	int nRows, nCols; // dimensions of the pixmap
	RGBpixmap() { nRows = nCols = 0; pixel = 0; }
	RGBpixmap(int rows, int cols) //constructor
	{
		nRows = rows;
		nCols = cols;
		pixel = new mRGB[rows*cols];
	}
	int readBMPFile(char *fname); // read BMP file into this pixmap
	void freeIt() // give back memory for this pixmap
	{
		delete[]pixel; nRows = nCols = 0;
	}
	void setTexture(GLuint textureName)
	{
		glBindTexture(GL_TEXTURE_2D, textureName);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, nCols, nRows, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel);
	}
	//<<<<<<<<<<<<<<<<<< copy >>>>>>>>>>>>>>>>>>>
	void copy(IntPoint from, IntPoint to, int x, int y, int width, int height)
	{ // copy a region of the display back onto the display
		if (nRows == 0 || nCols == 0) return;
		glCopyPixels(x, y, width, height, GL_COLOR);
	}
	//<<<<<<<<<<<<<<<<<<< draw >>>>>>>>>>>>>>>>>
	void draw()
	{ // draw this pixmap at current raster position
		if (nRows == 0 || nCols == 0) return;
		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glDrawPixels(nCols, nRows, GL_RGB, GL_UNSIGNED_BYTE, pixel);
	}
	//<<<<<<<<<<<<<<<<< read >>>>>>>>>>>>>>>>
	int read(int x, int y, int wid, int ht)
	{ // read a rectangle of pixels into this pixmap
		nRows = ht;
		nCols = wid;
		pixel = new mRGB[nRows *nCols]; if (!pixel) return -1;
		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(x, y, nCols, nRows, GL_RGB, GL_UNSIGNED_BYTE, pixel);
		return 0;
	}
	//<<<<<<<<<<<<<<<<< read from IntRect >>>>>>>>>>>>>>>>
	int read(IntRect r)
	{ // read a rectangle of pixels into this pixmap
		nRows = r.getT() - r.getB();
		nCols = r.getR() - r.getL();
		pixel = new mRGB[nRows *nCols]; if (!pixel) return -1;
		//tell OpenGL: don’t align pixels to 4 byte boundaries in memory
		glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(r.getL(), r.getB(), nCols, nRows, GL_RGB, GL_UNSIGNED_BYTE, pixel);
		return 0;
	}
	//<<<<<<<<<<<<<< setPixel >>>>>>>>>>>>>
	void setPixel(int x, int y, mRGB color)
	{
		if (x >= 0 && x < nCols && y >= 0 && y < nRows)
			pixel[nCols * y + x] = color;
	}
	//<<<<<<<<<<<<<<<< getPixel >>>>>>>>>>>
	mRGB getPixel(int x, int y)
	{
		mRGB bad(255, 255, 255);
		assert(x >= 0 && x < nCols);
		assert(y >= 0 && y < nRows);
		return pixel[nCols * y + x];
	}
}; //end of class RGBpixmap
#endif

typedef unsigned short ushort;
typedef unsigned long ulong;
fstream inf; // global in this file for convenience
//<<<<<<<<<<<<<<<<<<<<< getShort >>>>>>>>>>>>>>>>>>>>
ushort getShort() //helper function
{ //BMP format uses little-endian integer types
  // get a 2-byte integer stored in little-endian form
	char ic;
	ushort ip;
	inf.get(ic); ip = ic;  //first byte is little one 
	inf.get(ic);  ip |= ((ushort)ic << 8); // or in high order byte
	return ip;
}
//<<<<<<<<<<<<<<<<<<<< getLong >>>>>>>>>>>>>>>>>>>
ulong getLong() //helper function
{  //BMP format uses little-endian integer types
   // get a 4-byte integer stored in little-endian form
	ulong ip = 0;
	char ic = 0;
	unsigned char uc = ic;
	inf.get(ic); uc = ic; ip = uc;
	inf.get(ic); uc = ic; ip |= ((ulong)uc << 8);
	inf.get(ic); uc = ic; ip |= ((ulong)uc << 16);
	inf.get(ic); uc = ic; ip |= ((ulong)uc << 24);
	return ip;
}
//<<<<<<<<<<<<<<<<<< RGBPixmap:: readBmpFile>>>>>>>>>>>>>
int RGBpixmap::readBMPFile(char *fname)
{  // Read into memory an mRGB image from an uncompressed BMP file.
	// return 0 on failure, 1 on success
	inf.open(fname, ios::in | ios::binary); //read binary char's
	if (!inf) { cout << " can't open file: " << fname << endl; return 0; }
	int k, row, col, numPadBytes, nBytesInRow;
	// read the file header information
	char ch1, ch2;
	inf.get(ch1); inf.get(ch2); //type: always 'BM'
	ulong fileSize = getLong();
	ushort reserved1 = getShort();    // always 0
	ushort reserved2 = getShort();     // always 0 
	ulong offBits = getLong(); // offset to image - unreliable
	ulong headerSize = getLong();     // always 40
	ulong numCols = getLong(); // number of columns in image
	ulong numRows = getLong(); // number of rows in image
	ushort planes = getShort();      // always 1 
	ushort bitsPerPixel = getShort();    //8 or 24; allow 24 here
	ulong compression = getLong();      // must be 0 for uncompressed 
	ulong imageSize = getLong();       // total bytes in image 
	ulong xPels = getLong();    // always 0 
	ulong yPels = getLong();    // always 0 
	ulong numLUTentries = getLong();    // 256 for 8 bit, otherwise 0 
	ulong impColors = getLong();       // always 0 
	if (bitsPerPixel != 24)
	{ // error - must be a 24 bit uncompressed image
		cout << "not a 24 bit/pixelimage, or is compressed!\n";
		inf.close(); return 0;
	}
	//add bytes at end of each row so total # is a multiple of 4
	// round up 3*numCols to next mult. of 4
	nBytesInRow = ((3 * numCols + 3) / 4) * 4;
	numPadBytes = nBytesInRow - 3 * numCols; // need this many
	nRows = numRows; // set class's data members
	nCols = numCols;
	pixel = new mRGB[nRows * nCols]; //make space for array
	if (!pixel) return 0; // out of memory!
	long count = 0;
	char dum;
	for (row = 0; row < nRows; row++) // read pixel values
	{
		for (col = 0; col < nCols; col++)
		{
			char r, g, b;
			inf.get(b); inf.get(g); inf.get(r); //read bytes
			pixel[count].r = r; //place them in colors
			pixel[count].g = g;
			pixel[count++].b = b;
		}
		for (k = 0; k < numPadBytes; k++) //skip pad bytes at row's end
			inf >> dum;
	}
	inf.close(); return 1; // success
}


/* 
 *Functions for adding an image texture to the scene as a wall hanging
 */

#include "RGBpixmap.h"

static GLuint texName;
RGBpixmap pic; //  pixmap
int ImageWidth = 512, ImageHeight = 512; 
static GLubyte Image[512][512][4];
float c = 3.14/180.0;

void LoadImage()
{
    int i,j;
	mRGB  pixel;
	pic.readBMPFile("galaxy.bmp"); //make a pixmap from a bmp file

	for (i = 0 ; i <ImageHeight; i++) {
		for (j = 0; j < ImageWidth; j++) {

			  pixel = pic.getPixel(i,j);
			  Image[i][j][0] =  (GLubyte) pixel.r ;
			  
			  Image[i][j][1] =  (GLubyte) pixel.g ;
			  
			  Image[i][j][2] =  (GLubyte) pixel.b ;
			 
			  Image[i][j][3] =  (GLubyte)  255;
 		}
	}
}

void initImage()
{    
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);
   
   LoadImage();
   
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);


   glGenTextures(1, &texName);
   glBindTexture(GL_TEXTURE_2D, texName);


   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, ImageWidth, ImageHeight, 
                0, GL_RGBA, GL_UNSIGNED_BYTE, Image);
}

void drawImage()
{
	glPushMatrix();
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		glBindTexture(GL_TEXTURE_2D, texName);
		glTranslatef(0.0025, 0.6, 0.25);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glBegin(GL_QUADS);
		   glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, -0.25, 0.0); //bottom left
		   glTexCoord2f(1.0, 0.0); glVertex3f(-0.5, 0.25, 0.0); //bottom right
		   glTexCoord2f(1.0, 1.0); glVertex3f(0.0, 0.25, 0.0); //top right
		   glTexCoord2f(0.0, 1.0); glVertex3f(0.0, -0.25, 0.0); //top left
		glEnd();
	    glDisable(GL_TEXTURE_2D);
   glPopMatrix();
}
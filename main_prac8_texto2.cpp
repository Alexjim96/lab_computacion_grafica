//Semestre 2012 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Jiménez Jiménez Luis Alejandro***//
//*************		grupo: 01							******//
//*************	ejercicio de casa						******//
//************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_oro;
CTexture t_mad;
CTexture t_mad2;
CTexture t_pared_mad;
CTexture t_teja;
CTexture t_chime;
CTexture t_puerta;
CTexture t_ventana;
CTexture t_chim;
int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_oro.LoadTGA("golden.tga");//cargar textura
	t_oro.BuildGLTexture();
	t_oro.ReleaseImage();

	t_mad.LoadTGA("madera_silla.tga");//cargar textura
	t_mad.BuildGLTexture();
	t_mad.ReleaseImage();

	t_mad2.LoadTGA("made.tga");//cargar textura
	t_mad2.BuildGLTexture();
	t_mad2.ReleaseImage();

	t_pared_mad.LoadTGA("pare_mad.tga");//cargar textura
	t_pared_mad.BuildGLTexture();
	t_pared_mad.ReleaseImage();

	t_teja.LoadTGA("tej.tga");//cargar textura
	t_teja.BuildGLTexture();
	t_teja.ReleaseImage();

	t_chime.LoadTGA("chime.tga");//cargar textura
	t_chime.BuildGLTexture();
	t_chime.ReleaseImage();

	t_chim.LoadTGA("chim.tga");//cargar textura
	t_chim.BuildGLTexture();
	t_chim.ReleaseImage();

	t_puerta.LoadTGA("puerta.tga");//cargar textura
	t_puerta.BuildGLTexture();
	t_puerta.ReleaseImage();

	t_ventana.LoadTGA("ventana.tga");//cargar textura
	t_ventana.BuildGLTexture();
	t_ventana.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,1.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void prisma2(GLuint textura1)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(90,0.0,1.0,0.0);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
		glPushMatrix();
			glTranslatef(0.0,-0.7,0.0);
			glScalef(0.15,0.15,0.15);
			glPushMatrix(); 
				glColor3f(1.0, 1.0, 1.0);
				glScalef(2.0,1.0,3.0);  
				prisma(t_Ajedrez2.GLindex, t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//mesa
			
				glScalef(4.0,1.0,4.0);
				glTranslatef(0.0, -0.07, 0.0);
				prisma2(t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//pata de la mesa
				glScalef(0.5, 4.0, 0.5);
				glTranslatef(3.0, -0.6, 3.0);
				prisma2(t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//pata de la mesa
				glScalef(0.5, 4.0, 0.5);
				glTranslatef(-3.0, -0.6, -3.0);
				prisma2(t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//pata de la mesa
				glScalef(0.5, 4.0, 0.5);
				glTranslatef(-3.0, -0.6, 3.0);
				prisma2(t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//pata de la mesa
				glScalef(0.5, 4.0, 0.5);
				glTranslatef(3.0, -0.6, -3.0);
				prisma2(t_mad.GLindex);
			glPopMatrix();

			glPushMatrix();//silla
				glTranslatef(3.4, -2.0, 0.0);
				glScalef(1.5, 0.3, 2.0);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//respaldo
				glTranslatef(4.1, -0.6, 0.0);
				glScalef(0.1, 2.5, 2.0);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata1 silla
				glTranslatef(3.0, -3.2, 0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata2 silla
				glTranslatef(4.0, -3.2, 0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata3 silla
				glTranslatef(4.0, -3.2, -0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata4 silla
				glTranslatef(3.0, -3.2, -0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			//silla 2
			glPushMatrix();//silla
				glTranslatef(-3.4, -2.0, 0.0);
				glScalef(1.5, 0.3, 2.0);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//respaldo
				glTranslatef(-4.1, -0.6, 0.0);
				glScalef(0.1, 2.5, 2.0);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata1 silla
				glTranslatef(-3.0, -3.2, 0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
				glPopMatrix();

			glPushMatrix();//pata2 silla
				glTranslatef(-4.0, -3.2, 0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata3 silla
				glTranslatef(-4.0, -3.2, -0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();

			glPushMatrix();//pata4 silla
				glTranslatef(-3.0, -3.2, -0.7);
				glScalef(0.2, 2.3, 0.2);
				prisma2(t_mad2.GLindex);
			glPopMatrix();
		glPopMatrix();
		//cabana
		glPushMatrix();
			//base de casa
			glPushMatrix();
				glTranslatef(0.0, -1.5, 0.0);
				glScalef(5.0, 0.1, 5.0);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			//paredes de casa
			glPushMatrix();
				glTranslatef(0.0, 0.0, 1.5);	
				glScalef(3.0,3.0,0.01);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, 0.0,- 1.5);
				glScalef(3.0, 3.0, 0.01);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1.5, 0.0, 0.0);
				glScalef(0.01, 3.0, 3.0);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1.5, -1.0, 0.0);
				glScalef(0.01, 1.5, 3.0);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
				glTranslatef(-1.5, 1.0, 0.0);
				glScalef(0.01, 1.0, 3.0);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1.5, 0.0, 0.0);
				glScalef(0.01, 3.0, 1.0);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();

			//teja1
			glPushMatrix();
				glTranslatef(0.0,1.8,1.0);
				glRotatef(35,1.0,0.0,0.0);
				glScalef(3.3, 0.2, 3.0);
				prisma2(t_teja.GLindex);
			glPopMatrix();
			//teja2
			glPushMatrix();
				glTranslatef(0.0, 1.9, -1.0);
				glRotatef(-42, 1.0, 0.0, 0.0);
				glScalef(3.3, 0.2, 3.3);
				prisma2(t_teja.GLindex);
			glPopMatrix();
			//teja3
			glPushMatrix();
				glTranslatef(-1.8, 1.5, 0.0);
				glRotatef(55, 0.0, 0.0, 1.0);
				glScalef(2.0, 0.2, 3.0);
				prisma2(t_teja.GLindex);
			glPopMatrix();
			//teja4
			glPushMatrix();
				glTranslatef(1.8, 1.5, 0.0);
				glRotatef(-55, 0.0, 0.0, 1.0);
				glScalef(2.0, 0.2, 3.0);
				prisma2(t_teja.GLindex);
			glPopMatrix();
			//chimenea
			glPushMatrix();
				glTranslatef(0.0, 0.5, 1.2);
				glScalef(0.5, 3.8, 0.5);
				prisma(t_teja.GLindex, t_chime.GLindex);
			glPopMatrix();
			//columna para teja3
			glPushMatrix();
				glTranslatef(-2.1, -0.2, -1.0);
				glRotatef(90,0.0,1.0,0.0);
				glScalef(0.08, 2.4, 0.08);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			//columna2 para teja3
			glPushMatrix();
				glTranslatef(-2.1, -0.2, 1.0);
				glRotatef(90, 0.0, 1.0, 0.0);
				glScalef(0.08, 2.4, 0.08);
				prisma2(t_pared_mad.GLindex);
			glPopMatrix();
			//chimenea interior
			glPushMatrix();
				glTranslatef(0.0, -1.1, 0.99);
				glRotatef(180,0.0,0.0,1.0);
				glScalef(0.47, 0.5, 0.1);
				prisma2(t_chim.GLindex);
			glPopMatrix();
			//ventana
			glPushMatrix();
				glTranslatef(-1.5, 0.2, 1.0);
				glRotatef(90, 1.0, 0.0, 0.0);
				glScalef(0.01, 1.0, 0.9);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.5);
				prisma2(t_ventana.GLindex);
				glDisable(GL_ALPHA_TEST);
				
			glPopMatrix();
			//ventana 2
			glPushMatrix();
				glTranslatef(-1.5, 0.2, -1.0);
				glRotatef(90, 1.0, 0.0, 0.0);
				glScalef(0.01, 1.0, 0.9);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.5);
				prisma2(t_ventana.GLindex);
				glDisable(GL_ALPHA_TEST);

			glPopMatrix();
			//puerta
			glPushMatrix();
				glTranslatef(-1.5, -0.7, 0.0);
				glRotatef(90, 1.0, 0.0, 0.0);
				glScalef(0.01, 0.6, 1.5);
				prisma2(t_puerta.GLindex);
			glPopMatrix();
			

		glPopMatrix();



	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 8");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Texturas");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
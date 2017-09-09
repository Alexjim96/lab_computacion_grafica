//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Jiménez Jiménez Luis Alejandro***//
//*************	  grupo: 01								******//
//*************											******//
//*****agregar esquema del perrito left front y top ****//
#include "Main.h"

float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;
float rotY = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
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

		glBegin(GL_POLYGON);	//Front
		//	glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0, 1.0, 0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();
		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0, 1.0, 1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();
		glBegin(GL_POLYGON);	//Right
			glColor3f(0.255, 0.128, 0.08);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//Poner Código Aquí.
	/*	glTranslatef(0.0f, 0.0f, 0.0);


	glPushMatrix();
	glTranslatef(-2.0f, 0.0f, 0.0);
	glScalef(2.0, 0.0, 0.0);
	prisma();
	glPopMatrix();

	glRotatef(transZ, 1.0, 0.0, 1.0);
	glScalef(3.0, 1.0, 1.0);
	prisma();
	*//*
	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(rotY, 0.0, 1.0,0.0);
	glPushMatrix();
		glPushMatrix();//cabeza
			glColor3f(1.0, 0.0, 0.0);
			prisma(); //(0,0,0)
		glPopMatrix();
		glPushMatrix();//cuello (0,-0.75,0)
			glTranslatef(0.0,-0.75,0.0);
			glScalef(0.5,0.5,1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//torso (0,-2.5,0)
			glTranslatef(0.0, -2.5, 0.0);
			glScalef(3.0, 3.0, 1.0);
			glColor3f(0.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//brazo der (-3.0,-1.5,0)
			glTranslatef(-3.0, -1.5, 0.0);
			glScalef(3.0, 1.0, 1.0);
			glColor3f(1.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//brazo izq (3.0,-1.5,0)
			glTranslatef(3.0, -1.5, 0.0);
			glScalef(3.0, 1.0, 1.0);
			glColor3f(1.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//mano izq (3.0,-1.5,0)
			glTranslatef(-5.5, -1.5, 0.0);
			glScalef(2.0, 2.0, 1.0);
			glColor3f(1.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//mano der (3.0,-1.5,0)
			glTranslatef(5.5, -1.5, 0.0);
			glScalef(2.0, 2.0, 1.0);
			glColor3f(1.0, 1.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//pierna der (-3. 0,-1.5,0)
			glTranslatef(-1.0, -7.5, 0.0);
			glScalef(1.0, 7.0, 1.0);
			glColor3f(1.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//pierna izq (-3. 0,-1.5,0)
			glTranslatef(1.0, -7.5, 0.0);
			glScalef(1.0, 7.0, 1.0);
			glColor3f(1.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie der (-3. 0,-1.5,0)
			glTranslatef(-2.0, -12.5, 0.0);
			glScalef(3.0, 3.0, 1.0);
			glColor3f(0.5, 0.0, 0.2);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie der (-3. 0,-1.5,0)
			glTranslatef(2.0, -12.5, 0.0);
			glScalef(3.0, 3.0, 1.0);
			glColor3f(0.5, 0.0, 0.2);
			prisma();
		glPopMatrix();


	glPopMatrix();
	*/
	//perro, presionar 's' para ajustar tamaño 
	//las teclas de direcciones junto con 'n' y 'm' para la rotacion 
	glTranslatef(0.0f, 0.0f, transZ);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
	glPushMatrix();
		glPushMatrix();//cuello
			glTranslatef(0.0f, 0.0f, 0.0f);
			glScalef(3.0, 5.0, 5.0);
			glColor3f(0.204, 0.102, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//cabeza
			glTranslatef(-2.5, 1.0, 0.0);
			glScalef(2.0, 5.0, 6.0);
			glColor3f(0.255, 0.128, 0.05);
			prisma();
		glPopMatrix();
		glPushMatrix();//trompa
			glTranslatef(-4.0, -0.25, 0.0);
			glScalef(1.5, 1.5, 3.0);
			glColor3f(0.204, 0.102, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//trompa 2
			glTranslatef(-4.0, -1.25f, 0.0);
			glScalef(1.5, 0.5, 3.0);
			glColor3f(0.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//nariz
			glTranslatef(-4.75,0.0, 0.0);
			glScalef(0.25, 1.0, 1.0);
			glColor3f(0.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//oreja der
			glTranslatef(-1.75, 4.5, -1.5);
			glScalef(0.5, 2.0, 2.0);
			glColor3f(0.5, 0.0, 0.2);
			prisma();
		glPopMatrix();
		glPushMatrix();//oreja izq
			glTranslatef(-1.75, 4.5, 1.5);
			glScalef(0.5, 2.0, 2.0);
			glColor3f(0.5, 0.0, 0.2);
			prisma();
		glPopMatrix();
		glPushMatrix();//ojo izq blanco
			glTranslatef(-3.6, 2.5, 1.5);
			glScalef(0.25, 1.0, 2.0);
			glColor3f(1.0, 1.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//ojo der blanco
			glTranslatef(-3.6, 2.5, -1.5);
			glScalef(0.25, 1.0, 2.0);
			glColor3f(1.0, 1.0, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//ojo izq negro
			glTranslatef(-3.8, 2.25, 1.5);
			glScalef(0.25, 0.5, 1.0);
			glColor3f(0.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//ojo der negro
			glTranslatef(-3.8, 2.25, -1.5);
			glScalef(0.25, 0.5, 1.0);
			glColor3f(0.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//tronco
			glTranslatef(4.5, -0.25, 0.0);
			glScalef(6.0, 3.5, 5.0);
			glColor3f(0.255, 0.128, 0.05);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie der frente
			glTranslatef(0.0, -4.0, -1.5);
			glScalef(1.0, 3.0, 1.0);
			glColor3f(0.255, 0.128, 0.05);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie izq frente
			glTranslatef(0.0, -4.0, 1.5);
			glScalef(1.0, 3.0, 1.0);
			glColor3f(0.255, 0.128, 0.05);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie der atras
			glTranslatef(6.0, -3.5, -1.5);
			glScalef(1.0, 3.0, 1.0);
			glColor3f(0.204, 0.102, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//pie der atras
			glTranslatef(6.0, -3.5, 1.5);
			glScalef(1.0, 3.0, 1.0);
			glColor3f(0.204, 0.102, 0.0);
			prisma();
		glPopMatrix();
		glPushMatrix();//cola
			glTranslatef(9.0, 1.0, 0.0);
			glScalef(3.0, 1.0, 1.0);
			glColor3f(0.255, 0.128, 0.05);
			prisma();
		glPopMatrix();

	glPopMatrix();

  glutSwapBuffers ( );
  // Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'm':
		case 'M':
			angleZ += 2.5f;
			break;
		case 'n':
		case 'N':
			angleZ -= 2.5f;
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
  case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
	  angleX += 3.0f;
	  break;
	  //glutFullScreen ( ); // Full Screen Mode
	  //break;
  case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
	  angleX -= 3.0f;
	  break;
	  //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
	  //break;
  case GLUT_KEY_LEFT:
	  angleY += 3.0f;
	  break;
  case GLUT_KEY_RIGHT:
	  angleY -= 3.0f;
	  break;
  default:
	  break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (1000, 1000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}




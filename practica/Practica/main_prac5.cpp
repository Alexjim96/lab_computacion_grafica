//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): Jiménez Jiménez Luis Alejandro***//
//*************		grupo: 01		          ****//
//*************	ejercicio:	cuerpo y brazo juntos	******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro=0.0;
float angCodo = 0.0;
float angMano = 0.0;
float angPulgar1 = 0.0;
float angPulgar2= 0.0;
float angInd1 = 0.0;
float angInd2 = 0.0;
float angInd3 = 0.0;
float angMedio1 = 0.0;
float angMedio2 = 0.0;
float angMedio3 = 0.0;
float angAnu1 = 0.0;
float angAnu2 = 0.0;
float angAnu3 = 0.0;
float angMe1 = 0.0;
float angMe2 = 0.0;
float angMe3 = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
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
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	//brazo detallado
	glPushMatrix();
		glRotatef(angHombro,0.0,0.0,1.0);
		glPushMatrix();//hombro
			glColor3f(1.0,0.0,0.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();//bicep
			glColor3f(0.0, 0.0, 1.0);
			glScalef(0.5,1.0,1.0);
			prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angCodo,0.0,0.0,1.0);
		glPushMatrix();//codo
			glColor3f(0.2, 0.0, 0.3);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();//ante brazo
			glColor3f(0.5, 0.0, 0.3);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(0.5, 0.2, 0.1);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();
		//pulgar
		glTranslatef(0.25, 0.0, -0.5);
		glRotatef(angPulgar1,0.0,1.0,0.0);
		glTranslatef(0.1, 0.0, 0.0);
		glPushMatrix();
			//dedo 1
			glColor3f(0.5, 0.2, 0.1);
			glPushMatrix();
				glScalef(0.2, 0.1, 0.2);
				prisma();
			glPopMatrix();

			glTranslatef(0.1, 0.0,0.0);//dedo2
			glRotatef(angPulgar2,0.0,1.0,0.0);
			glTranslatef(0.1, 0.0, 0.0);
			glColor3f(0.3, 0.2, 0.1);
			glScalef(0.2, 0.1, 0.2);
			prisma();

		glPopMatrix();
		glPopMatrix();
		//indice
		glPushMatrix();
			glTranslatef(0.25, -0.25, -0.3);
			glRotatef(-angInd1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glPushMatrix();
				//dedo 1
				glColor3f(0.5, 0.2, 0.1);
				glPushMatrix();
					glScalef(0.2, 0.1, 0.2);
					prisma();
				glPopMatrix();

				glTranslatef(0.1, 0.0, 0.0);//dedo2
				glRotatef(-angInd2, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.2, 0.1);
				glPushMatrix();
					glScalef(0.2, 0.1, 0.2);
					prisma();
				glPopMatrix();
					glTranslatef(0.1, 0.0, 0.0);//dedo3
					glRotatef(-angInd3, 0.0, 0.0, 1.0);
					glTranslatef(0.1, 0.0, 0.0);
					glColor3f(0.5, 0.2, 0.1);
					glScalef(0.2, 0.1, 0.2);
					prisma();

			glPopMatrix();
			glPopMatrix();
			//medio
			glPushMatrix();
				glTranslatef(0.25,-0.25, -0.05);
				glRotatef(-angMedio1, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glPushMatrix();
					//dedo 1
					glColor3f(0.5, 0.2, 0.1);
					glPushMatrix();
						glScalef(0.2, 0.1, 0.2);
						prisma();
					glPopMatrix();

				glTranslatef(0.1, 0.0, 0.0);//dedo2
				glRotatef(-angMedio2, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glColor3f(0.3, 0.2, 0.1);
				glPushMatrix();
					glScalef(0.2, 0.1, 0.2);
					prisma();
				glPopMatrix();
				glTranslatef(0.1, 0.0, 0.0);//dedo3
				glRotatef(-angMedio3, 0.0, 0.0, 1.0);
				glTranslatef(0.125, 0.0, 0.0);
				glColor3f(0.5, 0.2, 0.1);
				glScalef(0.25, 0.1, 0.2);
				prisma();

				glPopMatrix();
				glPopMatrix();
			//anular
			glPushMatrix();
				glTranslatef(0.25, -0.25, 0.2);
				glRotatef(-angAnu1, 0.0, 0.0, 1.0);
				glTranslatef(0.1, 0.0, 0.0);
				glPushMatrix();
					//dedo 1
					glColor3f(0.5, 0.2, 0.1);
					glPushMatrix();
						glScalef(0.2, 0.1, 0.2);
						prisma();
					glPopMatrix();

					glTranslatef(0.1, 0.0, 0.0);//dedo2
					glRotatef(-angAnu2, 0.0, 0.0, 1.0);
					glTranslatef(0.1, 0.0, 0.0);
					glColor3f(0.3, 0.2, 0.1);
					glPushMatrix();
						glScalef(0.2, 0.1, 0.2);
						prisma();
					glPopMatrix();
					glTranslatef(0.1, 0.0, 0.0);//dedo3
					glRotatef(-angAnu3, 0.0, 0.0, 1.0);
					glTranslatef(0.05, 0.0, 0.0);
					glColor3f(0.5, 0.2, 0.1);
					glScalef(0.1, 0.1, 0.2);
					prisma();

				glPopMatrix();
				glPopMatrix();

			//Meñique
			glTranslatef(0.25, -0.25, 0.45);
			glRotatef(-angMe1, 0.0, 0.0, 1.0);
			glTranslatef(0.05, 0.0, 0.0);
			glPushMatrix();
				//dedo 1
				glColor3f(0.5, 0.2, 0.1);
				glPushMatrix();
					glScalef(0.15, 0.1, 0.2);
					prisma();
				glPopMatrix();

				glTranslatef(0.1, 0.0, 0.0);//dedo2
				glRotatef(-angMe2, 0.0, 0.0, 1.0);
				glTranslatef(0.05, 0.0, 0.0);
				glColor3f(0.3, 0.2, 0.1);
				glPushMatrix();
					glScalef(0.15, 0.1, 0.2);
					prisma();
				glPopMatrix();
				glTranslatef(0.1, 0.0, 0.0);//dedo3
				glRotatef(-angMe3, 0.0, 0.0, 1.0);
				glTranslatef(0.0, 0.0, 0.0);
				glColor3f(0.5, 0.2, 0.1);
				glScalef(0.1, 0.1, 0.2);
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
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'f':
			angInd1 += 1.2f;
			break;
		case 'F':
			angInd1 -= 1.2f;
			break;
		case 'g':
			angInd2 += 1.2f;
			break;
		case 'G':
			angInd2 -= 1.2f;
			break;
		case 'h':
			angInd3 += 1.2f;
			break;
		case 'H':
			angInd3 -= 1.2f;
			break;
		case 'j':
			angMedio1 += 1.2f;
			break;
		case 'J':
			angMedio1 -= 1.2f;
			break;
		case 'k':
			angMedio2 += 1.2f;
			break;
		case 'K':
			angMedio2 -= 1.2f;
			break;
		case 'l':
			angMedio3 += 1.2f;
			break;
		case 'L':
			angMedio3 -= 1.2f;
			break;

		case 'z':
			angAnu1 += 1.2f;
			break;
		case 'Z':
			angAnu1 -= 1.2f;
			break;
		case 'x':
			angAnu2 += 1.2f;
			break;
		case 'X':
			angAnu2 -= 1.2f;
			break;

		case 'c':
			angAnu3 += 1.2f;
			break;
		case 'C':
			angAnu3 -= 1.2f;
			break;

		case 'v':
			angMe1 += 1.2f;
			break;
		case 'V':
			angMe1 -= 1.2f;
			break;

		case 'b':
			angMe2 += 1.2f;
			break;
		case 'B':
			angMe2 -= 1.2f;
			break;
		case 'e':
			angMe3 += 1.2f;
			break;
		case 'E':
			angMe3 -= 1.2f;
			break;

		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		//manipulacion brazo
		case 't':
		case 'T':
			angHombro += 1.7f;
			break;
		case 'y':
		case 'Y':
			angHombro -= 1.7f;
			break;
	//control de codo
		case 'u':
		case 'U':
			angCodo += 1.2f;
			break;
		case 'i':
		case 'I':
			angCodo -= 1.2f;
			break;
			//mano
		case 'o':
		case 'O':
			angMano += 1.2f;
			break;
		case 'p':
		case 'P':
			angCodo -= 1.2f;
			break;
		case 'm':
			angPulgar1 += 1.2f;
			break;
		case 'n':
			angPulgar2 += 1.2f;
			break;
		case 'M':
			angPulgar1 -= 1.2f;
			break;
		case 'N':
			angPulgar2 -= 1.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
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
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
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




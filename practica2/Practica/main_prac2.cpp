//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Jiménez Jiménez Luis Alejandro   	******//
//*************											******//
//****actividad: contorno, relleno,contorno, relleno.... <- poner las iniciales de mi nombre y dibujar una estrella de 5 picos*//

#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	glPointSize(10.0);
	//glBegin(GL_POINTS);//inicio dibujo y modo de dibujo puntos
	//glBegin(GL_LINES); //dibuja linea por pares
	//glBegin(GL_LINE_LOOP); //une los punto
	//glBegin(GL_TRIANGLES); //genera triangulos con solo tres vertices
/*	glBegin(GL_POLYGON); //toma en cuenta todos los vertices
	glColor3f(1.0,0.0,0.0);//para dar color
	glVertex3f(0.0f,0.0f,-1.2);//coordenadas en tres dimensiones, se define un punto
	//vertices
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-3.0f, 3.0, -1.2f);
	glColor3f(1.0, 0.0, 2.0);
	glVertex3f(3.5f, 4.0f, -1.2f);
	glColor3f(0.0, 5.0, 0.0);
	glVertex3f(4.0f, -1.0f, -1.2f);
	glVertex3f(10.0f, -4.0f, -1.2f);
	//glVertex3f(-5.0f, -5.0f, -1.2f);
	glEnd(); //termina dibujo
*/
/* ejercicio de clase lunes 21-agosto-17
	glBegin(GL_POLYGON); //toma en cuenta todos los vertices
	glColor3f(0.0, 0.0, 2.0);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glVertex3f(1.0f, 9.0f, -1.2f);
	glVertex3f(3.0f, 7.0f, -1.2f);
	glVertex3f(3.0f, 3.0f, -1.2f);
	glEnd(); //termina dibujo
	
	glBegin(GL_POLYGON); //toma en cuenta todos los vertices
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0f, 1.0f, -1.2f);
	glVertex3f(3.0f, 3.0f, -1.2f);
	glVertex3f(9.0f, 3.0f, -1.2f);
	glVertex3f(9.0f, 1.0f, -1.2f);
	
	glEnd(); //termina dibujo

	glBegin(GL_POLYGON); //toma en cuenta todos los vertices
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(1.0f, 9.0f, -1.2f);
	glVertex3f(3.0f, 7.0f, -1.2f);
	glVertex3f(9.0f, 7.0f, -1.2f);
	glVertex3f(9.0f, 9.0f, -1.2f);

	glEnd(); //termina dibujo

	*/
	//ejercicio de casa, iniciales y estrella
	//J
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-13.0f, 0.0f, -1.2f);
	glVertex3f(-9.0f, 0.0f, -1.2f);
	glVertex3f(-9.0f, 8.0f, -1.2f);
	glVertex3f(-11.0f, 8.0f, -1.2f);
	glVertex3f(-11.0f, 2.0f, -1.2f);
	glVertex3f(-13.0f, 2.0f, -1.2f);
	glEnd();
	//J con polygon
	glBegin(GL_POLYGON);
	glColor3f(0.0, 2.0, 0.0);
	glVertex3f(-7.0f, 0.0f, -1.2f);
	glVertex3f(-3.0f, 0.0f, -1.2f);
	glVertex3f(-3.0f, 2.0f, -1.2f);
	glVertex3f(-7.0f, 2.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 2.0, 0.0);
	glVertex3f(-3.0f, 2.0f, -1.2f);
	glVertex3f(-3.0f, 8.0f, -1.2f);
	glVertex3f(-5.0f, 8.0f, -1.2f);
	glVertex3f(-5.0f, 2.0f, -1.2f);
	glEnd();

	//L 
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0f, 0.0f, -1.2f);
	glVertex3f(3.0f, 0.0f, -1.2f);
	glVertex3f(3.0f, 2.0f, -1.2f);
	glVertex3f(1.0f, 2.0f, -1.2f);
	glVertex3f(1.0f, 8.0f, -1.2f);
	glVertex3f(-1.0f, 8.0f, -1.2f);
	glEnd();
	//A con polygon
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(5.0f, 0.0f, -1.2f);
	glVertex3f(7.0f, 0.0f, -1.2f);
	glVertex3f(7.0f, 6.0f, -1.2f);
	glVertex3f(5.0f, 6.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(9.0f, 0.0f, -1.2f);
	glVertex3f(11.0f, 0.0f, -1.2f);
	glVertex3f(11.0f, 6.0f, -1.2f);
	glVertex3f(9.0f, 6.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(5.0f, 6.0f, -1.2f);
	glVertex3f(11.0f, 6.0f, -1.2f);
	glVertex3f(11.0f, 8.0f, -1.2f);
	glVertex3f(5.0f, 8.0f, -1.2f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(7.0f, 4.0f, -1.2f);
	glVertex3f(9.0f, 4.0f, -1.2f);
	glVertex3f(9.0f, 2.0f, -1.2f);
	glVertex3f(7.0f, 2.0f, -1.2f);
	glEnd();
	//estrella
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.1f, -11.0f, -1.2f);
	glVertex3f(1.9f, -9.4f, -1.2f);
	glVertex3f(1.1f, -7.0f, -1.2f);
	glVertex3f(-1.2f, -7.0f, -1.2f);
	glVertex3f(-2.2f, -9.4f, -1.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-1.2f, -7.0f, -1.2f);
	glVertex3f(1.1f, -7.0f, -1.2f);
	glVertex3f(-0.2f, -3.0f, -1.2f);

	glVertex3f(1.1f, -7.0f, -1.2f);
	glVertex3f(1.9f, -9.4f, -1.2f);
	glVertex3f(5.2f, -7.0f, -1.2f);

	glVertex3f(1.9f, -9.4f, -1.2f);
	glVertex3f(-0.1f, -11.0f, -1.2f);
	glVertex3f(3.2f, -13.2f, -1.2f);

	glVertex3f(-0.1f, -11.0f, -1.2f);
	glVertex3f(-2.2f, -9.4f, -1.2f);
	glVertex3f(-3.8f, -13.2f, -1.2f);

	glVertex3f(-2.2f, -9.4f, -1.2f);
	glVertex3f(-1.2f, -7.0f, -1.2f);
	glVertex3f(-5.5f, -7.0f, -1.2f);
	glEnd();


	glFlush();
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

	// Ortogonal
	glOrtho(-15,15,-15,15,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}


#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
static void draw(void);
static void init_couleur_rand(GLfloat* c);
typedef struct 
{
	float x;
	float y;
	float deltax;
	float deltay;
	GLfloat* c; // la couleur du point
} pointm;

typedef struct
{
	pointm point1;
	pointm point2;
	pointm point3;
} lignem;

int cptLignes=0;
lignem* lesLignes;
int estTriangle=0;

int screenw=600;
int screenh=600;

void majTailleFenetre(int w, int h)
{
	screenw=w;
	screenh=h;
}

/* Initialisation d'un point */

void init_point(pointm* p)
{
	p->x=rand()%11 * 0.1;
	p->x=p->x*2-1;
	p->y=rand()%11 * 0.1;
	p->y=p->y*2-1;
	p->deltax=((rand()%10)+1) * 0.003; 
	p->deltay=((rand()%10)+1) * 0.003;
	//printf(" x:%f y:%f deltax:%f deltay:%f\n",p->x,p->y,p->deltax,p->deltay);
	/* couleur  */
	
	p->c=(GLfloat*)malloc(3*sizeof(GLfloat));
	init_couleur_rand(p->c);
}

/* Initialisation du tableau de lignes */
void init_ligne(lignem* l)
{
	init_point(&(l->point1));
	init_point(&(l->point2));
	init_point(&(l->point3));
	//printf("init_ligne\n");
}
void init_lesLignes(void)
{
	lignem l;
	
	/* Initialisation de la ligne */
	
	
	/* Affectation des points a la ligne */
	
	init_ligne(&l);
	
	lesLignes=(lignem*)malloc(sizeof(lignem));
	lesLignes[0]=l;
	cptLignes++;
}

void ajouterLigne(void)
{
	int i;
	lignem l;
	
	/* Initialisation de la ligne */
	
	init_ligne(&l);
	
	// on cree un tableau de taille i+1
	cptLignes++; 
	lignem* lesLignesTemp=(lignem*)calloc(cptLignes,sizeof(lignem));
	for (i=0;i<cptLignes-1;i++) lesLignesTemp[i]=lesLignes[i];
	lesLignesTemp[cptLignes-1]=l;
	free(lesLignes);
	lesLignes=(lignem*)calloc(cptLignes,sizeof(lignem));
	lesLignes=lesLignesTemp;
}

void retirerLigne(void)
{
	if (cptLignes>1) cptLignes--;
}


static void key(unsigned char touche, int x, int y)
{
	/* Fonction appelée lorsque l'utilisateur presse une touche "normale" */
	//printf("touche %d appuyee\n",touche);
	switch (touche) {  
		case 27:	/* touche escape */
			exit(0);break;
	case 43:
		ajouterLigne();// touche +
		break;
	case 45:
		retirerLigne(); // touche -
		break;
		// appuie sur espace : mode triangle active/desactive
	case 32:
		estTriangle=!estTriangle;
		break;
	}
}

static void specialKey(int touche, int x, int y)
{
	switch (touche) {  
		case GLUT_KEY_UP:	/* fleche haut*/
			ajouterLigne();
		break;
	case GLUT_KEY_DOWN:
		retirerLigne();
		break;
		// appuie sur espace : mode triangle active/desactive
	case 32:
		estTriangle=!estTriangle;
		break;
	}
	/* Fonction correspondant aux touches speciales (Up, Down, Left, Right, Page_Up, ...) */
}

void bouge(void)
{
	int i;
	//printf("bouge\n");
	for (i=0;i<cptLignes;i++)
    {
		lesLignes[i].point1.x+=lesLignes[i].point1.deltax;
		lesLignes[i].point1.y+=lesLignes[i].point1.deltay;
		lesLignes[i].point2.x+=lesLignes[i].point2.deltax;
		lesLignes[i].point2.y+=lesLignes[i].point2.deltay; 
		lesLignes[i].point3.x+=lesLignes[i].point3.deltax;
		lesLignes[i].point3.y+=lesLignes[i].point3.deltay;
		if ( (lesLignes[i].point1.x<-1) || (lesLignes[i].point1.x>1) ) lesLignes[i].point1.deltax=-lesLignes[i].point1.deltax;  
		if ( (lesLignes[i].point1.y<-1) || (lesLignes[i].point1.y>1) ) lesLignes[i].point1.deltay=-lesLignes[i].point1.deltay; 
		if ( (lesLignes[i].point2.x<-1) || (lesLignes[i].point2.x>1) ) lesLignes[i].point2.deltax=-lesLignes[i].point2.deltax;  
		if ( (lesLignes[i].point2.y<-1) || (lesLignes[i].point2.y>1) ) lesLignes[i].point2.deltay=-lesLignes[i].point2.deltay; 
		if ( (lesLignes[i].point3.x<-1) || (lesLignes[i].point3.x>1) ) lesLignes[i].point3.deltax=-lesLignes[i].point3.deltax;  
		if ( (lesLignes[i].point3.y<-1) || (lesLignes[i].point3.y>1) ) lesLignes[i].point3.deltay=-lesLignes[i].point3.deltay; 
    }
	usleep(50000);
	glutPostRedisplay();
}

static void init_couleur_rand(GLfloat* c)
{
	c[0]=rand()%1001 * 0.001;
	c[1]=rand()%1001 * 0.001;
	c[2]=rand()%1001 * 0.001;
	//printf ("r:%f v:%f b:%f\n",c[0],c[1],c[2]); 
}

static void draw(void)
{
	GLfloat* couleur;
	int i;
	
	glDrawBuffer(GL_BACK);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(3.5);
	for (i=0;i<cptLignes;i++)
    {
		switch(i%4)
		{
			case 0:
				glViewport(0,screenh/2,screenw/2,screenh/2);
				break;
			case 1: 
				glViewport(screenw/2,screenh/2,screenw/2,screenh/2);
				break;
			case 2:
				glViewport(screenw/2,0,screenw/2,screenh/2);
				break;
			case 3:
				glViewport(0,0,screenw/2,screenh/2);
				break;
		}
		
		if (estTriangle)
		{
			glBegin(GL_TRIANGLES);	 
			glColor3fv(lesLignes[i].point1.c);
			glVertex2f(lesLignes[i].point1.x,lesLignes[i].point1.y);
			glColor3fv(lesLignes[i].point2.c);
			glVertex2f(lesLignes[i].point2.x,lesLignes[i].point2.y);
			glColor3fv(lesLignes[i].point3.c);
			glVertex2f(lesLignes[i].point3.x,lesLignes[i].point3.y);
			glEnd();
		} 
		else 
    	{
			glBegin(GL_LINES);
			glColor3fv(lesLignes[i].point1.c);
			glVertex2f(lesLignes[i].point1.x,lesLignes[i].point1.y);
			glColor3fv(lesLignes[i].point2.c);
			glVertex2f(lesLignes[i].point2.x,lesLignes[i].point2.y);
			glEnd();
		} 
    }
	
	glutSwapBuffers();
}

static void idle(void)
{
	
}

static void visible(int vis)
{
	if (vis == GLUT_VISIBLE)
		glutIdleFunc(bouge);
	else
		glutIdleFunc(NULL);
}

static void mouseFunc(int button, int state, int x, int y)
{
	/* Fonction appelée lorsque l'une des touches de la souris change d'état:
	* Touche possible : GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON & GLUT_RIGHT_BUTTON.
	* Etat possible : GLUT_DOWN & GLUT_UP.
	* x et y correspondent aux coordonnées x et y de la souris.
	*/
}

static void MotionFunc(int x, int y)
{
	/* Fonction appelée lorsque l'utilisateur bouge la souris alors qu'une de ses touche est appuyée */
}

int main(int argc, char *argv[])
{
	/* Initialisation de glut */
	glutInit(&argc, argv);
	/* definition de la position de la fenetre */
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(screenw,screenh);
	/* Creation du contexte OpenGL en mode indexé et simple buffer à l'interieur de la fenetre */
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	/* Affichage de la fenetre */
	glutCreateWindow("Squelette");
	/* Affichage plein ecran */
	//	glutFullScreen();
	/* Initialisation des differentes fonctions de callbacks */
	glutDisplayFunc(draw);
	glutVisibilityFunc(visible);
	glutKeyboardFunc(key);
	glutSpecialFunc(specialKey);
	glutMouseFunc(mouseFunc);
	glutMotionFunc(MotionFunc);
	glutReshapeFunc(majTailleFenetre); // appelée lors d'un redimensionnement de la fenetre
	
	/* Initialisation de differents paramètres OpenGL */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	
	/* Autorisation des degradés */
	glShadeModel(GL_SMOOTH);
	
	/* Dessin des triangles en fil de fer */
	glPolygonMode(GL_FRONT,GL_LINE);
	
	/* Lancement de la boucle principale de traitement d'OpenGL. */
	srand((unsigned) time(NULL));
	init_lesLignes();
	
	glutMainLoop();
	/* Le return n'est jamais appele, car la glutMainLoop ne retourne jamais !
		* Sa presence permet cependant d'éviter que le compilateur n'affiche un warning ...
		*/
	return 0;
}

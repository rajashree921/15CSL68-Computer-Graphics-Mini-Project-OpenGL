#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
GLfloat color[][3]={{0.8,0.2,1},{0.7,0.1,0.9},{0.7,0.3,0.9},{0.8,0.5,0.9},{0.5,0.3,0.8},{0.7,0.4,0.9},{0.5,0,0.9},{0.5,0.1,0.8},{0.5,0.1,1},{0.5,0.2,1},{0.5,0.3,1},{0.5,0.4,1},{0.6,0,1},{0.6,0.1,1},{0.6,0.4,1},{0.6,0.2,1},{0.7,0.1,1},{0.7,0,1},{0.7,0.3,1},{0.7,0.4,1},{0.7,0.5,1},{0.8,0.3,1},{0.8,0.4,1},{0.8,0.6,1},{0.9,0.7,1}},rr,g,bb;
GLint i,k,r,x,y,a=0,b=0,h=0,i=0,w=0,t=0,flag=0,frame=0,x0,x1,bg=1,stars=2,text2=3,text3=4,text4=5,
v[][2]={{0,0},{0,100},{10,96},{25,90},{39,94},{50,90},{70,88},{85,95},{95,96},{110,105},{128,97},{139,95},{145,97},{155,99},{172,95},{195,90},{212,95},{254,92},{284,96},{344,100},{360,93},{390,94},{410,102},{450,94},{485,100},{502,92},{552,92},{592,96},{630,105},{680,93},{720,97},{750,87},{800,95},{850,97},{880,108},{900,96},{920,93},{950,106},{980,92},{1000,99},{1000,0},{1600,10},{3000,280}},seed[][2]={{660,155},{663,185},{677,140},{675,175},{680,205},{690,180},{695,210}};
int width, height, nrc;
unsigned int texture1,texture2;

void circle(GLfloat x, GLfloat y, GLdouble radius) {
 	float x2, y2, angle;  	
 	glPointSize(2.0); 
 	glBegin(GL_TRIANGLE_FAN); 
 	for (angle = 0.0; angle < 6.3; angle += 0.01) 
 	{ 
  		x2 = x + sin(angle)*radius;   
  		y2 = y + cos(angle)*radius; 
 	 	glVertex2f(x2, y2); 
 	} 
 	glEnd(); 
}	
void drawText(float x, float y, int r, int g, int b, const char *string)	{
	int j = strlen(string);
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	for (int i = 0; i < j; i++) {
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
	glFlush();
}
void DEl(GLfloat x, GLfloat y, GLfloat rX, GLfloat rY) 
{ 
 	float i, x2, y2;  	
 	glPointSize(2.0); 
 	glBegin(GL_TRIANGLE_FAN); 
 	for (i = 0.0; i<3.15; i += 0.01) { 
 	 	x2 = x + cos(i)*rX; 
 	 	y2= y + sin(i)*rY; 
 	 	glVertex2f(x2, y2); 
 	} 
 	glEnd(); 
}
void hand(){
	glBegin(GL_POLYGON);//left hand
		glVertex2f(460,220);
		glVertex2f(470,220);
		glVertex2f(450,150);
		glVertex2f(440,150);
	glEnd();
	glPointSize(25);
	glDisable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
		glVertex2d(447,146);
	glEnd();
	glEnable(GL_POINT_SMOOTH);
	glLineWidth(10);
	glBegin(GL_LINES);
		glVertex2f(437,148);
		glVertex2f(443,155);
	glEnd();
}
void seeds(){
	glColor3f(0,0,0);
	glPointSize(9);
	glBegin(GL_POINTS);
	for(i=0;i<8;i++) glVertex2iv(seed[i]);
	glEnd();
}
void hilda(){
glColor3f(0.6,0.2,0);
glPushMatrix();
	glScalef(1.6,1.6,0);
	DEl(480,245,20,50);//head
	glColor3f(1.0,0.9,0.6);
	glRects(475,225,485,245);//neck
	hand();
	glPushMatrix();
		glScaled(-1,1,0);
		glTranslated(-960,0,0);
		hand();
	glPopMatrix();
	glColor3f(1.0,0.6,0.7);//shirt
	glRects(465,150,495,225);
	glRects(460,190,465,220);
	glRects(500,190,495,220);
	glColor3f(0.3,1,1);
	glBegin(GL_POLYGON);//skirt
		glVertex2f(465,150);
		glVertex2f(495,150);
		glVertex2f(530,100);
		glVertex2f(430,100);
	glEnd();
	glColor3f(1.0,0.9,0.6);
	glRects(460,100,470,50);
	glPushMatrix();
		glTranslated(30,0,0);
		glRects(460,100,470,50);
	glPopMatrix();
glPopMatrix();
glColor3f(1.0,0.6,0.7);
circle(743,90,15);
circle(793,90,15);
}
void win1(int xi,int yi,int yf,int yu,int xu1,int xu2,int xu3,int yu2){
	for(x=xi,y=yi;y<yf;y+=yu){
		glRects(x,y,x+xu1,y+yu2);
		glRects(x+xu2,y,x+xu3,y+yu2);
	}
}
void win2(int x1,int y1,int x2,int y2){
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2i(x1+2,(y1+y2)/2);
	glVertex2i(x2,(y1+y2)/2);
	glVertex2i((x1+x2)/2,y1);
	glVertex2i((x1+x2)/2,y2);
	glEnd();
}
void bu()
{
	glPushMatrix();
	glScalef(0.8,0.8,0);
	glTranslatef(0,350,0);
	glColor3f(0.6,0.3,0.1);
	glRects(10,200,200,490);//1st building Ground floor
	glColor3f(0.0,0.2,0.1);//window
	glRects(150,300,180,330);
	glColor3f(0.6,0.3,0.3);//first floor
	glRects(30,490,180,690);
	glColor3f(0.3,0.3,0.3);//window
	glRects(150,550,180,580);
	glRects(150,690,170,760);//chimney
	glColor3f(0.7,0.4,0.3);//2nd building
	glRects(1050,200,1210,800);
	glColor3f(0.0,0.2,0.3);//window
	win1(1070,240,760,80,40,80,120,40);
	glPopMatrix();
	glColor3f(0.3,0.4,0.7);//blue building
	glRects(200,100,400,760);
	glColor3f(0.3,0.1,0);	
	glBegin(GL_POLYGON);//roof
	glVertex2i(180,760);
	glVertex2i(220,830);
	glVertex2i(380,830);
	glVertex2i(420,760);
	glEnd();
	glColor3f(0.8,0.3,0);//blue b door
	glRects(270,450,330,560);	
	glColor3f(0.8,1,1);//windows	
	glRects(220,630,280,720);
	glRects(320,630,380,720);	
	glColor3f(1,1,1);//white building
	glRects(450,450,570,750);
	glColor3f(0.0,0.2,0.3);//window
	win1(460,460,750,100,40,60,100,60);
	glColor3f(0,0,0);
	glRects(700,600,715,690);//chimney of hut	
	glColor3f(0.1,0.6,0.5);
	glBegin(GL_POLYGON);
	glVertex2i(630,450);
	glVertex2i(630,600);
	glVertex2i(680,700);
	glVertex2i(730,600);
	glVertex2i(730,450);
	glEnd();
	glColor3f(0.6,0.3,0.2);
	glRects(660,450,700,540);//door of hut
	glColor3f(0.3,0.3,0.3);
	win2(220,630,280,720);
	win2(320,630,380,720);
}
void road(){
	glColor3f(0.0,0.0,0.0);//road
	glRects(0,300,999,450);
	glColor3f(1.0,1.0,1.0);//zebra cross
	x0=10,x1=90;
	for(;x0<999;x0+=150,x1+=150)
	glRects(x0,360,x1,380);
}
void soil(){
glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);
	glTexCoord2f(0,0);	
	glVertex2f(0,0);
	glTexCoord2f(0,1);	
	glVertex2f(0,300);
	glTexCoord2f(1,1);	
	glVertex2f(999,300);
	glTexCoord2f(1,0);
	glVertex2f(999,0);
glEnd();
glDisable(GL_TEXTURE_2D);
}
void rc(){
	r=rand()%24;
	rr=color[r][0];
	g=color[r][1];
	bb=color[r][2];
	glColor3f(rr,g,bb);
}
void flower(int x, int y){
	glLineWidth(10);
	glPointSize(20);
	glColor3f(0.4,0.7,0.3);
	glBegin(GL_LINES);
			glVertex2f(x,y-100);
			glVertex2f(x,y+50);
	glEnd();
	glBegin(GL_POINTS);
	rc();
	for(i=y+50;i<y+200;i+=15){
		rc();
		glVertex2f(x-5,i);
		rc();
		glVertex2f(x+5,i);
	}
	glVertex2f(x,y+200);
	glEnd();
}
void rf(){
	for(k=0;k<100;k++){
		x=rand()%1200;
		y=rand()%250;
		flower(x,y);
	}
}
void water(){
	glPushMatrix();
	glTranslated(w,0,0.0);
	glColor3f(0.1,0.5,1.0);
	glBegin(GL_POLYGON);
	for(i=0;i<43;i++) glVertex2d(v[i][0],v[i][1]);
	glEnd();
	glPopMatrix();
}
void ship(){
	glScaled(20,20,0);
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);
		glVertex2f(3.5,5.5);
		glVertex2f(3.5,8.5);
		glVertex2f(19.5,8.5);
		glVertex2f(19.5,5.5);
	glEnd();
	glColor3f(1.0,0.0,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(1,5.5);
		glVertex2f(4,1);
		glVertex2f(19,1);
		glVertex2f(23,5.5);
	glEnd();
	glColor3f(0.7,0.4,0.2);
	glRects(4,5.5,5,8);
	glColor3f(0.9,0.9,0.9);
	glRects(7,7.5,10,8);
	glRects(11.5,7.5,15,8);
	glRects(16,7.5,19,8);
	glColor3f(0.5,0.5,0.5);
	glRects(4.5,8.5,18.5,10);
	glColor3f(0.9,0.5,0.2);
	glRects(5.5,12.9,7,13.5);
	glRects(8.5,12.9,10,13.5);
	glRects(11.5,12.9,13,13.5);
	glRects(14.5,12.9,16,13.5);
	glColor3f(1.0,0.0,0.0);
	glRects(5.5,10,7,12.9);
	glRects(8.5,10,10,12.9);
	glRects(11.5,10,13,12.9);
	glRects(14.5,10,16,12.9);
	float t[2][3]={{5.5,6.5,6.2},{10,11,10.8}};
	for(i=1.5;i<=21.5;i+=2){
	glBegin(GL_LINE_LOOP);
		glVertex2f(i,t[0][0]);
		glVertex2f(i,t[0][1]);
		glVertex2f(i+0.5,t[0][2]);
		glVertex2f(i+1.5,t[0][2]);
		glVertex2f(i+2,t[0][1]);
		glVertex2f(i+2,t[0][0]);
	glEnd();
	}
	glColor3f(1.0,1.0,1.0);
	for(i=4.5;i<=19.5;i+=2.5) glRects(i,3.5,i+1,4.5);
	glColor3f(0.9,0.0,0.2);
	for(i=5;i<=15;i+=2){
		glBegin(GL_LINE_LOOP);
		glVertex2f(i,t[1][0]);
		glVertex2f(i,t[1][1]);
		glVertex2f(i+0.5,t[1][2]);
		glVertex2f(i+1.5,t[1][2]);
		glVertex2f(i+2,t[1][1]);
		glVertex2f(i+2,t[1][0]);
	glEnd();
	}
}
void buttons(){
	glColor3f(0,0,0);
	glPointSize(55);
	glDisable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	if(frame>1) glVertex2i(882,50);
	if(frame<4) glVertex2i(948,50);
	glEnd();
	glEnable(GL_POINT_SMOOTH);
	glColor3f(1,1,1);
	glBegin(GL_TRIANGLES);
	if(frame>1){
		glVertex2i(870,50);
		glVertex2i(890,70);
		glVertex2i(890,30);
	}
	if(frame<4){
		glVertex2i(940,70);
		glVertex2i(940,30);
		glVertex2i(960,50);
	}	
	glEnd();
}	
void win0() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
drawText(200, 850, 1,1,1,  " ");
drawText(350,950,1,1,1,"BANGALORE INSTITUTE OF TECHNOLOGY");
drawText(280,900,1,1,1,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
drawText(300, 830, 1,1,1,  "PROJECT THEME: ");
drawText(450, 830, 1,1,1, "HUMAN INTERACTION WITH NATURE");
drawText(200, 780, 1,1,1,  "PROJECT TITLE: ");
drawText(340, 780, 1,1,1, "SAVING THE EARTH SEED BY SEED: THE STORY OF HILDA HAMLIN");
drawText(190, 660, 1,1,1, "PAVITHRA S");
drawText(190, 620, 1,1,1, "1BI16CS095");
drawText(600, 660, 1,1,1, "RAJASREE JAYARAM");
drawText(600, 620, 1,1,1, "1BI16CS114");
drawText(400.0, 500.0, 1,1,1, "UNDER THE GUIDANCE OF");
drawText(100.0, 390.0, 1,1,1, "Prof. K J Bhanushree");
drawText(100.0, 350.0, 1,1,1, "Assistant Professor, Dept of CSE");
drawText(100.0, 320, 1,1,1,  "Bangalore Institute of Technology, Bangalore");
drawText(650.0, 390.0, 1,1,1, "Prof. K N Prashanth");
drawText(650.0, 350.0, 1,1,1, "Assistant Professor, Dept of CSE");
drawText(650.0, 320, 1,1,1,  "Bangalore Institute of Technology, Bangalore");
drawText(450,140,1,1,1,"Use numbers or on-screen buttons to switch between slides, press 'q' to quit");
buttons();
glFlush();
}
void display1()     
{   	
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(stars);
	glPushMatrix();
	glTranslated(a,70,0.0);
	ship();
	glPopMatrix();
	water();
	buttons();
	drawText(t,800,1,1,1, "In 1904, Hilda Edwards travelled from Bristol, England to stay with her uncle in Maine, USA");
}
void display2()
{
	glClearColor(0.6,0.8,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	
	glCallList(bg);
	buttons();
}
void update1(int value)
{
	if(a<1000&&frame==1){
	a+=50.0;
	w-=50;
	if(flag%2==0)t+=40;
	flag++;
	if(t>400) t=10;
	if(w<=-80) w=0;	
	display1();
	glFlush();
	glutTimerFunc(350,update1,0);
	}
}
void update2(int f){
	if(frame==2){
		display2();
		glColor3f(0.9,0.9,0.9);
		if(f>0)
			circle(130,890,15);//smoke
		if(f>1)
			circle(150,910,25);//smoke
		if(f>2){
			circle(170,940,35);//smoke
			 f=0;
			}
		glCallList(text2);
		glFlush();	
		glutTimerFunc(500,update2,f+1);
	}
}
void update3(int f){
	if(frame==3){
	display2();
	h-=90;
	if(h<-550)h=0;
	glPushMatrix();
		glTranslated(h,0,0);
		hilda();
		seeds();
	glPopMatrix();
	glCallList(text3);
		glFlush();	
		glutTimerFunc(800,update3,f+1);
	}
}
void update4(int f){
	if(frame==4){
	display2();
	if(f>0){
		glPushMatrix();
		glScalef(0.7,0.7,1);
		rf();
		glPopMatrix();
	}
	if(f>1)
		rf();
	if(f>2){
		glPushMatrix();
		glScalef(1.2,1.2,1);
		rf();
		glPopMatrix();
		f=0;
	}
	glCallList(text4);
	glFlush();	
	glutTimerFunc(700,update4,f+1);
	}
}
void display(){
	switch(frame){
		case 0: win0();
			break;
		case 1:	a=0;
			w=0;
			t=50;
			flag=0;
			update1(0);	
			break;
		case 2: update2(0);
			break;
		case 3:	update3(0);
			break;
		case 4:	update4(1);
			break;
	}
}
void Normalkey(unsigned char k, int x, int y)
{
	switch (k)
	{
		case '1':frame=1;
			break;
		case '2':frame=2;
			break;
		case '3':frame=3;
			break;
		case '4':frame=4;
			break;
		case 'q': exit(0);
	}
	display();
}
void mouse(int b,int s,int x,int y){
	if(b==GLUT_LEFT_BUTTON&&s==GLUT_DOWN){
		if((x>1270&&x<1320)&&(y>740&&y<790)&&frame>1) {
			frame--;
			glutPostRedisplay();
		}
		if((x>1365&&x<1420)&&frame<4) {
			frame++;
			glutPostRedisplay();
		}
	}
}
void init(){
glNewList(bg, GL_COMPILE);
	bu();
	road();
	soil();
glEndList();
glNewList(stars, GL_COMPILE);
	glPointSize(7);
	glColor3f(1,1,1);
	int i,x,y;
	glBegin(GL_POINTS);
	for(i=0;i<170;i++){
		x=rand()%999;
		y=rand()%999;
		glVertex2i(x,y);
	}
	glEnd();
glEndList();
glNewList(text2, GL_COMPILE);
drawText(300,930,0,0,0,"In the rapidly industrializing country, she found herself"); 
drawText(310,860,0,0,0,"longing for the greenery of the English countryside.");
glEndList();
glNewList(text3, GL_COMPILE);
drawText(320,930,0,0,0,"Hilda imported lupine seeds from her native county.");
drawText(240,860,0,0,0, "She put them in her pocket and began secretly planting them along the roadside.");
glEndList();
glNewList(text4, GL_COMPILE);
drawText(260,930,0,0,0,"The lupines flourished, bringing beauty and verdancy to the land.");
drawText(180,860,0,0,0," Her friends fondly gave her the title of Lupine Lady, and this is the name she is remembered by");
glEndList();
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0, 999, 0, 999);
glGenTextures(1, &texture1);
glBindTexture(GL_TEXTURE_2D, texture1);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
stbi_set_flip_vertically_on_load(true);
unsigned char *data=stbi_load("s1.jpg",&width,&height,&nrc,0);
if(data)
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
else printf("Error");
stbi_image_free(data);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_SINGLE);
glutInitWindowSize(1500, 750);
glutCreateWindow("CG Project");
init();
glutDisplayFunc(display);
glutKeyboardFunc(Normalkey);
glutMouseFunc(mouse);
glutMainLoop();
}

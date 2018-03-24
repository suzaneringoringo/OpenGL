#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>   // freeglut.h might be a better alternative, if available.

void display() {  // Display function will draw the image.

	glClearColor(0, 0, 0, 1);  // (In fact, this is the default.)
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glColor3f(0, 0, 1); // Blue
	glVertex2f(-1, -0.5);
	glColor3f(0, 1, 0); // Green
	glVertex2f(0, -0.5);
	glColor3f(1, 0, 0); // Red
	glVertex2f(-0.5, 0.5);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); // Blue
	glVertex2f(0, -0.5);
	glVertex2f(1, -0.5);
	glVertex2f(0.5, 0.5);
	glEnd();

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

} 

int main(int argc, char** argv) {  // Initialize GLUT and 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);    // Use single color buffer and no depth buffer.
	glutInitWindowSize(800, 800);         // Size of display area, in pixels.
	glutInitWindowPosition(100, 100);     // Location of window in screen coordinates.
	glutCreateWindow("GL RGB Triangle"); // Parameter is window title.
	glutDisplayFunc(display);            // Called when the window needs to be redrawn.

	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;

}

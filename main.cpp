#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>   // freeglut.h might be a better alternative, if available.

void display() {  // Display function will draw the image.

	glClearColor(0, 0, 0, 1);  // (In fact, this is the default.)
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(0.73, 0.87, 0.98);
	glVertex2f(1, 0);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, 0);

	glColor3f(0.93, 0.93, 0.93);
	glVertex2f(1, 0);
	glVertex2f(1, -1);
	glVertex2f(-1, -1);
	glVertex2f(-1, 0);

	float leftest = -0.9;
	float uppest = -0.45;
	float patternWidth = 0.3;
	float patternHeight = 0.1;

	while (leftest < 1) {
		if ((leftest + 0.1) < 1) {
			glColor3f(1, 1, 1);
			glVertex2f(leftest, uppest);
			glVertex2f(leftest + patternWidth, uppest);
			glVertex2f(leftest + patternWidth, uppest - patternHeight);
			glVertex2f(leftest, uppest - patternHeight);
		}
		else {
			glColor3f(1, 1, 1);
			glVertex2f(leftest, uppest);
			glVertex2f(1, uppest);
			glVertex2f(1, uppest - patternHeight);
			glVertex2f(leftest, uppest - patternHeight);
		}
		leftest = leftest + 0.4;
	}

	glEnd();

	glutSwapBuffers(); // Required to copy color buffer onto the screen.

} 

int main(int argc, char** argv) {  // Initialize GLUT and 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);    // Use single color buffer and no depth buffer.
	glutInitWindowSize(600, 600);         // Size of display area, in pixels.
	glutInitWindowPosition(100, 100);     // Location of window in screen coordinates.
	glutCreateWindow("GL Asoy Geboy"); // Parameter is window title.
	glutDisplayFunc(display);            // Called when the window needs to be redrawn.

	glutMainLoop(); // Run the event loop!  This function does not return.
					// Program ends when user closes the window.
	return 0;

}

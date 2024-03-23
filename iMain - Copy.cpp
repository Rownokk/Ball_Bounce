#include "iGraphics.h"
#define screenWidth 700
#define screenHeight 700

int rd = 20, rd1 = 20;
int count = 0;

float x = rd, y = 350;
float dx = 0.2, dy = 0.2;

float x_1 = 350, y_1 = rd1;
float dx_1 =0.2, dy_1 =0.2;

// Collision detection function
int col() {
    if ((x + rd + rd1 > x_1 && x < x_1 + rd1 + rd) && (y + rd + rd1 > y_1 && y < y_1 + rd1 + rd))
        return 1;
    else
        return 0;
}

void iDraw() {
    iClear();

    iSetColor(47, 168, 124);
    iFilledCircle(x, y, rd, 1000);

    iSetColor(117, 140, 224);
    iFilledCircle(x_1, y_1, rd1, 1000);

    // Move the first ball from left to right
    x += dx;
    if (x >= screenWidth - rd || x <= rd) {
        dx *= (-1);
    }

    // Move the second ball from up to down
    y_1 += dy_1;
    if (y_1 >= screenHeight - rd1 || y_1 <= rd1) {
        dy_1 *= (-1);
    }

    // Check for collision and update count
    if (col() == 1) {
        count++;
        printf("%d\n", count);
    }
}

void iMouseMove(int mx, int my) {
    // Empty function for mouse movement
}

void iPassiveMouseMove(int mx, int my) {
    // Empty function for passive mouse movement
}

void iMouse(int button, int state, int mx, int my) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Empty function for left mouse click
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Empty function for right mouse click
    }
}

void iKeyboard(unsigned char key) {
    if (key == 97) {
        // Empty function for 'a' key press
    }
    if (key == 98) {
        // Empty function for 'b' key press
    }
}

void iSpecialKeyboard(unsigned char key) {
    if (key == GLUT_KEY_RIGHT) {
        // Empty function for right arrow key press
    }
    if (key == GLUT_KEY_LEFT) {
        // Empty function for left arrow key press
    }

    if (key == GLUT_KEY_UP) {
        // Empty function for up arrow key press
    }
    if (key == GLUT_KEY_DOWN) {
        // Empty function for down arrow key press
    }
}

int main() {
    iInitialize(screenWidth, screenHeight, "Ball_Bounce");
    return 0;
}

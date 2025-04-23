#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <time.h>

#define PI 3.14159

void drawSolarSystem(int zoom, int angles[]) {
    cleardevice();
    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int sunRadius = 30 * zoom;
    
    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(centerX, centerY, sunRadius, sunRadius);

    int numPlanets = 8;
    int planetRadius[] = {6, 8, 10, 12, 14, 16, 18, 20};
    int orbitRadius[] = {50, 80, 120, 160, 200, 250, 300, 350};
    int speed[] = {5, 4, 3, 2, 2, 1, 1, 1};
    int colors[] = {LIGHTGRAY, LIGHTBLUE, LIGHTGREEN, RED, BROWN, CYAN, BLUE, LIGHTRED};
    int tilt = 40; // Tilt angle for elliptical orbits

    for (int i = 0; i < numPlanets; i++) {
        angles[i] = (angles[i] + speed[i]) % 360;
        double radian = angles[i] * (PI / 180.0);
        int x = centerX + (orbitRadius[i] * zoom) * cos(radian);
        int y = centerY + ((orbitRadius[i] * zoom) * sin(radian) * cos(tilt * PI / 180.0));
        
        setcolor(WHITE);
        ellipse(centerX, centerY, 0, 360, orbitRadius[i] * zoom, (orbitRadius[i] * zoom) * cos(tilt * PI / 180.0));
        setcolor(colors[i]);
        setfillstyle(SOLID_FILL, colors[i]);
        fillellipse(x, y, planetRadius[i] * zoom, planetRadius[i] * zoom);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    int zoom = 1;
    char ch;
    int angles[8] = {0};

    while (1) {
        drawSolarSystem(zoom, angles);
        delay(50);
        if (kbhit()) {
            ch = getch();
            if (ch == '+') zoom++;
            else if (ch == '-' && zoom > 1) zoom--;
            else if (ch == 27) break; // ESC to exit
        }
    }
    
    closegraph();
    return 0;
}

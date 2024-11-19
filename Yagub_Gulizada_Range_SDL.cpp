#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

#include <cmath>

void initOpenGL(int width, int height) {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void drawScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-10.0f, -10.0f);
        glVertex2f(10.0f, -10.0f);
        glVertex2f(10.0f, 10.0f);
        glVertex2f(-10.0f, 10.0f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(-10.0f, 0.0f);
        glVertex2f(10.0f, 0.0f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(10.0f, 0.0f);
        glVertex2f(9.3f, 0.3f);
        glVertex2f(9.3f, -0.3f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, -10.0f);
        glVertex2f(0.0f, 10.0f);
    glEnd();


    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 10.0f);
        glVertex2f(0.3f, 9.3f);
        glVertex2f(-0.3f, 9.3f);
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
        for (float x = -10.0f; x <= 10.0f; x += 0.1f) {
            float y = std::pow(x, 2);
            glVertex2f(x, y);
        }
    glEnd();


    SDL_GL_SwapBuffers();
}


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    SDL_Surface* screen = SDL_SetVideoMode(800, 600, 32, SDL_OPENGL);
    if (!screen) {
        std::cerr << "SDL SetVideoMode failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    initOpenGL(800, 600);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        drawScene();

        SDL_Delay(16);
    }

    SDL_Quit();
    return 0;
}

#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <vector>

struct Ghost {
    float x, z;
    float dirX, dirZ;
    float r, g, b;
};

struct Dot {
    float x, z;
    bool active;
};

class Game {
public:
    Game();
    ~Game();

    bool Init(int width, int height, const char* title);
    void Run();

private:
    void ProcessInput();
    void Update(float deltaTime);
    void Render();
    
    void DrawCube(float x, float y, float z, float size, float r, float g, float b);
    void DrawSphere(float x, float y, float z, float radius, float r, float g, float b);
    
    bool IsWall(int gridX, int gridZ);

    GLFWwindow* window;
    int screenWidth;
    int screenHeight;

    // Player State
    float pacmanX, pacmanZ;
    float dirX, dirZ;
    float reqDirX, reqDirZ;
    int score;
    int lives;

    // Animation
    float mouthAngle;
    float animationTime;

    // Game Elements
    std::vector<Ghost> ghosts;
    std::vector<Dot> dots;

    static const int MAP_WIDTH = 19;
    static const int MAP_HEIGHT = 20;
    static const int MAP[MAP_HEIGHT][MAP_WIDTH];
};

#endif

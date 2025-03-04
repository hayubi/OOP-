/*Task-06:
Write a program that uses composition to implement a game engine. A game engine is madeup of
several components. For example:
a) Graphics rendering engine
b) Input handler
c) Physics engine
You don’t have to write the logic for how these individual components work.*/

#include <iostream>
using namespace std;

class GraphicsRenderingEngine
{
    public:
        void render()
        {
            cout << "Rendering graphics engine" << endl;
        }
};

class InputHandler
{
    public:
        void handleInput()
        {
            cout << "Handling user input" << endl;
        }
};

class PhysicsEngine
{
    public:
        void runPhyEngine()
        {
            cout << "Running physics engine" << endl;
        }
};

class GameEngine
{
    private:
        GraphicsRenderingEngine gr;
        InputHandler ih;
        PhysicsEngine pe;
    public:
        GameEngine()
        {
            cout << "Starting Game Engine" << endl;
        }

        void runGameEngine()
        {
            cout << "Running Game Engine" << endl;
            gr.render();
            ih.handleInput();
            pe.runPhyEngine();
        }

        ~GameEngine() 
        {
            cout << "Game Engine ended" << endl;
        }
};

int main()
{
    GameEngine engine;
    engine.runGameEngine();
}
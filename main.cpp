#include <GLFW/glfw3.h>
#include "GlutApp.h"
#include "Controller.h"

using namespace std;

int main(int argc,char** argv) {

    GlutApp* app = new GlutApp(argc, argv);

    Controller* myController = new Controller();

    app->setController(myController);

    app->setTitle("Paint App");

    app->run();
    
    return 0;
}
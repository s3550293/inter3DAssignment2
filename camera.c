#include "camera.h"

Camera createCamera(int height, int width){
    Camera camera = {0};
    camera.position.x = 0.0;
    camera.position.y = 0.0;
    camera.position.z = 0.0;
    camera.view.x = 0.0;
    camera.view.y = 0.0;
    camera.view.z = 0.0;
    camera.rotate = 0;
    camera.fov = 75;
    return camera;
}

void updateCamera(){

}

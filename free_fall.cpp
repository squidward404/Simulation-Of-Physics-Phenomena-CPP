#include<iostream>
#include <raylib.h>
using namespace std;

//ball  struct
struct Ball{
const float acceleration=9.8;
double velocity=0;
float time;
};

int main(){
    Ball b1; 
    double y_direction=60;
    int screen_width=800;
    int screen_height=600;
    
InitWindow(screen_width,screen_height,"gravity-simulation");
SetTargetFPS(60);
//event loop
while(WindowShouldClose()==false){
BeginDrawing();
ClearBackground(BLACK);
y_direction+=b1.velocity*(1.0/60.0);
DrawCircle(400,y_direction,50,RED);
b1.velocity+=b1.acceleration*(1.0/60.0);
EndDrawing();
}
CloseWindow();

}

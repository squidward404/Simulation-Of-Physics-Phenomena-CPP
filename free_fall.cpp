#include<iostream>
#include<cmath>
#include <raylib.h>
using namespace std;

//ball class
class Ball{
    public:
const int radius=50;
const float acceleration=9.8;
float velocity=0;
float coefficient_of_restitution=0.8;
float y_direction=60;

//update ball position
void update(int screen_height){
if(velocity==0&&y_direction+radius>=screen_height){
return; //stay at rest
}
velocity+=acceleration*(1.0/3.0);
y_direction+=velocity*(1.0/3.0);
}
//check collusion
void check_collision(int screen_height){
if(y_direction+radius>=screen_height){
y_direction=screen_height-radius;//prevent the ball from sinking by always adjusting the y_direction
velocity*=-coefficient_of_restitution; //reverse the movement direction making it bounce
if(fabs(velocity)<2){
    velocity=0;
}
}
}
};

int main(){
    Ball ball; //instantiating ball object
    int screen_width=800;
    int screen_height=600;
    
InitWindow(screen_width,screen_height,"gravity-simulation");
SetTargetFPS(60);
//event loop
while(WindowShouldClose()==false){
BeginDrawing();
ClearBackground(BLACK);
DrawText("Free-Fall",10,20,30,GREEN);
//print the value of y_direction at every frame
DrawText(TextFormat("y_direction = %.2f",ball.y_direction),10,60,20,WHITE);
//print the value of velocity at every frame
DrawText(TextFormat("velocity = %.2f",ball.velocity),10,90,20,WHITE);
ball.update(screen_height); //update position
ball.check_collision(screen_height); //check collusion
DrawCircle(400,ball.y_direction,ball.radius,RED); //draw the circle

EndDrawing();
}
CloseWindow();

}

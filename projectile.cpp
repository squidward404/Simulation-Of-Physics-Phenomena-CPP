#include<iostream>
#include<raylib.h>
using namespace std;
int screen_width=900,screen_height=600;
class Ball{
    public:
    int radius=20;
    float V_velocity=0; 
    float H_velocity=300;
    float acceleration=200; 
    float time;
    float centerx=radius;
    float screen_height=600;
    float centery=(screen_height-200)-radius;
   
    void horizontal_motion(){
        time =GetFrameTime();
        centerx+=H_velocity*time;
      
    }
   
    void vertical_motion(){
        time =GetFrameTime();
        V_velocity+=acceleration*time;
        centery+=V_velocity*time;
    }
    void check_collision(){
     if(centery+radius>=screen_height){
      centery=screen_height-radius;
     }   
    }
};
class Wall{
    public:
    float width=100;
    float height=200;
    float xposition=0;
    float yposition=screen_height-height;
};
int main(){
Ball ball;
Wall wall;
InitWindow(screen_width,screen_height,"horizontal projection");
SetTargetFPS(60);
while(WindowShouldClose()==false){
BeginDrawing();
ClearBackground(BLACK);
DrawRectangle(wall.xposition,wall.yposition,wall.width,wall.height,GRAY);
DrawCircle(ball.centerx,ball.centery,ball.radius,RED);
ball.vertical_motion();
ball.horizontal_motion();
ball.check_collision();
DrawText("Projectile",10,20,30,GREEN);
DrawText(TextFormat("horizontal velocity = %.2f",ball.H_velocity),10,60,20,WHITE);
DrawText(TextFormat("vertical velocity = %.2f",ball.V_velocity),10,90,20,WHITE);
EndDrawing();
}
CloseWindow();
}
#include<iostream>
#include<raylib.h>
using namespace std;

class Ball{
    public:
    float radius;
    float velocity;
    float mass;
    float centerx,centery;
    void Draw(){
        DrawCircle(centerx,centery,radius,RED);
    }
    //move ball1
    void Update(){
     centerx+=velocity;
     
    }
    };

int main(){
    //instantiation
    Ball ball1;
    Ball ball2;
int screen_width=800;
int screen_height=400;
InitWindow(screen_width,screen_height,"linear-collision");
SetTargetFPS(60);

/*initializations*/
//ball 1
ball1.radius=40;
ball1.velocity=5;
ball1.mass=6;
ball1.centery=screen_height-ball1.radius;
ball1.centerx=ball1.radius;
//ball 2
ball2.radius=20;
ball2.velocity=0;
ball2.mass=3;
ball2.centery=screen_height-ball2.radius;
ball2.centerx=(screen_width)/2-ball2.radius;

//event loop
while(WindowShouldClose()==false){
   BeginDrawing();
   ClearBackground(BLACK);
   /*main code*/
DrawText("Linear-Collision",10,20,30,GREEN);
//print the value of ball velocities at every frame
DrawText(TextFormat("Velocity Ball 1 = %.2f",ball1.velocity),10,60,20,WHITE);
DrawText(TextFormat("Velocity Ball 2 = %.2f",ball2.velocity),10,90,20,WHITE);
ball1.Draw();
ball2.Draw();

//collision check,assuming it's a perfectly elastic collision.
bool collided=false;
if(!collided &&ball1.centerx + ball1.radius >= ball2.centerx - ball2.radius){
    collided=true;
    ball1.velocity=((ball1.mass-ball2.mass)*ball1.velocity+(2*ball2.mass*ball2.velocity))/(ball1.mass+ball2.mass);
    ball2.velocity=((ball2.mass-ball1.mass)*ball2.velocity+(2*ball1.mass*ball1.velocity))/(ball1.mass+ball2.mass);
}
//update position after collision
ball1.Update();
ball2.Update();
  EndDrawing();
}
CloseWindow();
}
#include<stdio.h>
#include"raylib.h"

Color Green = {38, 185, 154, 255 };
Color Dark_Green = { 20,160,133,255 };
Color Light_Green = { 129,204,184,255 };
Color Red = {255, 0, 0 ,255 };


int player_score = 0;
int cpu_score =0;

typedef struct Ball
{
    float x,y;
    int speed_x,speed_y;
    int radius;
}Ball;
void Draw(Ball b)
{
    DrawCircle(b.x,b.y,b.radius,Red);
}

void ResetBall(Ball* ball)
{
    ball->x = GetScreenWidth()/2;
    ball->y = GetScreenHeight()/2;
    int choice[2] = {-1,1};
    ball->speed_x *= choice[GetRandomValue(0,1)];
    ball->speed_y *= choice[GetRandomValue(0,1)];
}
void Update(Ball* b)
{
    b->x += b->speed_x;
    b->y += b->speed_y;

    if(b->y + b->radius >= GetScreenHeight() || b->y - b->radius <=0)
    {
        b->speed_y *= -1;
    }
    if(b->x + b->radius >= GetScreenWidth())
    {
       cpu_score++;
       ResetBall(b);
    } 
    if(b->x - b->radius <=0 )
    {
        player_score++;
        ResetBall(b);
    }
}

typedef struct Paddle
{
    float x,y;
    int speed_y;
    int Width,Height;

}Paddle;
void DrawPaddle(Paddle p)
{
    Rectangle rec = {p.x,p.y,p.Width,p.Height};
    DrawRectangleRounded(rec,0.8,0,WHITE);
}

void UpdatePaddle(Paddle* p)
{
    if(IsKeyDown(KEY_UP))
    {
        p->y -= p->speed_y;
    }
    if(IsKeyDown(KEY_DOWN))
    {
        p->y += p->speed_y;
    }
    if(p->y <= 0)
    {
        p->y = 0;
    }
    if(p->y + p->Height >= GetScreenHeight())
    {
        p->y = GetScreenHeight() - p->Height;
    }
}

void UpdateCpu(Paddle* cpu,int ball_y)
{
   if(cpu->y + cpu->Height/2 >= ball_y)
   {
      cpu->y -= cpu->speed_y;
   }
   if(cpu->y + cpu->Height/2 <= ball_y)
   {
      cpu->y += cpu->speed_y;
   }  
    if(cpu->y <= 0)
    {
        cpu->y = 0;
    }
    if(cpu->y + cpu->Height >= GetScreenHeight())
    {
        cpu->y = GetScreenHeight() - cpu->Height;
    }    
}


Ball ball;
Paddle player;
Paddle cpu;


int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "Vignesh's - Pong Game");
    SetTargetFPS(60);

    ball.x = screenWidth/2;
    ball.y = screenHeight/2;
    ball.radius = 15;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.Height = 120;
    player.Width = 25;
    player.x = screenWidth - player.Width -10;
    player.y = screenHeight/2 - player.Height/2;
    player.speed_y = 6;

    cpu.Height = 120;
    cpu.Width = 25;
    cpu.x = 0;
    cpu.y = screenHeight/2 - player.Height/2;
    cpu.speed_y = 6;


    while(!WindowShouldClose())
    {
        BeginDrawing();

        Update(&ball);
        UpdatePaddle(&player);
        UpdateCpu(&cpu,ball.y);

        Vector2 vect = { ball.x, ball.y };
        Rectangle Rect = { player.x, player.y, player.Width, player.Height };
        Rectangle RectCPU = { cpu.x, cpu.y, cpu.Width, cpu.Height };

        if (CheckCollisionCircleRec(vect, ball.radius, Rect) || CheckCollisionCircleRec(vect, ball.radius, RectCPU)) {
            ball.speed_x *= -1;
        }

       ClearBackground(Dark_Green);
       DrawRectangle(screenWidth/2,0,screenWidth/2,screenHeight,Green);
       DrawCircle(screenWidth/2,screenHeight/2,150,Light_Green);
       DrawPaddle(cpu);
       DrawPaddle(player);
       Draw(ball);
       DrawLine(screenWidth/2,0,screenWidth/2,screenHeight,WHITE);

       DrawText(TextFormat("%i",cpu_score),screenWidth/4 - 20,20,80,WHITE);
       DrawText(TextFormat("%i",player_score), 3*screenWidth/4 - 20,20,80,WHITE);
       EndDrawing();
    }
    CloseWindow();
    return 0;
}
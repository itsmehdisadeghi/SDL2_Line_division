#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>

using namespace std;

#define length 600
#define width 400


int Top_point(int coor[4][2])
{
    int res_num;
    int temp = width;
    int i = 0;
    while(i!=4)
    {
        if (coor[i][1] < temp)
        {
            temp = coor[i][1];
            res_num = i;
        }
        i+=1;
    }
    return res_num;
}

int Right_point(int coor[4][2])
{
    int res_num;
    int temp = 0;
    int i = 0;
    while(i!=4)
    {
        if (coor[i][0] > temp)
        {
            temp = coor[i][0];
            res_num = i;
        }
        i+=1;
    }
    return res_num;
}

int Left_point(int coor[4][2])
{
    int res_num;
    int temp = length;
    int i = 0;
    while(i!=4)
    {
        if (coor[i][0] < temp)
        {
            temp = coor[i][0];
            res_num = i;
        }
        i+=1;
    }
    return res_num;
}



int main(int argc, char ** argv)
{
    int n , coordinates[4][2];

    cout << "enter n : ";
    cin >> n;
    int i = 0;
    while(i!=4)
    {
        cout << "enter coordinate "<<i+1<< " : ";
        cin >> coordinates[i][0] >> coordinates[i][1];
        i+=1;
    }


    int top_point = Top_point(coordinates);
    int right_point = Right_point(coordinates);
    int left_point = Left_point(coordinates);
    int middle_point = 6 - (top_point + right_point + left_point);

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window * window = SDL_CreateWindow("TALES",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, length, width, SDL_WINDOW_SHOWN);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0,0, 0, 255);
    SDL_RenderDrawLine(renderer, coordinates[top_point][0], coordinates[top_point][1],coordinates[left_point][0], coordinates[left_point][1]);
    SDL_RenderDrawLine(renderer, coordinates[top_point][0], coordinates[top_point][1],coordinates[right_point][0], coordinates[right_point][1]);
    SDL_RenderDrawLine(renderer, coordinates[top_point][0], coordinates[top_point][1],coordinates[middle_point][0], coordinates[middle_point][1]);
    SDL_RenderDrawLine(renderer, coordinates[middle_point][0], coordinates[middle_point][1],coordinates[left_point][0], coordinates[left_point][1]);
    SDL_RenderDrawLine(renderer, coordinates[middle_point][0], coordinates[middle_point][1],coordinates[right_point][0], coordinates[right_point][1]);



    int templ1[2] = {coordinates[left_point][0], coordinates[left_point][1]};
    int templ2[2] = {coordinates[middle_point][0], coordinates[middle_point][1]};
    int templ3[2] = {coordinates[right_point][0], coordinates[right_point][1]};

    i = 1;
    while(n!=i)
    {
        templ1[0] += (abs((coordinates[top_point][0] - coordinates[left_point][0])))/n;
        templ1[1] -= (abs((coordinates[left_point][1] - coordinates[top_point][1])))/n;
        if (coordinates[top_point][0]>= coordinates[middle_point][0])
        {
            templ2[0] += (abs((coordinates[top_point][0] - coordinates[middle_point][0])))/n;
        }
        else
        {
            templ2[0] -= (abs((coordinates[top_point][0] - coordinates[middle_point][0])))/n;
        }
        templ2[1] -= (abs((coordinates[middle_point][1] - coordinates[top_point][1])))/n;

        templ3[0] -= (abs((coordinates[right_point][0] - coordinates[top_point][0])))/n;
        templ3[1] -= (abs((coordinates[top_point][1] - coordinates[right_point][1])))/n;

        SDL_RenderDrawLine(renderer,templ2[0] , templ2[1], templ1[0], templ1[1]);
        SDL_RenderDrawLine(renderer,templ2[0] , templ2[1], templ3[0], templ3[1]);

        i+=1;
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(10000);
    return 0;
}

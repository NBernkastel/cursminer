#include <game.h>
#include <callback.c>
#include <logic.c>
#include <draw.c>
int main(){

       if (!glfwInit())
        return -1;

    window = glfwCreateWindow(900, 900, "miner", NULL, NULL);
    if (!window)
    {

        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glTranslatef(-1, 1, 0);
    fortex("source/03.png",0);
    fortex("source/15x15.png",1);
    fortex("source/10x10.png",2);
    fortex("source/12x12.png",3);
    fortex("source/lose.png", 4);
   // PlaySound("Brawlrap.wav", NULL, SND_ASYNC);
    while (!glfwWindowShouldClose(window)) // основной цикл
    {
            glClearColor(0.7f, 1.0f, 0.7f, 0.0f); // задаём фон
            glClear(GL_COLOR_BUFFER_BIT);
            if (gamemode == 0) {
                m_draw(colorchange[0], colorchange[1], colorchange[2], colorchange[3]);
                logic_m();
                text("source/15x15.png");
                text("source/10x10.png");
                text("source/12x12.png");
            }
            if (gamemode == 1) {
                if (gameover != 1 && gameover != 2) { // проверка на поражение
                    FHIGHT = 15;
                    FLENGHT = 15;
                    mincounter = ((FHIGHT * FLENGHT) / 100.0) * 15.0;
                    sdwg = 0.2;
                    logic(mincounter);
                    fielddraw();
                    counter(flag_stay,mincounter, gamemode);
                    if (m_press_first == 1) {
                        m_press_first = 2;
                        startup();
                    }
                }
                if (gameover == 2) 
                    text("source/03.png");
                if (gameover == 1)
                    text("source/lose.png");
            }
            if (gamemode == 2) {
                FHIGHT = 10;
                FLENGHT = 10;
                mincounter = ((FHIGHT * FLENGHT) / 100.0) * 15.0;
                sdwg = 0.5;
                if (gameover != 1 && gameover != 2) { // проверка на поражение
                    logic(mincounter);
                    fielddraw();
                    counter(flag_stay, mincounter, gamemode);
                    if (m_press_first == 1) {
                        startup();
                        m_press_first = 2;
                    }
                    // printf("%f  %f\n",xpos,ypos);
                }
                if (gameover == 2) {
                    text("source/03.png");
                }
                if (gameover == 1)
                    text("source/lose.png");
            }
            else if (gamemode == 3) {
                FHIGHT = 12;
                FLENGHT = 12;
                mincounter = ((FHIGHT * FLENGHT) / 100.0) * 15.0;
                sdwg = 0.4;
                if (gameover != 1 && gameover != 2) { // проверка на поражение
                    logic(mincounter);
                    fielddraw();
                    counter(flag_stay, mincounter, gamemode);
                    if (m_press_first == 1) {
                        startup();
                        m_press_first = 2;
                    }
                    // printf("%f  %f\n",xpos,ypos);
                }
                if (gameover == 2) {
                    text("source/03.png");
                }
                if (gameover == 1)
                    text("source/lose.png");
            }
            else if (gamemode == 4) {
                if (gameover != 1 && gameover != 2) { // проверка на поражение
                    logic(mincounter);
                    fielddraw();
                    counter(flag_stay, mincounter, gamemode);
                    // printf("%f  %f\n",xpos,ypos);
                }
                if (gameover == 2) {
                    text("source/03.png");
                }
                if (gameover == 1)
                    text("source/lose.png");
            }
            if (refresh == 1) {
                startup();
                gameover = 0;
                m_press_first = 0;
            }
            refresh = 0;
            Sleep(5);
            glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
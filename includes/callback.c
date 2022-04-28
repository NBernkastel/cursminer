
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) // проверка на нажатие мыши
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        m_press = 1;
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        m_press = 2;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS) {
        for (int i = 0; i < FLENGHT; i++) { // закрывает все квадраты
            for (int j = 0; j < FHIGHT; j++) {
                field[i][j].is_open = 1;
            }
        }
    }
    if (key == GLFW_KEY_E && action == GLFW_RELEASE) {
        for (int i = 0; i < FLENGHT; i++) { // закрывает все квадраты
            for (int j = 0; j < FHIGHT; j++) {
                field[i][j].is_open = 0;
            }
        }
    }
    if (key == GLFW_KEY_J && action == GLFW_PRESS) {
        if (gamemode == 4) {
            saveload();
            gameover = 0;
        }
        else
        refresh = 1;
    }
    if (key == GLFW_KEY_K && action == GLFW_PRESS) {
        help();
    }
    if (key == GLFW_KEY_M && action == GLFW_PRESS && gameover == 0) {
        FILE* fp = fopen("save.bin", "wb");
        fwrite(&FLENGHT, sizeof(int), 1, fp);
        fwrite(&FHIGHT, sizeof(int), 1, fp);
        fwrite(&mincounter, sizeof(int), 1, fp);
        fwrite(&sdwg, sizeof(float), 1, fp);
        fwrite(&flag_stay, sizeof(int), 1, fp);
        for (int i = 0; i < FLENGHT; i++)
            for (int j = 0; j < FHIGHT; j++) {
                fwrite(&field[i][j].is_open, sizeof(int), 1, fp);
                fwrite(&field[i][j].min, sizeof(int), 1, fp);
                fwrite(&field[i][j].flag, sizeof(int), 1, fp);
                fwrite(&field[i][j].bombs_around, sizeof(int), 1, fp);
            }
        fclose(fp);
        exit(0);
    }
}

#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

short** picture;
short** image;
bool** px_map; 
short px0 = 0, px1 = 1;
int n = 0;

void PrintPicture() {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (picture[i][k] == px0) {
                cout << " -";
            }
            else {
                cout << " #";
            }
        }
        cout << endl;
    }
}
void CreatePicture() {
    picture = new short* [n];
    px_map = new bool* [n];
    for (int i = 0; i < n; i++) {
        picture[i] = new short[n];
        px_map[i] = new bool[n];
        for (int k = 0; k < n; k++) {
            picture[i][k] = px0;
            px_map[i][k] = false;
        }
    }
}
void ClearPicture() {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            picture[i][k] = px0;
            px_map[i][k] = false;
        }
    }
}

void MakeImage(int width, int height) {
    image = new short* [height];
    for (int i = 0; i < height; i++) {
        image[i] = new short[width];
        for (int k = 0; k < width; k++) {
            if (k == 0 && i < height - 2) {//самый левыый
                image[i][k] = px1;
            }
            else if (k == width - 1 && i < height - 2) {//правый край(верхняя половина правого края)
                image[i][k] = px1;
            }
            else if (i == height - 1 && k > 1 && k < width - 2) {//самая верхняя строчка
                image[i][k] = px1;
            }
            else if (k == 1 && i == height - 2)
            {
                image[i][k] = px1;
            }
            else if (k == width - 2 && i == height - 2)
            {
                image[i][k] = px1;
            }
            else {//остальное, заполн нулями
                image[i][k] = px0;
            }
        }
    }
}

bool F(int x, int y, int width, int height) { 
    if (x + width - 1 > n) {
        cout << "Выход за пределы картинки (x)" << endl;
        return false;
    }
    if (y + height - 1 > n) {
        cout << "Выход за пределы картинки (y)" << endl;
        return false;
    }
    for (int i = y; i < y + height; i++) {
        for (int k = x; k < x + width; k++) {
            picture[i][k] = image[i - y][k - x];
        }
    }
    return true;
}

void RandomPicture(int amount) { 
    int countPlaced = 0;
    int random_height, random_width, random_x, random_y; 
    int min_width, min_height = 5;
    int max_width, max_height = sqrt(n * n / (amount + sqrt(amount)));
    bool** isEmptyPx = new bool* [n]; 
    bool canPlace;
    for (int i = 0; i < n; i++)
    {
        isEmptyPx[i] = new bool[n];
        for (int k = 0; k < n; k++)
        {
            isEmptyPx[i][k] = true;
        }
    }
    while (countPlaced < amount)
    {
        canPlace = false;
        random_height = rand() % (max_height - min_height) + min_height;
        min_width = (random_height + 1) / 2;
        max_width = random_height;
        random_width = rand() % (max_width - min_width) + min_width;
        int tries = 0;
        while (!canPlace) 
        {
            if (tries > 100) 
            {
                random_height = rand() % (random_height - min_height) + min_height;
                min_width = (random_height + 1) / 2;
                max_width = random_height;
                random_width = rand() % (max_width - min_width) + min_width;
                tries = 0;
            }
            tries++;
            canPlace = true;
            random_x = rand() % (n - random_width + 1);
            random_y = rand() % (n - random_height + 1);
            for (int i = random_y; i < random_y + random_height; i++)
                for (int k = random_x; k < random_x + random_width; k++)
                    if (isEmptyPx[i][k] == false)
                    {
                        i = n;
                        k = n;
                        canPlace = false;
                    }
        }
        MakeImage(random_width, random_height);
        F(random_x, random_y, random_width, random_height);
        countPlaced++;
        for (int i = random_y - 1; i < n && i <= random_y + random_height; i++)
        {
            if (i < 0)
                i++;
            for (int k = random_x - 1; k < n && k <= random_x + random_width; k++)
            {
                if (k < 0)
                    k++;
                isEmptyPx[i][k] = false;
            }
        }
    }
}

int S() { 
    int imgCounter = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (px_map[i][k] == false && picture[i][k] == px1) 
            {
                int highX = k;
                int highY = i;
                int downX = k;
                int downY = i;
                count += 4; 
                for (bool isAreaClosed = false; !isAreaClosed; )
                {
                    isAreaClosed = true;
                    if (downX < n) 
                        for (int x = downX + 1, y = highY; y < n && y <= downY; y++)
                        {
                            if (picture[y][x] == px1) {
                                downX = x;
                                count += 1;
                                isAreaClosed = false;
                                break;
                            }
                            count++; 
                        }
                    if (highX - 1 >= 0) 
                        for (int x = highX - 1, y = highY + 1; y < n && y <= downY + 1; y++)
                        {
                            if (picture[y][x] == px1) {
                                highX = x;
                                if (downY < y)
                                {
                                    downY = y;
                                    count++;
                                }
                                count += 2;
                                isAreaClosed = false;
                                break;
                            }
                            count++; 
                        }
                    if (downY + 1 < n) 
                        for (int y = downY + 1, x = highX; x <= downX + 1; x++)
                        {
                            if (picture[y][x] == px1) {
                                downY = y;
                                if (downX < x)
                                {
                                    downX = x;
                                    count++; 
                                }
                                count += 2;
                                isAreaClosed = false;
                                break;
                            }
                            count++; 
                        }
                    count += 3; 
                }
                for (int y = highY; y <= downY; y++)
                {
                    for (int x = highX; x <= downX; x++)
                    {
                        px_map[y][x] = true;
                        count++;
                    }
                }
                imgCounter++;
            }
            count += 2;
        }
    }
    return count;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));
    long long sum;
    int amount;
    ofstream file("file_of_image.txt");
    file << "размер изобр" << "\t" << "кол-во изобр" << "\t" << "среднее значение" << "\t" << endl;
    for (n = 100; n <= 1000; n += 100)
    {
        CreatePicture();
        sum = 0;
        amount = n * sqrt(n) / 200;
        for (int k = 0; k < 100; k++)
        {
            ClearPicture();
            RandomPicture(amount);
            sum += S();
        }
        double mid = sum / (double)100;
        file << fixed  << n << "\t\t" << amount << "\t\t " << mid << endl;
    }
}
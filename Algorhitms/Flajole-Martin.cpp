#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <ctime>

using namespace std;



// 1)генератор случайных URL


string generate_random_URL()
{
    string URL = "";
    static const char a[] = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 10; ++i)
    {
        URL += a[rand() % (size(a) - 1)];
    }
    return URL;
}


// 2)хеш-функция h(x)
int hash_f(const string& url, int N)
{
    int hash = 0;
    for (char c : url)
    {
        hash += c;
    }
    return hash % N;
}

// 3)Считаем ранг p(y)
int make_rank(const string& url, int N)
{
    int rank = 0;
    for (char c : url)
    {
        rank += static_cast<int>(c);
    }
    return rank % N;
}


struct URL
{
    string url;
    int rank;
};

//Ф-М
void run_FM(URL* mu_urls, int am_of_url, int N, int s)
{
    //Генер случайных рангов и URL
    srand(time(nullptr));
    for (int i = 0; i < am_of_url; ++i)
    {
        string url = generate_random_URL();
        int rank = make_rank(url, N);
        mu_urls[i] = { url, rank };
    }
    //сортировка URL по рангам
    sort(mu_urls, mu_urls + am_of_url, [](const URL& a, const URL& b) { return a.rank < b.rank; });
    if (am_of_url > s)
    {
        am_of_url = s;
    }   
}



int main()
{
    int am_of_url = 20;//кол-во URL
    int N = 10;//Кол-во возможных чисел от 0 до N-1
    int s = 5;//Мощность MU потока

    URL* mu_urls = new URL[am_of_url];//массив для URL и их рангов
    run_FM(mu_urls, am_of_url, N, s);


    //вывод
    for (int i = 0; i < am_of_url; ++i)
    {
        cout << "URL: " << mu_urls[i].url << ",Rank: " << mu_urls[i].rank << endl;
    }

    delete[] mu_urls;//освободили память
    return 0;
}


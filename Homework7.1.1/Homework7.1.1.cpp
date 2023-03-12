// Homework7.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <chrono>

class Window
{
protected:
    int max_people = 0;
    int people = 1;
public:
    Window(int max_people_)
    {
        max_people = max_people_;
    }
    void income()
    {
        while (people != max_people)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            ++people;
            std::cout << people << " ";
        }
    }
    void outcome()
    {
        while (people != 0)
        {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            --people;
            std::cout << people << " ";
        }
    }
};

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    int people_num = 5;

    Window window(people_num);

    std::cout << "Current workload: ";
    std::thread t1(&Window::income, &window);
    std::thread t2(&Window::outcome, &window);
    t1.join();
    t2.join();

    return 0;
}
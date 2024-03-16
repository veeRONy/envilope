#include <iostream>
#include"service.h"


int main()
{
    setlocale(LC_ALL, "ru");
    DataProcessorService* service = new DataProcessorService("input.txt", "output.txt");
    service->runService();

    return 0;
}

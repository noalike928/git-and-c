#include <iostream>
#include <stdexcept>
#include <unistd.h>
#include <chrono>
#include <thread>

auto clearScreen = []()
{
    #ifdef _WIN32
  system("cls");
    #else
  system("clear");
    #endif

  // didn,t use the ANSII clear screen way because don,t remember it=_=
};

// shortcut to the long sleep for command
auto wait = [](const int& sec)
{
    if (sec < 0)
    {
        throw std::invalid_argument("cannot handle under 0 seconds");
    }


    std::this_thread::sleep_for(std::chrono::seconds(sec));
};

static const int getUserInput()
{
    int userNum = 0;

    while (true)
    {
      clearScreen();

      std::cout << "Please Enter The Number Of Iterations:";

      if (!(std::cin >> userNum))
      {
        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


        std::cerr << "Can,t Handle None Numerical Types" << std::flush;

        wait(3);

        continue;
      }

      break;
    }

    return (userNum <= 0 ? 0 : userNum);
}

int main()
{
    int userNum = getUserInput();

    for (int i = 0; i <= userNum; ++i)
    {
        std::cout << i << '\n';
    }

    return 0;
}

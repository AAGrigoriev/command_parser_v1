#pragma once
#include <vector>
#include <string>
#include <chrono>

/* Недо паттерн комманда 
   Простая обёртка над временем записи первого запроса и строками
   Не стал добавлять методы, так как в них нету смысла
*/
namespace fileReader
{
struct Command
{
   std::vector<std::string> stringCommand;
   int unixTime;
};

} // namespace fileReader
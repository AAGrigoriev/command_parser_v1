#include "reader.hpp"
#include "time.h"
#include <iostream>

fileReader::Reader::Reader(std::size_t sizeBlock, std::istream &stream) : deep(0), readStream(stream), sizeBlock(sizeBlock) {}

void fileReader::Reader::run()
{
    std::string line;
    while (std::getline(readStream, line))
    {
        if (line == "{")
        {
            if (deep == 0)
                beforeNotify();
            ++deep;
        }
        else if (line == "}")
        {
            if (deep != 0)
                --deep;
            if (!deep)
                beforeNotify();
        }
        else
        {
            // Отлавливаю первый момент записи
            if (command.stringCommand.empty())
            {
                command.unixTime = (unsigned long)time(NULL);
            }

            command.stringCommand.emplace_back(std::move(line));

            if (!deep && command.stringCommand.size() >= sizeBlock)
                beforeNotify();
        }
    }
}

void fileReader::Reader::attach(const std::shared_ptr<IObserver<Command>> &u_ptr)
{
    F_list.push_front(u_ptr);
}

void fileReader::Reader::detach(const std::shared_ptr<IObserver<Command>> &u_ptr)
{
    //F_list.remove(u_ptr);
}

void fileReader::Reader::beforeNotify()
{
    if (!command.stringCommand.empty())
        notify(command);

    command.stringCommand.clear();
}
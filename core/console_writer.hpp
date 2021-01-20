#pragma once 

#include "observer.hpp"
#include <memory>
#include <iostream>

namespace fileReader
{
    class ConsoleWriter : public IObserver<Command>, public std::enable_shared_from_this<ConsoleWriter>
    {
    public:
        virtual void update(const Command &command);

        static std::shared_ptr<ConsoleWriter> create();

    private:
        ConsoleWriter():console(std::cout) {};
        std::ostream& console;
    };

} // namespace fileReader
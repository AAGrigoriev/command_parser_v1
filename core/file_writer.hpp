#pragma once 
#include "Observer.hpp"
#include <fstream>
#include <memory>

namespace fileReader
{
    class FileWriter : public IObserver<Command>,public std::enable_shared_from_this<FileWriter>
    {
    public:
        virtual void update(const Command &command);

        static std::shared_ptr<FileWriter> create();
    private:
        FileWriter() = default;
    };
} // namespace fileReader
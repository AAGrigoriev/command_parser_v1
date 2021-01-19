#pragma once 
#include "Observer.hpp"
#include "SimpleCommand.hpp"
#include <iostream>
#include <memory>

namespace fileReader
{
    class Reader : public ISubject<Command>,public std::enable_shared_from_this<Reader>
    {
    public:

        Reader(std::size_t sizeBlock, std::istream& stream = std::cin);

        void run();

        virtual void attach(const std::shared_ptr<IObserver<Command>>& u_ptr) override;

        virtual void detach(const std::shared_ptr<IObserver<Command>>& u_ptr) override;

        void         beforeNotify();
        
    private:
        std::istream& readStream;
        Command       command;
        int32_t       deep; // deep dark fantasy
        std::size_t   sizeBlock;
    };
} // namespace fileReader
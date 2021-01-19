#include "console_writer.hpp"

void fileReader::ConsoleWriter::update(const Command &command)
{
    console << "bulk : " << command.stringCommand.at(0);

    auto iterBeg = command.stringCommand.begin();
    auto iterEnd = command.stringCommand.end();

    ++iterBeg;

    while (iterBeg != iterEnd)
    {
        console << "," << *iterBeg++;
    }

    console << std::endl;
}

std::shared_ptr<fileReader::ConsoleWriter> fileReader::ConsoleWriter::create()
{
    return std::shared_ptr<ConsoleWriter>(new ConsoleWriter());
}
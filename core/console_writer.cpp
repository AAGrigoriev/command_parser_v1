#include "console_writer.hpp"

void fileReader::ConsoleWriter::update(const Command &command)
{
    auto const &vector = command.getCommand();

    console << "bulk : " << vector.at(0);

    auto iterBeg = vector.begin();
    auto iterEnd = vector.end();

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
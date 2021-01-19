#include "file_writer.hpp"

void fileReader::FileWriter::update(const Command &command)
{
    std::ofstream file_writer("bulk" + std::to_string(command.unixTime) + ".log");

    if (!file_writer.is_open()) return;
    
        file_writer << "bulk : " << command.stringCommand.at(0);

        auto iterBeg = command.stringCommand.begin();
        auto iterEnd = command.stringCommand.end();
        ++iterBeg;

        while (iterBeg != iterEnd)
        {
            file_writer << " ," << *iterBeg++;
        }
        file_writer << std::endl;
    
    file_writer.close();
}

std::shared_ptr<fileReader::FileWriter> fileReader::FileWriter::create()
{
    return std::shared_ptr<FileWriter>(new FileWriter());
}

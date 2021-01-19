#include "console_writer.hpp"
#include "file_writer.hpp"
#include "reader.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "N :\n  " << argv[0];
        return EXIT_FAILURE;
    }

    std::cout << argv[1] << std::endl;

    fileReader::Reader lineReader(std::stoul(argv[1]));
    auto file_writer  = fileReader::FileWriter::create();
    auto file_writer2 = fileReader::FileWriter::create();

    std::cout << "\n";

    std::cout << file_writer.use_count() << std::endl;

    std::cout << file_writer2.use_count() << std::endl;

    //auto console_writer = fileReader::ConsoleWriter::create();
    //lineReader.attach(file_writer);
    //lineReader.attach(console_writer);
    //lineReader.run();
    return 0;
}
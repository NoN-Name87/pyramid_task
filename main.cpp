#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
#include <vector>
#include <queue>

const std::string EXTRACT = "EXTRACT";
const std::string ADD = "ADD";
const std::string CLEAR = "CLEAR";

enum class Command
{
    EXTRACT,
    ADD,
    CLEAR,
    ERROR
};

Command get_command_type(std::string cmd, size_t cmd_size, size_t pyramid_size)
{
    Command cmd_type = Command::ERROR;
    if(cmd == EXTRACT && cmd_size == 1 && pyramid_size)
        cmd_type = Command::EXTRACT;
    else if(cmd == ADD && cmd_size == 2)
        cmd_type = Command::ADD;
    else if(cmd == CLEAR && cmd_size == 1)
        cmd_type = Command::CLEAR;
    return cmd_type;
}

void operate_pyramid()
{
    std::cout << "COMMAND:\n";
    std::priority_queue<int> pyramid;
    std::string temp;
    while(std::getline(std::cin, temp))
    {
        std::stringstream line(temp);
        std::istream_iterator<std::string> begin(line);
        std::istream_iterator<std::string> end;
        std::vector<std::string> cmd(begin, end);
        Command cmd_type = get_command_type(*begin, cmd.size(), pyramid.size());
        switch(cmd_type)
        {
            case Command::EXTRACT:
                std::cout << pyramid.top() << "\n";
                pyramid.pop();
                break;
            case Command::ADD:
                pyramid.push(std::stoi(cmd.back()));
                break;
            case Command::CLEAR:
                std::priority_queue<int>().swap(pyramid);
                break;
            case Command::ERROR:
                std::cout << "CANNOT\n";
        }
    }
}

int main(int argc, char **argv)
{
    try
    {
        operate_pyramid();
    }
    catch(const std::exception & except)
    {
        std::cout << except.what() << "\n";
    }
}
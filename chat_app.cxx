
#include <iostream>
#include <string>
using namespace std;

#include <dds/dds.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/util/util.hpp>
#include "chat.hpp"


int main(int argc, char* argv[])
{
    string username, group;
    string firstName, lastName;
    const int domain_id = 10;

    if (argc < 3) {
        cerr << "Usage: chat_app username group [firstName] [lastName]" << endl;
        return -1;
    }
    username = string(argv[1]);
    group = string(argv[2]);
    if (argc >= 4)
        firstName = string(argv[3]);
    if (argc >= 5)
        lastName = string(argv[4]);
}
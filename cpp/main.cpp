#include <iostream>
#include "ossie/ossieSupport.h"

#include "messageproducer.h"
int main(int argc, char* argv[])
{
    messageproducer_i* messageproducer_servant;
    Component::start_component(messageproducer_servant, argc, argv);
    return 0;
}


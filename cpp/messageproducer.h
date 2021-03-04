#ifndef MESSAGEPRODUCER_I_IMPL_H
#define MESSAGEPRODUCER_I_IMPL_H

#include "messageproducer_base.h"

class messageproducer_i : public messageproducer_base
{
    ENABLE_LOGGING
    public:
        messageproducer_i(const char *uuid, const char *label);
        ~messageproducer_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // MESSAGEPRODUCER_I_IMPL_H

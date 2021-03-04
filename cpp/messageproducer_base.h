#ifndef MESSAGEPRODUCER_BASE_IMPL_BASE_H
#define MESSAGEPRODUCER_BASE_IMPL_BASE_H

#include <boost/thread.hpp>
#include <ossie/Component.h>
#include <ossie/ThreadedComponent.h>

#include <ossie/MessageInterface.h>
#include "struct_props.h"

class messageproducer_base : public Component, protected ThreadedComponent
{
    public:
        messageproducer_base(const char *uuid, const char *label);
        ~messageproducer_base();

        void start() throw (CF::Resource::StartError, CORBA::SystemException);

        void stop() throw (CF::Resource::StopError, CORBA::SystemException);

        void releaseObject() throw (CF::LifeCycle::ReleaseError, CORBA::SystemException);

        void loadProperties();

    protected:
        // Member variables exposed as properties
        /// Message structure definition for Component_Members
        Component_Members_struct Component_Members;

        // Ports
        /// Port: message_out
        MessageSupplierPort *message_out;

    private:
};
#endif // MESSAGEPRODUCER_BASE_IMPL_BASE_H

#include "messageproducer_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

messageproducer_base::messageproducer_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    //setThreadName(label);

    loadProperties();

    message_out = new MessageSupplierPort("message_out");
    //message_out->setLogger(this->_baseLog->getChildLogger("message_out", "ports"));
    addPort("message_out", message_out);
}

messageproducer_base::~messageproducer_base()
{
    message_out->_remove_ref();
    message_out = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void messageproducer_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void messageproducer_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void messageproducer_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void messageproducer_base::loadProperties()
{
    addProperty(Component_Members,
                Component_Members_struct(),
                "Component_Members",
                "",
                "readwrite",
                "",
                "external",
                "message");

}




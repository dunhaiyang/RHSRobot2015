/**  Example of subsystem task behavior.
 *
 * This class is derived from the standard Component base class and includes
 * initialization for the devices used to control a given subsystem.
 *
 * The task receives messages from the main robot class and implements behaviors
 * for a given subsystem.
 */

#include "WPILib.h"

//Robot
#include "ComponentBase.h"
#include "RobotParams.h"

//Local
#include "Component.h"

Component::Component()
: ComponentBase(COMPONENT_TASKNAME, COMPONENT_QUEUE, COMPONENT_PRIORITY)
{
	pTask = new Task(COMPONENT_TASKNAME, (FUNCPTR) &Component::StartTask,
			COMPONENT_PRIORITY, COMPONENT_STACKSIZE);
	wpi_assert(pTask);
	pTask->Start((int)this);
};

Component::~Component()
{
	delete(pTask);
};

void Component::OnStateChange()	
{
};

void Component::Run()
{
	switch(localMessage.command)			//Reads the message command
	{
		case COMMAND_COMPONENT_TEST:
			break;

		default:
			break;
		}
};

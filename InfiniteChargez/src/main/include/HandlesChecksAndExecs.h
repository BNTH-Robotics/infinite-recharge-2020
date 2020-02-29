#ifndef YEET_CHECKS_AND_EXECS

#define YEET_CHECKS_AND_EXECS

#include "InputHandler.h"



namespace utilities

{

    class HandlesChecksAndExecs
    {
    public:

    /**

     * Check for input and execute actions

     */

    virtual void checkAndExec() = 0;

    virtual InputHandler& getInputHandler() = 0;

    virtual ~HandlesChecksAndExecs() {}

    };

}
#endif

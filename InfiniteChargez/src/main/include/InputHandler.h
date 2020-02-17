#ifndef YEET_INPUT_HANDLER_H
#define YEET_INPUT_HANDLER_H
#include <string>
namespace utilities
{
    class InputHandler
    {
        using snapshot_t = std::string;
    public:
        /**
         * Space separated values of all input values that can be passed.
         * Spaces are escaped via \ 
         */
        virtual snapshot_t getSnapshot() = 0;
        /**
         * Feed Snapshot string into class. The class will set its values
         * equal to an InputHandler that has the same state that generated
         * the same string
         */
        virtual void operator=(const InputHandler &inputHandler) = 0;
    };
}
#endif
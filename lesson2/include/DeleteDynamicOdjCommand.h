#pragma once
#include "Command.h"
#include "DynamicObject.h"
#include <vector>


class DeleteDynamicOdjCommand : public Command {
    public:
        DeleteDynamicOdjCommand(const DynamicObject* ptrObject, std::vector<DynamicObject*>& vec)
            :
                ptrObject(ptrObject),
                vec(vec)
        {}
        
        virtual ~DeleteDynamicOdjCommand() {}
        
        void execute() override {
            for (auto it = vec.begin(); it != vec.end(); ++it)
                if (*it == ptrObject) {
                    vec.erase(it);
                    delete *it;
                    return;
                }
        }
        
    private:
        const DynamicObject* ptrObject;
        std::vector<DynamicObject*>& vec;
};
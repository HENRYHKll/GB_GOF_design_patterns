#pragma once
#include "Command.h"
#include "GameObject.h"
#include <vector>


class DeleteStaticOdjCommand : public Command {
    public:
        DeleteStaticOdjCommand(const GameObject* ptrObject, std::vector<GameObject*>& vec)
            :
                ptrObject(ptrObject),
                vec(vec)
        {}
        
        virtual ~DeleteStaticOdjCommand() {}
        
        void execute() override {
            for (auto it = vec.begin(); it != vec.end(); ++it)
                if (*it == ptrObject) {
                    vec.erase(it);
                    delete *it;
                    return;
                }
        }
        
    private:
        const GameObject* ptrObject;
        std::vector<GameObject*>& vec;
};
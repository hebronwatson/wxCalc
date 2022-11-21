#include "Calculate.h"

float Calculate::ProcessOperations(vector<OperationEvent> events) {
    vector<OperationEvent>::iterator it = events.begin();
    float result;
    if(it->operation == OperationType::equal){
        result = it->number;
    };

    it++;

    for(; it != events.end(); it++){
        switch(it->operation){
            case OperationType::plus:
                result += it->number;
                break;
            default:
                break;
        }
    }

    return result;
}
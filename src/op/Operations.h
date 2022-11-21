#pragma once

#include <vector>

using std::vector;

enum OperationType {
    plus,
    minus,
    multiply,
    divide,
    equal
};

struct OperationEvent {
    OperationType operation;
    float number;

    OperationEvent(OperationType o, float n) : operation(o), number(n) {}
    OperationEvent(float n) : operation(OperationType::equal), number(n) {}
};


//
// Created by corigan01 on 11/4/23.
//

#pragma once

#include <UIElement.h>

template <typename DataType, class ValueType>
class IncludeDataWithUIElement : public ValueType {
public:
    DataType data;

    IncludeDataWithUIElement(DataType d, ValueType value) :
            ValueType { value },
            data { d } {

    }

    ~IncludeDataWithUIElement() = default;
};

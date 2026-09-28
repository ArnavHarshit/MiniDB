#include "common/definitions.h"

#include "core/assert.h"

std::string ToString(DataType dataType)
{
    switch (dataType) {
    case DataType::INTEGER:
        return "INTEGER";
    case DataType::TEXT:
        return "TEXT";
    }
    MiniDB_ASSERT(false, "DataType doesn't have a string representation");
    __builtin_unreachable();
}

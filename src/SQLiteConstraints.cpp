#include "SQLiteConstraints.h"

 std::unique_ptr<SQLiteConstraints<>> createNoConstraints() {
    return std::make_unique<SQLiteConstraints<>>();
}

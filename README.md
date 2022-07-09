# algorithms

## Including

To add this library to your project, simply add those two lines to your *CMakeLists.txt*:
```cmake
add_subdirectory(path/to/algorithms)
target_link_libraries(${PROJECT_NAME} PRIVATE algorithms::algorithms)
```

Then include it as:
```cpp
#include <algorithms/algorithms.hpp>
```

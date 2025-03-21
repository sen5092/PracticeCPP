# Build shared application logic as a library
set(APP_SOURCES
    Point.cpp
    HashTable.cpp
    BitManipulator.cpp
    ExceptionPractice.cpp
    TextFilePractice.cpp
    BinaryFiles.cpp
    STLPractice.cpp
)

# Create the shared library
add_library(PracticeLib ${APP_SOURCES})
target_include_directories(PracticeLib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Main executable (only includes main.cpp)
add_executable(PracticeApp main.cpp)
target_link_libraries(PracticeApp PRIVATE PracticeLib)
target_include_directories(PracticeApp PRIVATE ${PROJECT_SOURCE_DIR}/include)

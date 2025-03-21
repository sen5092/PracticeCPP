include(FetchContent)

# Download Catch2
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.1.0
)
FetchContent_MakeAvailable(Catch2)

# Gather test sources
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS *.cpp)

# Build test executable
add_executable(UnitTests ${TEST_FILES})

# Add include path
target_include_directories(UnitTests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Link to app and Catch2
target_link_libraries(UnitTests PRIVATE PracticeLib Catch2::Catch2WithMain)

# Enable and register tests
include(Catch)
catch_discover_tests(UnitTests)

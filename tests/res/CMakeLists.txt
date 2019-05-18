add_executable(
    bug-test
	bug_test.cpp
    ${PROJECT_SOURCE_DIR}/src/bug.cpp
)

add_executable(
    landscape-test
	landscape_test.cpp
    ${PROJECT_SOURCE_DIR}/src/landscape.cpp
    ${PROJECT_SOURCE_DIR}/src/bug.cpp
    ${PROJECT_SOURCE_DIR}/src/container.cpp
)

add_executable(
    container-test
	container_test.cpp
    ${PROJECT_SOURCE_DIR}/src/container.cpp
)

include_directories(bug-test landscape-test container-test PUBLIC
    ${PROJECT_SOURCE_DIR}/vendor/catch2/
    ${PROJECT_SOURCE_DIR}/src/
)

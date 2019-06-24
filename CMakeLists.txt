cmake_minimum_required(VERSION 3.0)

project(tmtp)

file(GLOB sources src/*)

if (UNIX)

find_package(PkgConfig)

pkg_check_modules(CAIRO REQUIRED cairo)

set(cflags
    ${cflags}
    ${CAIRO_CFLAGS_OTHER}
)

set(incl
    ${incl}
    ${CAIRO_INCLUDE_DIRS}
)

set(libs
    ${libs}
    cairo
)

elseif (MSVC)

endif (UNIX)

add_executable(${PROJECT_NAME} ${sources})

target_compile_options(${PROJECT_NAME} PRIVATE ${cflags})
target_include_directories(${PROJECT_NAME} PRIVATE ${incl})
target_link_libraries(${PROJECT_NAME} PRIVATE ${libs})

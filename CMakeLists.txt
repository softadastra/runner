cmake_minimum_required(VERSION 3.20)
project(runner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(VIX_LINK_STATIC "Static libstdc++/libgcc" ON)
option(VIX_LINK_FULL_STATIC "Full static link (-static). Prefer musl." OFF)

# ------------------------------------------------------
# Core Vix runtime
# ------------------------------------------------------
find_package(vix QUIET CONFIG)
if (NOT vix_FOUND)
  find_package(Vix CONFIG REQUIRED)
endif()

# ------------------------------------------------------
# Local registry packages installed with: vix install
# ------------------------------------------------------
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.vix/vix_deps.cmake")
  include("${CMAKE_CURRENT_SOURCE_DIR}/.vix/vix_deps.cmake")
endif()

# ------------------------------------------------------
# Helpers
# ------------------------------------------------------
function(vix_link_optional_targets tgt)
  foreach(dep IN LISTS ARGN)
    if (TARGET ${dep})
      target_link_libraries(${tgt} PRIVATE ${dep})
    endif()
  endforeach()
endfunction()

function(vix_apply_static_link_flags tgt)
  if (MSVC)
    return()
  endif()

  if (VIX_LINK_STATIC)
    target_link_options(${tgt} PRIVATE -static-libstdc++ -static-libgcc)
    target_compile_definitions(${tgt} PRIVATE VIX_LINK_STATIC=1)
  endif()

  if (VIX_LINK_FULL_STATIC)
    target_link_options(${tgt} PRIVATE -static)
    target_compile_definitions(${tgt} PRIVATE VIX_LINK_FULL_STATIC=1)
  endif()
endfunction()

function(runner_apply_warnings tgt)
  if (MSVC)
    target_compile_options(${tgt} PRIVATE /W4 /permissive-)
  else()
    target_compile_options(${tgt} PRIVATE -Wall -Wextra -Wpedantic)
  endif()
endfunction()

# ------------------------------------------------------
# Runner sources
# ------------------------------------------------------
set(RUNNER_SOURCES
  src/app/RunnerApp.cpp
  src/cli/Console.cpp
  src/cli/InputParser.cpp
  src/cli/Prompt.cpp
  src/core/RunnerService.cpp
  src/infrastructure/VixProcessExecutor.cpp
  src/utils/StringUtils.cpp
)

# ------------------------------------------------------
# Runner library
# ------------------------------------------------------
add_library(runner_lib STATIC
  ${RUNNER_SOURCES}
)

target_include_directories(runner_lib
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(runner_lib
  PUBLIC
    vix::vix
)

runner_apply_warnings(runner_lib)
vix_apply_static_link_flags(runner_lib)

# ------------------------------------------------------
# Main executable
# ------------------------------------------------------
add_executable(runner
  src/main.cpp
)

target_link_libraries(runner
  PRIVATE
    runner_lib
)

runner_apply_warnings(runner)
vix_apply_static_link_flags(runner)

# ------------------------------------------------------
# Tests
# ------------------------------------------------------
include(CTest)
enable_testing()

add_executable(runner_basic_test
  tests/test_basic.cpp
)

target_link_libraries(runner_basic_test
  PRIVATE
    runner_lib
)

runner_apply_warnings(runner_basic_test)
vix_apply_static_link_flags(runner_basic_test)

add_test(NAME runner.basic COMMAND runner_basic_test)

add_executable(runner_cli_test
  tests/test_cli.cpp
)

target_link_libraries(runner_cli_test
  PRIVATE
    runner_lib
)

runner_apply_warnings(runner_cli_test)
vix_apply_static_link_flags(runner_cli_test)

add_test(NAME runner.cli COMMAND runner_cli_test)

# ------------------------------------------------------
# Convenience target
# ------------------------------------------------------
add_custom_target(run
  COMMAND $<TARGET_FILE:runner>
  DEPENDS runner
  USES_TERMINAL
)

project(${CMAKE_PROJECT_NAME})

set(EXE_NAME "Vernam")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cc")
list(REMOVE_ITEM SOURCES "main.cc")
message(STATUS "Found sources: ${SOURCES}")

add_executable(${EXE_NAME})
set_target_properties(${EXE_NAME} PROPERTIES ENABLE_EXPORTS TRUE)

target_sources(${EXE_NAME}
    PRIVATE
      "main.cc"
    PUBLIC
      ${SOURCES}
)

target_include_directories(
    ${EXE_NAME}
  PRIVATE
    .
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR}>
)
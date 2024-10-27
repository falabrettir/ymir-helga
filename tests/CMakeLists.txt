add_executable(simon_tests
  ./test_main.cpp
)

target_include_directories(simon_tests
  PRIVATE
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(simon_tests
    PUBLIC
        jogo
        Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(simon_tests)

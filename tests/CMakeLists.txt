# # Procurar Catch2 (necessário para testes)
# find_package(Catch2 REQUIRED)
#
# # Executável dos testes
# add_executable(simon_tests
#   main_tests.cpp
# )
#
# target_include_directories(simon_tests
#   PRIVATE
#   ${PROJECT_INCLUDE_DIR}
# )
#
# target_link_libraries(simon_tests
#   PUBLIC
#   jogo
#   Catch2::Catch2
# )
#
# # Descoberta automática de testes
# include(Catch)
# catch_discover_tests(simon_tests)
#

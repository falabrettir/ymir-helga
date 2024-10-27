add_library(jogo
  ./Jogo.cpp
)

target_include_directories(jogo
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(jogo
  PUBLIC
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
)

# ---------------------------------------
# Executável principal
add_executable(simon ./Main.cpp)

target_include_directories(simon
  PUBLIC
  ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(simon
  PRIVATE
  jogo
)

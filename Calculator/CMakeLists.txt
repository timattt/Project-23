cmake_minimum_required (VERSION 3.0.0)

project (Calculator)

add_library(Core Calculator/Core/Calculator.cpp Calculator/Core/Utils.cpp Calculator/Syntaxizer/Node.cpp Calculator/Syntaxizer/Syntaxizer.cpp Calculator/Syntaxizer/Nodes/E.cpp Calculator/Syntaxizer/Nodes/G.cpp Calculator/Syntaxizer/Nodes/K.cpp Calculator/Syntaxizer/Nodes/M.cpp Calculator/Syntaxizer/Nodes/P.cpp Calculator/Syntaxizer/Nodes/T.cpp Calculator/Tokenizer/Token.cpp Calculator/Tokenizer/Tokenizer.cpp)

add_executable(Calculator Main.cpp)
add_executable(UnitTests UnitTests.cpp)

target_link_libraries(Calculator Core)
target_link_libraries(UnitTests Core)
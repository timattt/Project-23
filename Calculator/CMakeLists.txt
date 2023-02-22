cmake_minimum_required (VERSION 3.0.0)

project (Calculator)

add_executable(Calculator Calculator/Core/Calculator.cpp Calculator/Core/Utils.cpp Calculator/Syntaxizer/Node.cpp Calculator/Syntaxizer/Syntaxizer.cpp Calculator/Syntaxizer/Nodes/E.cpp Calculator/Syntaxizer/Nodes/G.cpp Calculator/Syntaxizer/Nodes/K.cpp Calculator/Syntaxizer/Nodes/M.cpp Calculator/Syntaxizer/Nodes/P.cpp Calculator/Syntaxizer/Nodes/T.cpp Calculator/Tokenizer/Token.cpp Calculator/Tokenizer/Tokenizer.cpp Main.cpp)
add_executable(UnitTests Calculator/Core/Calculator.cpp Calculator/Core/Utils.cpp Calculator/Syntaxizer/Node.cpp Calculator/Syntaxizer/Syntaxizer.cpp Calculator/Syntaxizer/Nodes/E.cpp Calculator/Syntaxizer/Nodes/G.cpp Calculator/Syntaxizer/Nodes/K.cpp Calculator/Syntaxizer/Nodes/M.cpp Calculator/Syntaxizer/Nodes/P.cpp Calculator/Syntaxizer/Nodes/T.cpp Calculator/Tokenizer/Token.cpp Calculator/Tokenizer/Tokenizer.cpp UnitTests.cpp)
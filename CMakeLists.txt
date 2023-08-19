cmake_minimum_required(VERSION 3.12.0)
project(test)
set(CMAKE_CXX_STANDARD 17)
include_directories(
    /home/triton/tools/llvm-project/llvm/include
)
link_directories(/home/triton/tools/llvm-project/build/lib)
link_libraries(LLVMSupport LLVMCodeGen LLVMIRReader LLVMCore LLVMBinaryFormat)
set(_source
    codegen.cpp
    Lexer.cpp
    Parser.cpp
    toy.cpp
)

add_executable(toy ${_source})
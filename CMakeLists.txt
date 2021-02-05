set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.17)

project(tape-lang)

find_package(BISON)
find_package(FLEX)

#MAIN
  set(CMAKE_CURRENT_BINARY_DIR ../src)

  set(GEN src/Bison)
  set(AST src/Ast)
  set(PARSER src/Parser)
  
  set(GEN_DEST ${CMAKE_CURRENT_BINARY_DIR}/../${PARSER}) # where to put output files

  BISON_TARGET(TapeParser ${GEN}/parser.yy ${GEN_DEST}/Parser.cc DEFINES_FILE ${GEN_DEST}/Parser.hh)
#  FLEX_TARGET(TapeScanner ${GEN}/lexer.l ${GEN_DEST}/Lexer.cc DEFINES_FILE ${GEN_DEST}/Lexer.hh) 
  FLEX_TARGET(TapeScanner ${GEN}/lexer.l ${GEN_DEST}/Lexer.cc) 
  ADD_FLEX_BISON_DEPENDENCY(TapeScanner TapeParser)


  include_directories(${CMAKE_CURRENT_BINARY_DIR})
  add_executable(tape 

    ${PARSER}/Driver.cc
    ${PARSER}/Parser.cc
    ${BISON_TapeParser_OUTPUTS} 
    ${PARSER}/Lexer.cc
    ${FLEX_TapeScanner_OUTPUTS} 
    src/Tape.cc
  )

  target_include_directories(tape PUBLIC ${SRC} ${INCLUDE})

  target_compile_options(tape PUBLIC -Wall)



  #set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/local/share/llvm/cmake")
  #find_package(LLVM)
  #
  #if( NOT LLVM_FOUND )
    #message(FATAL_ERROR "LLVM package can't be found. Set CMAKE_PREFIX_PATH variable to LLVM's installation prefix.")
  #endif()
  #
  #include_directories( ${LLVM_INCLUDE_DIRS} )
  #link_directories( ${LLVM_LIBRARY_DIRS} )
  #
  #llvm_map_components_to_libraries(REQ_LLVM_LIBRARIES jit native)
  #
  #target_link_libraries(tape ${REQ_LLVM_LIBRARIES})
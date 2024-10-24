cmake_minimum_required(VERSION 3.8)

project(JesusASM)

set(SOURCES
	"src/jasm/Builder.cpp"
 "src/jasm/instruction/singleOperandInstruction/CallInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/GetFieldInstruction.cpp" "src/jasm/instruction/operand/Label.cpp" "src/jasm/instruction/singleOperandInstruction/LdcInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/LdiInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/LoadInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/NewArrayInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/NewArrayPrimInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/NewInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/NumberInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/PutFieldInstruction.cpp" "src/jasm/instruction/singleOperandInstruction/StoreInstruction.cpp" "src/jasm/instruction/Label.cpp" "src/jasm/type/Type.cpp" "src/jasm/type/PrimitiveType.cpp" "src/jasm/type/VoidType.cpp" "src/jasm/type/ClassType.cpp" "src/jasm/type/FunctionType.cpp" "src/jasm/instruction/Constant.cpp" "src/jasm/instruction/Directive.cpp" "src/jasm/instruction/Value.cpp" "src/jasm/instruction/Class.cpp" "src/jasm/instruction/Function.cpp")

set(HEADERS
	"include/jasm/Builder.h"
 "include/jasm/instruction/Value.h" "include/jasm/instruction/Instruction.h" "include/jasm/instruction/NoOperandInstruction.h" "include/jasm/codegen/Opcodes.h" "include/jasm/instruction/singleOperandInstruction/CallInstruction.h" "include/jasm/instruction/singleOperandInstruction/GetFieldInstruction.h" "include/jasm/instruction/singleOperandInstruction/JmpInstruction.h" "include/jasm/instruction/operand/Label.h" "include/jasm/instruction/singleOperandInstruction/LdcInstruction.h" "include/jasm/instruction/singleOperandInstruction/LdiInstruction.h" "include/jasm/instruction/singleOperandInstruction/LoadInstruction.h" "include/jasm/instruction/singleOperandInstruction/NewArrayInstruction.h" "include/jasm/instruction/singleOperandInstruction/NewArrayPrimInstruction.h" "include/jasm/instruction/singleOperandInstruction/NewInstruction.h" "include/jasm/instruction/singleOperandInstruction/NumberInstruction.h" "include/jasm/instruction/singleOperandInstruction/PutFieldInstruction.h" "include/jasm/instruction/singleOperandInstruction/StoreInstruction.h" "include/jasm/instruction/Label.h" "include/jasm/instruction/Constant.h" "include/jasm/type/Type.h" "include/jasm/type/PrimitiveType.h" "include/jasm/type/VoidType.h" "include/jasm/type/ClassType.h" "include/jasm/type/FunctionType.h" "include/jasm/instruction/Directive.h" "include/jasm/instruction/Class.h" "include/jasm/instruction/Function.h")

source_group(TREE ${PROJECT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})

add_executable(JesusASM ${SOURCES} ${HEADERS})

target_include_directories(JesusASM PUBLIC include)
target_compile_features(JesusASM PUBLIC cxx_std_20)
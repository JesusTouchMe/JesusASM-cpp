#include "jasm/type/ClassType.h"
#include "jasm/type/FunctionType.h"
#include "jasm/type/PrimitiveType.h"
#include "jasm/type/VoidType.h"

#include <memory>

namespace jasm {
	std::vector<std::unique_ptr<Type>> types;

	Type* Type::GetBoolType() {
		static PrimitiveType type("bool", "B", 0, 1);
		return &type;
	}

	Type* Type::GetByteType() {
		static PrimitiveType type("byte", "b", 1, 8);
		return &type;
	}

	Type* Type::GetShortType() {
		static PrimitiveType type("short", "s", 2, 16);
		return &type;
	}

	Type* Type::GetIntType() {
		static PrimitiveType type("int", "i", 3, 32);
		return &type;
	}

	Type* Type::GetLongType() {
		static PrimitiveType type("long", "l", 4, 64);
		return &type;
	}

	Type* Type::GetVoidType() {
		static VoidType type;
		return &type;
	}

	Type* Type::GetClassType(std::string_view moduleName, std::string_view name) {
		for (const auto& type : types) {
			if (ClassType* classType = dynamic_cast<ClassType*>(type.get())) {
				if (classType->getModule() == moduleName && classType->getClassName() == name) {
					return classType;
				}
			}
		}

		types.push_back(std::make_unique<ClassType>(moduleName, name));
		return types.back().get();
	}

	Type* Type::GetFunctionType(Type* returnType, std::vector<Type*> argumentTypes) {
		for (const auto& type : types) {
			if (FunctionType* functionType = dynamic_cast<FunctionType*>(type.get())) {
				if (functionType->getReturnType() == returnType && functionType->getArgumentTypes() == argumentTypes) {
					return functionType;
				}
			}
		}

		types.push_back(std::make_unique<FunctionType>(returnType, std::move(argumentTypes)));
		return types.back().get();
	}
}
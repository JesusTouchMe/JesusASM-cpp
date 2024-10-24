#include "jasm/type/ClassType.h"

#include <format>

namespace jasm {
	ClassType::ClassType(std::string_view moduleName, std::string_view name)
		: Type(std::format("class {}", name), std::format("T{}/{}", moduleName, name))
		, mModule(moduleName)
		, mClassName(name) { }

	std::string_view ClassType::getModule() const {
		return mModule;
	}

	std::string_view ClassType::getClassName() const {
		return mClassName;
	}

	bool ClassType::isClassType() const {
		return true;
	}

	ClassType* ClassType::Get(std::string_view moduleName, std::string_view name) {
		return static_cast<ClassType*>(Type::GetClassType(moduleName, name));
	}
}

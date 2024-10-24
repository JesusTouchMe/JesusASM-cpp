#include "jasm/instruction/Constant.h"

#include <format>

namespace jasm {
	ConstantFunction::ConstantFunction(std::string_view moduleName, std::string_view name, FunctionType* type)
		: mModule(moduleName)
		, mName(name)
		, mType(type) { }

	bool ConstantFunction::print(std::ostream& out) {
		if (mModule.empty()) {
			out << std::format(".function {} {}(", mType->getReturnType()->getName(), mName);
		} else {
			out << std::format(".function {} {}/{}(", mType->getReturnType()->getName(), mModule, mName);
		}

		const std::vector<Type*>& argumentTypes = mType->getArgumentTypes();

		if (!argumentTypes.empty()) {
			for (auto i = 0; i < argumentTypes.size() - 1; i++) {
				out << argumentTypes[i]->getName() << ", ";
			}

			out << argumentTypes.back()->getName();
		}

		out << ")";

		return true;
	}

	ConstantClass::ConstantClass(std::string_view moduleName, std::string_view name)
		: mModule(moduleName)
		, mName(name) { }

	bool ConstantClass::print(std::ostream& out) {
		if (mModule.empty()) {
			out << std::format(".class {}", mName);
		} else {
			out << std::format(".class {}/{}", mModule, mName);
		}

		return true;
	}

	ConstantField::ConstantField(std::string_view moduleName, std::string_view className, std::string_view name)
		: mModule(moduleName)
		, mClassName(className)
		, mName(name) { }

	bool ConstantField::print(std::ostream& out) {
		if (mModule.empty()) {
			out << std::format(".field {}::{}", mClassName, mName);
		} else {
			out << std::format(".field {}/{}::{}", mModule, mClassName, mName);
		}

		return true;
	}

	ConstantMethod::ConstantMethod(std::string_view moduleName, std::string_view className, std::string_view name, FunctionType* type)
		: mModule(moduleName)
		, mClassName(className)
		, mName(name)
		, mType(type) { }

	bool ConstantMethod::print(std::ostream& out) {
		if (mModule.empty()) {
			out << std::format(".method {} {}::{}(", mType->getReturnType()->getName(), mClassName, mName);
		} else {
			out << std::format(".method {} {}/{}::{}(", mType->getReturnType()->getName(), mModule, mClassName, mName);
		}

		const std::vector<Type*>& argumentTypes = mType->getArgumentTypes();

		if (!argumentTypes.empty()) {
			for (auto i = 0; i < argumentTypes.size() - 1; i++) {
				out << argumentTypes[i]->getName() << ", ";
			}

			out << argumentTypes.back()->getName();
		}

		out << ")";

		return true;
	}
}
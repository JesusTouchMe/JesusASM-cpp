#include "jasm/instruction/Class.h"

#include <format>

namespace jasm {
	void Field::print(std::ostream& out) {
		out << std::format("field {}{} {}", GetModifiersAsString(modifiers), type->getName(), name);
	}

	void Method::print(std::ostream& out) {
		out << std::format("method {}{} {}(", GetModifiersAsString(modifiers), type->getReturnType()->getName(), name);

		const std::vector<Type*>& argumentTypes = type->getArgumentTypes();

		if (!argumentTypes.empty()) {
			for (auto i = 0; i < argumentTypes.size() - 1; i++) {
				out << argumentTypes[i]->getName() << ", ";
			}

			out << argumentTypes.back()->getName();
		}

		out << ")";
	}

	Class::Class(std::string_view moduleName, std::string_view name, std::string_view superClassModule, std::string_view superClassName, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods)
		: mType(ClassType::Get(moduleName, name))
		, mName(name)
		, mSuperModule(superClassModule)
		, mSuperClass(superClassName)
		, mModifiers(std::move(modifiers))
		, mFields(std::move(fields))
		, mMethods(std::move(methods)) { }

	ClassType* Class::getType() const {
		return mType;
	}

	bool Class::print(std::ostream& out) {
		out << "class " << mName;

		if (!mSuperClass.empty()) {
			if (!mSuperModule.empty()) {
				out << std::format(" extends {}/{}", mSuperModule, mSuperClass);
			} else {
				out << " extends " << mSuperClass;
			}
		}

		out << ":";

		for (auto& field : mFields) {
			out << "\n";
			field.print(out);
		}

		for (auto& method : mMethods) {
			out << "\n";
			method.print(out);
		}

		return true;
	}
}
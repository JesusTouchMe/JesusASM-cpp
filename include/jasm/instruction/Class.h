#ifndef JESUSASM_CLASS_VALUE_H
#define JESUSASM_CLASS_VALUE_H

#include "jasm/instruction/Value.h"
#include "jasm/type/ClassType.h"
#include "jasm/type/FunctionType.h"

namespace jasm {
	struct Field {
		Type* type;
		std::string name;
		std::set<Modifier> modifiers;

		void print(std::ostream& out);
	};

	struct Method {
		FunctionType* type;
		std::string name;
		std::set<Modifier> modifiers;

		void print(std::ostream& out);
	};

	class Class : public Value {
	public:
		Class(std::string_view moduleName, std::string_view name, std::string_view superClassModule, std::string_view superClassName, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods); // this is really bad design, but moduleName has to be the canonical name of the module this class is defined in. superClassModule can be the module the super class is defined in

		ClassType* getType() const;

		virtual bool print(std::ostream& out) override;

	private:
		ClassType* mType;
		std::string mName;

		std::string mSuperModule;
		std::string mSuperClass;

		std::set<Modifier> mModifiers;
		std::vector<Field> mFields;
		std::vector<Method> mMethods;
	};
}

#endif // JESUSASM_CLASS_VALUE_H

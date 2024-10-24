#ifndef JESUSASM_CLASS_TYPE_H
#define JESUSASM_CLASS_TYPE_H

#include "jasm/type/Type.h"

namespace jasm {
	class ClassType : public Type {
	public:
		ClassType(std::string_view moduleName, std::string_view name);

		std::string_view getModule() const;
		std::string_view getClassName() const;

		bool isClassType() const override;

		static ClassType* Get(std::string_view moduleName, std::string_view name);

	private:
		std::string mModule;
		std::string mClassName;
	};
}

#endif // JESUSASM_CLASS_TYPE_H

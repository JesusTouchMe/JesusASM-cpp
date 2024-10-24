#ifndef JESUSASM_FUNCTION_TYPE_H
#define JESUSASM_FUNCTION_TYPE_H

#include "jasm/type/Type.h"

#include <vector>

namespace jasm {
	class FunctionType : public Type {
	public:
		FunctionType(Type* returnType, std::vector<Type*> argumentTypes);

		Type* getReturnType() const;
		const std::vector<Type*>& getArgumentTypes() const;

		bool isFunctionType() const override;

		static FunctionType* Get(Type* returnType, std::vector<Type*> argumentTypes);

	private:
		Type* mReturnType;
		std::vector<Type*> mArgumentTypes;
	};
}

#endif // JESUSASM_FUNCTION_TYPE_H

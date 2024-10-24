#include "jasm/type/FunctionType.h"

#include <format>

namespace jasm {
	FunctionType::FunctionType(Type* returnType, std::vector<Type*> argumentTypes)
		: Type(std::format("{}(", returnType->getName()), "(")
		, mReturnType(returnType)
		, mArgumentTypes(std::move(argumentTypes)) 
	{
		if (!mArgumentTypes.empty()) {
			for (auto i = 0; i < mArgumentTypes.size() - 1; i++) {
				mName += std::string(mArgumentTypes[i]->getName()) + ", ";
				mId += mArgumentTypes[i]->getId();
			}

			mName += mArgumentTypes.back()->getName();
			mId += mArgumentTypes.back()->getId();
		}

		mName += ')';
		mId += ')';

		mId += mReturnType->getId();
	}

	Type* FunctionType::getReturnType() const {
		return mReturnType;
	}

	const std::vector<Type*>& FunctionType::getArgumentTypes() const {
		return mArgumentTypes;
	}

	bool FunctionType::isFunctionType() const {
		return true;
	}

	FunctionType* FunctionType::Get(Type* returnType, std::vector<Type*> argumentTypes) {
		return static_cast<FunctionType*>(Type::GetFunctionType(returnType, std::move(argumentTypes)));
	}
}

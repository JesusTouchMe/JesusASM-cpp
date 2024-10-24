#ifndef JESUSASM_TYPE_H
#define JESUSASM_TYPE_H

#include <string>
#include <vector>

namespace jasm {
	class Type {
	public:
		virtual ~Type() { }

		std::string_view getName() const { return mName; }
		std::string_view getId() const { return mId; }

		virtual bool isPrimitiveType() const { return false; }
		virtual bool isVoidType() const { return false; }
		virtual bool isFunctionType() const { return false; }
		virtual bool isClassType() const { return false; }

		static Type* GetBoolType();
		static Type* GetByteType();
		static Type* GetShortType();
		static Type* GetIntType();
		static Type* GetLongType();
		static Type* GetVoidType();
		static Type* GetClassType(std::string_view moduleName, std::string_view name);
		static Type* GetFunctionType(Type* returnType, std::vector<Type*> argumentTypes);

	protected:
		Type(std::string_view name, std::string_view id)
			: mName(name)
			, mId(id) { }

		std::string mName;
		std::string mId;
	};
}

#endif // JESUSASM_TYPE_H

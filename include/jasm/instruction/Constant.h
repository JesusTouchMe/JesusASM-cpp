#ifndef JESUSASM_CONSTANT_VALUE_H
#define JESUSASM_CONSTANT_VALUE_H

#include "jasm/instruction/Value.h"

#include "jasm/type/FunctionType.h"

namespace jasm {
	class Builder;

	class Constant : public Value {
	public:
		virtual ~Constant() { }
	};

	class ConstantFunction : public Constant {
	friend class Builder;
	public:
		ConstantFunction(std::string_view moduleName, std::string_view name, FunctionType* type);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mModule;
		std::string mName;
		FunctionType* mType;
	};

	class ConstantClass : public Constant {
	friend class Builder;
	public:
		ConstantClass(std::string_view moduleName, std::string_view name);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mModule;
		std::string mName;
	};

	class ConstantField : public Constant {
	friend class Builder;
	public:
		ConstantField(std::string_view moduleName, std::string_view className, std::string_view name);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mModule;
		std::string mClassName;
		std::string mName;
	};

	class ConstantMethod : public Constant {
	friend class Builder;
	public:
		ConstantMethod(std::string_view moduleName, std::string_view className, std::string_view name, FunctionType* type);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mModule;
		std::string mClassName;
		std::string mName;
		FunctionType* mType;
	};

	using ConstantPtr = std::unique_ptr<Constant>;
}

#endif // JESUSASM_CONSTANT_VALUE_H

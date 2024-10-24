#ifndef JESUSASM_BUILDER_H
#define JESUSASM_BUILDER_H

#include "jasm/instruction/Class.h"

#include "jasm/instruction/operand/Label.h"

#include <cstdint>
#include <vector>

namespace jasm {
	class Builder;

	class ClassBuilder {
	friend class Builder;
	public:
		ClassBuilder& extends(std::string_view moduleName, std::string_view super);

		ClassBuilder& modifier(Modifier modifier);
		ClassBuilder& field(Field field);
		ClassBuilder& method(Method method);

		Builder& build();

	private:
		ClassBuilder(Builder& builder, std::string_view name);

		Builder& mBuilder;
		std::string mName;

		std::string mSuperModule;
		std::string mSuperClass;

		std::set<Modifier> mModifiers;
		std::vector<Field> mFields;
		std::vector<Method> mMethods;
	};

	class Builder {
	friend class ClassBuilder;
	friend class ConstantBuilder;
	public:
		Builder(std::string_view moduleName);

		Builder& nop();
		Builder& pop();
		Builder& dup();
		Builder& load(std::uint64_t index);
		Builder& loadobj(std::uint64_t index);
		Builder& store(std::uint64_t index);
		Builder& storeobj(std::uint64_t index);
		Builder& aload();
		Builder& aloadobj();
		Builder& astore();
		Builder& astoreobj();
		Builder& newInsn(std::uint64_t index);
		Builder& newarray(std::uint64_t index);
		Builder& newarrayprim(std::uint8_t typeId);
		Builder& getfield(std::uint64_t index);
		Builder& putfield(std::uint64_t index);
		Builder& add();
		Builder& sub();
		Builder& mul();
		Builder& div();
		Builder& andInsn();
		Builder& orInsn();
		Builder& xorInsn();
		Builder& shr();
		Builder& shl();
		Builder& inc();
		Builder& dec();
		Builder& notInsn();
		Builder& neg();
		Builder& cmp();
		Builder& cmp_true();
		Builder& cmp_false();
		Builder& pusheq();
		Builder& pushne();
		Builder& pushlt();
		Builder& pushgt();
		Builder& pushle();
		Builder& pushge();
		Builder& jmp(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jeq(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jne(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jlt(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jgt(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jle(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& jge(LabelOperandPtr label = nullptr); // nullptr means jump by stack value
		Builder& call(std::uint64_t index);
		Builder& ret();
		Builder& ldc(std::uint64_t index);
		Builder& ldi(std::uint64_t value);
		Builder& debug();
		Builder& hlt();

		Builder& entry(std::uint32_t entry);

		Builder& section(std::string_view section);
		Builder& addLabel(std::string_view name);
		LabelOperandPtr label(std::string_view name);

		Builder& constFunction(std::string_view moduleName, std::string_view name, FunctionType* type);
		Builder& constClass(std::string_view moduleName, std::string_view name);
		Builder& constField(std::string_view moduleName, std::string_view className, std::string_view name);
		Builder& constMethod(std::string_view moduleName, std::string_view className, std::string_view name, FunctionType* type);

		ClassBuilder makeClass(std::string_view name);
		Builder& quickClass(std::string_view name, std::string_view superClassModule, std::string_view superClassName, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods);
		Builder& quickClass(std::string_view name, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods);

		Builder& function(std::string_view name, FunctionType* type, std::set<Modifier> modifiers, std::uint16_t locals = 0);

	private:
		Builder& insn(Value* value);

		std::string mModuleName;
		std::uint32_t mEntry; // const pool index zzz

		std::string mCurrentSection; // to avoid duplicate section nodes :D

		std::vector<std::string> mLabels; // to avoid duplicate labels 
		std::vector<ValuePtr> mValues;
	};
}

#endif // JESUSASM_BUILDER_H
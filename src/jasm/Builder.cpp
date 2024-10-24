#include "jasm/Builder.h"

#include "jasm/instruction/Constant.h"
#include "jasm/instruction/Directive.h"
#include "jasm/instruction/Function.h"
#include "jasm/instruction/Label.h"
#include "jasm/instruction/NoOperandInstruction.h"

#include "jasm/instruction/singleOperandInstruction/CallInstruction.h"
#include "jasm/instruction/singleOperandInstruction/GetFieldInstruction.h"
#include "jasm/instruction/singleOperandInstruction/JmpInstruction.h"
#include "jasm/instruction/singleOperandInstruction/LdcInstruction.h"
#include "jasm/instruction/singleOperandInstruction/LdiInstruction.h"
#include "jasm/instruction/singleOperandInstruction/LoadInstruction.h"
#include "jasm/instruction/singleOperandInstruction/NewArrayInstruction.h"
#include "jasm/instruction/singleOperandInstruction/NewArrayPrimInstruction.h"
#include "jasm/instruction/singleOperandInstruction/NewInstruction.h"
#include "jasm/instruction/singleOperandInstruction/NumberInstruction.h"
#include "jasm/instruction/singleOperandInstruction/PutFieldInstruction.h"
#include "jasm/instruction/singleOperandInstruction/StoreInstruction.h"

#include <algorithm>

namespace jasm {
	ClassBuilder& ClassBuilder::extends(std::string_view moduleName, std::string_view super) {
		mSuperModule = moduleName;
		mSuperClass = super;

		return *this;
	}

	ClassBuilder& ClassBuilder::modifier(Modifier modifier) {
		mModifiers.insert(std::move(modifier));
		return *this;
	}
	
	ClassBuilder& ClassBuilder::field(Field field) {
		mFields.push_back(std::move(field));
		return *this;
	}

	ClassBuilder& ClassBuilder::method(Method method) {
		mMethods.push_back(std::move(method));
		return *this;
	}

	Builder& ClassBuilder::build() {
		mBuilder.insn(new Class(mBuilder.mModuleName, std::move(mName), std::move(mSuperModule), std::move(mSuperClass), std::move(mModifiers), std::move(mFields), std::move(mMethods)));
		return mBuilder;
	}

	ClassBuilder::ClassBuilder(Builder& builder, std::string_view name)
		: mBuilder(builder)
		, mName(name) { }

	Builder::Builder(std::string_view moduleName)
		: mModuleName(moduleName)
		, mEntry(0) { }

	Builder& Builder::nop() {
		return insn(new NopInstruction()); 
	}

	Builder& Builder::pop() {
		return insn(new PopInstruction());
	}

	Builder& Builder::dup() {
		return insn(new DupInstruction());
	}

	Builder& Builder::load(std::uint64_t index) {
		return insn(new LoadInstruction(index));
	}

	Builder& Builder::loadobj(std::uint64_t index) {
		return insn(new LoadObjInstruction(index));
	}

	Builder& Builder::store(std::uint64_t index) {
		return insn(new StoreInstruction(index));
	}

	Builder& Builder::storeobj(std::uint64_t index) {
		return insn(new StoreObjInstruction(index));
	}

	Builder& Builder::aload() {
		return insn(new ALoadInstruction());
	}

	Builder& Builder::aloadobj() {
		return insn(new ALoadObjInstruction());
	}

	Builder& Builder::astore() {
		return insn(new AStoreInstruction());
	}

	Builder& Builder::astoreobj() {
		return insn(new AStoreObjInstruction());
	}

	Builder& Builder::newInsn(std::uint64_t index) {
		return insn(new NewInstruction(index));
	}

	Builder& Builder::newarray(std::uint64_t index) {
		return insn(new NewArrayInstruction(index));
	}

	Builder& Builder::newarrayprim(std::uint8_t typeId) {
		return insn(new NewArrayPrimInstruction(typeId));
	}

	Builder& Builder::getfield(std::uint64_t index) {
		return insn(new GetFieldInstruction(index));
	}

	Builder& Builder::putfield(std::uint64_t index) {
		return insn(new PutFieldInstruction(index));
	}

	Builder& Builder::add() {
		return insn(new AddInstruction());
	}

	Builder& Builder::sub() {
		return insn(new SubInstruction());
	}

	Builder& Builder::mul() {
		return insn(new MulInstruction());
	}

	Builder& Builder::div() {
		return insn(new DivInstruction());
	}

	Builder& Builder::andInsn() {
		return insn(new AndInstruction());
	}

	Builder& Builder::orInsn() {
		return insn(new OrInstruction());
	}

	Builder& Builder::xorInsn() {
		return insn(new XorInstruction());
	}

	Builder& Builder::shr() {
		return insn(new ShrInstruction());
	}

	Builder& Builder::shl() {
		return insn(new ShlInstruction());
	}

	Builder& Builder::inc() {
		return insn(new IncInstruction());
	}

	Builder& Builder::dec() {
		return insn(new DecInstruction());
	}

	Builder& Builder::notInsn() {
		return insn(new NotInstruction());
	}

	Builder& Builder::neg() {
		return insn(new NegInstruction());
	}

	Builder& Builder::cmp() {
		return insn(new CmpInstruction());
	}

	Builder& Builder::cmp_true() {
		return insn(new CmpTrueInstruction());
	}

	Builder& Builder::cmp_false() {
		return insn(new CmpFalseInstruction());
	}

	Builder& Builder::pusheq() {
		return insn(new PushEqInstruction());
	}

	Builder& Builder::pushne() {
		return insn(new PushNeInstruction());
	}

	Builder& Builder::pushlt() {
		return insn(new PushLtInstruction());
	}

	Builder& Builder::pushgt() {
		return insn(new PushGtInstruction());
	}

	Builder& Builder::pushle() {
		return insn(new PushLeInstruction());
	}

	Builder& Builder::pushge() {
		return insn(new PushGeInstruction());
	}

	Builder& Builder::jmp(LabelOperandPtr label) {
		return insn(new JmpInstruction(std::move(label)));
	}

	Builder& Builder::jeq(LabelOperandPtr label) {
		return insn(new JeqInstruction(std::move(label)));
	}

	Builder& Builder::jne(LabelOperandPtr label) {
		return insn(new JneInstruction(std::move(label)));
	}

	Builder& Builder::jlt(LabelOperandPtr label) {
		return insn(new JltInstruction(std::move(label)));
	}

	Builder& Builder::jgt(LabelOperandPtr label) {
		return insn(new JgtInstruction(std::move(label)));
	}

	Builder& Builder::jle(LabelOperandPtr label) {
		return insn(new JleInstruction(std::move(label)));
	}

	Builder& Builder::jge(LabelOperandPtr label) {
		return insn(new JgeInstruction(std::move(label)));
	}

	Builder& Builder::call(std::uint64_t index) {
		return insn(new CallInstruction(index));
	}

	Builder& Builder::ret() {
		return insn(new RetInstruction());
	}

	Builder& Builder::ldc(std::uint64_t index) {
		return insn(new LdcInstruction(index));
	}

	Builder& Builder::ldi(std::uint64_t value) {
		return insn(new LdiInstruction(value));
	}

	Builder& Builder::debug() {
		return insn(new DebugInstruction());
	}

	Builder& Builder::hlt() {
		return insn(new HltInstruction());
	}

	Builder& Builder::entry(std::uint32_t entry) {
		mEntry = entry;
		return *this;
	}

	Builder& Builder::section(std::string_view section) {
		if (section == mCurrentSection) return *this;

		mCurrentSection = section;
		return insn(new SectionDirective(section));
	}

	Builder& Builder::addLabel(std::string_view name) {
		if (std::find_if(mLabels.rbegin(), mLabels.rend(), [&name](const auto& s) { return s == name; }) != mLabels.rend()) { // reverse iterator cuz it's probably more likely to define the same labels close to each other
			return *this;
		}

		mLabels.emplace_back(name);
		return insn(new Label(name));
	}

	LabelOperandPtr Builder::label(std::string_view name) {
		addLabel(name);
		return std::make_unique<LabelOperand>(name);
	}

	Builder& Builder::constFunction(std::string_view moduleName, std::string_view name, FunctionType* type) {
		return insn(new ConstantFunction(moduleName, name, type));
	}

	Builder& Builder::constClass(std::string_view moduleName, std::string_view name) {
		return insn(new ConstantClass(moduleName, name));
	}

	Builder& Builder::constField(std::string_view moduleName, std::string_view className, std::string_view name) {
		return insn(new ConstantField(moduleName, className, name));
	}

	Builder& Builder::constMethod(std::string_view moduleName, std::string_view className, std::string_view name, FunctionType* type) {
		return insn(new ConstantMethod(moduleName, className, name, type));
	}

	ClassBuilder Builder::makeClass(std::string_view name) {
		return ClassBuilder(*this, name);
	}

	Builder& Builder::quickClass(std::string_view name, std::string_view superClassModule, std::string_view superClassName, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods) {
		return insn(new Class(mModuleName, name, superClassModule, superClassName, std::move(modifiers), std::move(fields), std::move(methods)));
	}

	Builder& Builder::quickClass(std::string_view name, std::set<Modifier> modifiers, std::vector<Field> fields, std::vector<Method> methods) {
		return insn(new Class(mModuleName, name, "", "", std::move(modifiers), std::move(fields), std::move(methods)));
	}

	Builder& Builder::function(std::string_view name, FunctionType* type, std::set<Modifier> modifiers, std::uint16_t locals = 0) {
		 return insn(new Function(name, type, std::move(modifiers), locals));
	}

	Builder& Builder::insn(Value* value) {
		mValues.emplace_back(value);
		return *this;
	}
}
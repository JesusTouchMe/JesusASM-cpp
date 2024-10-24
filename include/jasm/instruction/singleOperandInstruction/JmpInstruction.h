#ifndef JESUSASM_JMP_INSTRUCTION_H
#define JESUSASM_JMP_INSTRUCTION_H

#include "jasm/codegen/Opcodes.h"

#include "jasm/instruction/Instruction.h"
#include "jasm/instruction/operand/Label.h"

#include <format>

namespace jasm {
	template <codegen::Opcodes Opcode, codegen::Opcodes RelOpcode, OpcodeStringBuilder Name>
	class BaseJmpInstruction : public Instruction {
	public:
		BaseJmpInstruction(LabelOperandPtr label) : mLabel(std::move(label)) { }
		virtual ~BaseJmpInstruction() { }

		virtual bool print(std::ostream& out) override {
			out << Name;

			if (mLabel != nullptr) {
				out << std::format(" {}", mLabel->getName());
			}
		}

	private:
		LabelOperandPtr mLabel;
	};

	using JmpInstruction = BaseJmpInstruction<codegen::JMP, codegen::JMPREL, "jmp">;
	using JeqInstruction = BaseJmpInstruction<codegen::JEQ, codegen::JEQREL, "jeq">;
	using JneInstruction = BaseJmpInstruction<codegen::JNE, codegen::JNEREL, "jne">;
	using JltInstruction = BaseJmpInstruction<codegen::JLT, codegen::JLTREL, "jlt">;
	using JgtInstruction = BaseJmpInstruction<codegen::JGT, codegen::JGTREL, "jgt">;
	using JleInstruction = BaseJmpInstruction<codegen::JLE, codegen::JLEREL, "jle">;
	using JgeInstruction = BaseJmpInstruction<codegen::JGE, codegen::JGEREL, "jge">;
}

#endif // JESUSASM_JMP_INSTRUCTION_H
#ifndef JESUSASM_NO_OPERAND_INSTRUCTION_H
#define JESUSASM_NO_OPERAND_INSTRUCTION_H

#include "jasm/codegen/Opcodes.h"

#include "jasm/instruction/Instruction.h"

#include <string_view>

namespace jasm {
	template <codegen::Opcodes Opcode, OpcodeStringBuilder Name>
	class NoOperandInstruction : public Instruction {
	public:
		virtual ~NoOperandInstruction() { }

		virtual bool print(std::ostream& out) override {
			out << Name.value;
			return true;
		}
	};	

	using NopInstruction = NoOperandInstruction<codegen::NOP, "nop">;
	using PopInstruction = NoOperandInstruction<codegen::POP, "pop">;
	using DupInstruction = NoOperandInstruction<codegen::DUP, "dup">;

	using ALoadInstruction = NoOperandInstruction<codegen::ALOAD, "aload">;
	using AStoreInstruction = NoOperandInstruction<codegen::ASTORE, "astore">;
	using ALoadObjInstruction = NoOperandInstruction<codegen::ALOADOBJ, "aloadobj">;
	using AStoreObjInstruction = NoOperandInstruction<codegen::ASTOREOBJ, "astoreobj">;

	using AddInstruction = NoOperandInstruction<codegen::ADD, "add">;
	using SubInstruction = NoOperandInstruction<codegen::SUB, "sub">;
	using MulInstruction = NoOperandInstruction<codegen::MUL, "mul">;
	using DivInstruction = NoOperandInstruction<codegen::DIV, "div">;
	using AndInstruction = NoOperandInstruction<codegen::AND, "and">;
	using OrInstruction = NoOperandInstruction<codegen::OR, "or">;
	using XorInstruction = NoOperandInstruction<codegen::XOR, "xor">;
	using ShrInstruction = NoOperandInstruction<codegen::SHR, "shr">;
	using ShlInstruction = NoOperandInstruction<codegen::SHL, "shl">;

	using IncInstruction = NoOperandInstruction<codegen::INC, "inc">;
	using DecInstruction = NoOperandInstruction<codegen::DEC, "dec">;
	using NotInstruction = NoOperandInstruction<codegen::NOT, "not">;
	using NegInstruction = NoOperandInstruction<codegen::NEG, "neg">;

	using CmpInstruction = NoOperandInstruction<codegen::CMP, "cmp">;
	using CmpTrueInstruction = NoOperandInstruction<codegen::CMP_TRUE, "cmp_true">;
	using CmpFalseInstruction = NoOperandInstruction<codegen::CMP_FALSE, "cmp_true">;

	using PushEqInstruction = NoOperandInstruction<codegen::PUSHEQ, "pusheq">;
	using PushNeInstruction = NoOperandInstruction<codegen::PUSHNE, "pushne">;
	using PushLtInstruction = NoOperandInstruction<codegen::PUSHLT, "pushlt">;
	using PushGtInstruction = NoOperandInstruction<codegen::PUSHGT, "pushgt">;
	using PushLeInstruction = NoOperandInstruction<codegen::PUSHLE, "pushle">;
	using PushGeInstruction = NoOperandInstruction<codegen::PUSHGE, "pushge">;

	using RetInstruction = NoOperandInstruction<codegen::RET, "ret">;

	using DebugInstruction = NoOperandInstruction<codegen::DEBUG, "debug">;

	using HltInstruction = NoOperandInstruction<codegen::HLT, "hlt">;
}

#endif // JESUSASM_NO_OPERAND_INSTRUCTION_H

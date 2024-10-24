#ifndef JESUSASM_LABEL_OPERAND_H
#define JESUSASM_LABEL_OPERAND_H

#include "jasm/instruction/Instruction.h"

namespace jasm {
	class LabelOperand {
	public:
		LabelOperand(std::string_view name);

		std::string_view getName() const;

	private:
		std::string mName;
	};

	using LabelOperandPtr = std::unique_ptr<LabelOperand>;
}

#endif // JESUSASM_LABEL_OPERAND_H

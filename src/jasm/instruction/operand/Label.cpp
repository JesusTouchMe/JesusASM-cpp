#include "jasm/instruction/operand/Label.h"

namespace jasm {
	LabelOperand::LabelOperand(std::string_view name)
		: mName(name) {}

	std::string_view LabelOperand::getName() const {
		return mName;
	}
}
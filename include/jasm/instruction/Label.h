#ifndef JESUSASM_LABEL_VALUE_H
#define JESUSASM_LABEL_VALUE_H

#include "jasm/instruction/Value.h"

namespace jasm {
	class Label : public Value {
	public:
		Label(std::string_view name);

		virtual bool print(std::ostream& out) override;

	private:
		std::string mName;
	};

	using LabelPtr = std::unique_ptr<Label>;
}

#endif // JESUSASM_LABEL_VALUE_H

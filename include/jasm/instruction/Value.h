#ifndef JESUSASM_VALUE_H
#define JESUSASM_VALUE_H

#include <iostream>
#include <memory>
#include <set>

namespace jasm {
	class Value {
	public:
		virtual ~Value() { }

		virtual bool print(std::ostream& out) = 0;
	};

	using ValuePtr = std::unique_ptr<Value>;

	enum class Modifier {
		Public = 0x0001,
		Private = 0x0002,
	};

	std::string GetModifierName(Modifier modifier);

	std::string GetModifiersAsString(const std::set<Modifier>& modifiers);
}

#endif // JESUSASM_VALUE_H
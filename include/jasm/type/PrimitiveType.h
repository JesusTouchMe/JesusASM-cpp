#ifndef JESUSASM_PRIMITIVE_TYPE_H
#define JESUSASM_PRIMITIVE_TYPE_H

#include "jasm/type/Type.h"

#include <cstdint>

namespace jasm {
	class PrimitiveType : public Type {
	public:
		PrimitiveType(std::string_view name, std::string_view id, std::uint8_t primitiveId, int sizeInBits);

		bool isPrimitiveType() const override;

		static PrimitiveType* GetBool();
		static PrimitiveType* GetByte();
		static PrimitiveType* GetShort();
		static PrimitiveType* GetInt();
		static PrimitiveType* GetLong();

	private:
		std::uint8_t mPrimitiveId;
		int mSizeInBits;
	};
}

#endif // JESUSASM_PRIMITIVE_TYPE_H

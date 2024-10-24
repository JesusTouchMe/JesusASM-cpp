#include "jasm/type/PrimitiveType.h"

namespace jasm {
	PrimitiveType::PrimitiveType(std::string_view name, std::string_view id, std::uint8_t primitiveId, int sizeInBits)
		: Type(name, id)
		, mPrimitiveId(primitiveId)
		, mSizeInBits(sizeInBits) { }

	bool PrimitiveType::isPrimitiveType() const {
		return true;
	}

	PrimitiveType* PrimitiveType::GetBool() {
		return static_cast<PrimitiveType*>(Type::GetBoolType());
	}

	PrimitiveType* PrimitiveType::GetByte() {
		return static_cast<PrimitiveType*>(Type::GetByteType());
	}

	PrimitiveType* PrimitiveType::GetShort() {
		return static_cast<PrimitiveType*>(Type::GetShortType());
	}

	PrimitiveType* PrimitiveType::GetInt() {
		return static_cast<PrimitiveType*>(Type::GetIntType());
	}

	PrimitiveType* PrimitiveType::GetLong() {
		return static_cast<PrimitiveType*>(Type::GetLongType());
	}
}
// symbols.h
#ifndef SYMBOLS_H
#define SYMBOLS_H

#include <unordered_map>
#include <string>

enum class Symbol {
	SCATTER,
	BELL,
	CHERRY,
	LEMON,
	ORANGE,
	PLUM,
	SEVEN,
	WATERMELON
};

namespace std {
	template<>
	struct hash<Symbol> {
		size_t operator()(Symbol symbol) const {
			return static_cast<size_t>(symbol);
		}
	};
}

class Symbols {
public:
	Symbols();
	std::string to_string(Symbol symbol) const;
	Symbol from_string(const std::string& str) const;
private:
	std::unordered_map<Symbol, std::string> symbol_names;
};

#endif
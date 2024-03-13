#pragma once
#include <exception>
#include <stdexcept>

class AdaugareImposibilaException : public std::invalid_argument
{
public:
	AdaugareImposibilaException(const std::string& message)
		: std::invalid_argument(message) {
	}
};

class ProdusulNuExistaExcpetion : public std::invalid_argument
{
public:
	ProdusulNuExistaExcpetion(const std::string& message)
		: std::invalid_argument(message) {
	}
};
class DepasireDimensiuneException : public std::invalid_argument
{
public:
	DepasireDimensiuneException(const std::string& message)
		: std::invalid_argument(message) {
	}
};
class ExistadejaException : public std::invalid_argument
{
public:
	ExistadejaException(const std::string& message)
		: std::invalid_argument(message) {
	}
};


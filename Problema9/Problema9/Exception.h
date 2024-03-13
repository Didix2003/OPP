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
//class NuEsteInt :public std::invalid_argument
//{
//public: 
//	NuEsteInt(const std::string& message)
//		:std::invalid_argument(message)
//	{
//
//	}
//};
#pragma once

template <typename T>
class List;

template <class T>
class Node {
private:
	T info;
	Node<T>* prev;
	Node<T>* next;
	Node(T info, Node<T>* prev, Node<T>* next) : info(info), prev(prev), next(next) {}
public:
	Node(T info) : info(info) { prev = nullptr, next = nullptr; }
	friend class List<T>;
	T getData() const {
		return info;
	}
	Node<T>* getNext() const {
		return next;
	}
	Node<T>* getPrev() const {
		return prev;
	}
};

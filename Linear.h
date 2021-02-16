#pragma once
#include <iostream>
#include <vector>
#include "Parser.h"

struct Limitations;

#define N 5

struct Matrix {
private:
	struct Vector;
public:
	Matrix(size_t, size_t);

	Vector operator[](size_t);

	void print() const;

	void Transpose();

	~Matrix();
private:
	struct Vector {
		Vector(double*);
		double& operator[](size_t);
	private:
		double* vector;
	};

	double** matrix;
	size_t n, m;
};

struct Linear {
public:
	Linear(std::vector<double>&, Limitations&, std::vector<bool>&);

	void create_dual_program();
	Linear* get_dual_program();
private:
	static size_t vars_in_canonical(std::vector<double>&, Limitations&, std::vector<bool>&);

	Matrix A;
	std::vector<double> b;
	std::vector<double> objective_function;

	Linear* dual_program;
};
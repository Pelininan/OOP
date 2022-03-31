#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class complex {
private:
	float real;
	float imaginary;
public:
	complex(void);
	complex(float, float);
	~complex();
	float return_real(void);
	float return_imaginary(void);
};

#endif // COMPLEX_H_INCLUDED

class Complex
{
private:
    double re, im;  // representation: two doubles
public:
    Complex()    // default constructor
        : re{0}, im{0}
    {}

    Complex(double r)
        : re{r}, im{0}
    {}

    Complex(double r, double i)
        : re{r}, im{i}
    {}

    Complex(const Complex& z)   // copy constructor
        : re{z.re}, im{z.im}
    {}

    void real(double v) {
        re = v;
    }

    double real() const {
        return re;
    }

    void imag(double v) {
        im = v;
    }

    double imag() const {
        return im;
    }
    
    Complex& operator+=(Complex& z) {
        re += z.re;
        im += z.im;
        return *this;
    }

    Complex& operator-=(Complex& z) {
        re -= z.re;
        im -= z.im;
        return *this;
    }

};


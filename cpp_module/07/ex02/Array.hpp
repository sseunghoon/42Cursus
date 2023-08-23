#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
    private:
        T *array;
        unsigned int len;

    public:
        Array() : array(new T[0]), len(1) {}
        Array(unsigned int n) : array(new T[n]), len(n) {}

        Array(const Array& src) : array(NULL), len(0) {
            *this = src;
        }

        Array &operator=(const Array& src) {
            if (this != &src) {
                if (array)
                    delete [] array;
                len = src.size();
                array = new T[len];
                for (unsigned int i = 0; i < len; i++)
                    array[i] = src.array[i];
            }
            return *this;
        }

        ~Array() {
            if (array)
                delete [] array;
        }

        T& operator[] (unsigned int i) {
            if (i >= len)
                throw std::exception();
            return array[i];
        }

        unsigned int size() const {
            return len;
        }
};

#endif
